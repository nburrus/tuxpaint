#!/usr/bin/env python3
"""Collect native Windows dependencies, preferring the installed local profile.

Only generated DLLs inside the specified distribution are replaced/pruned.
EXEs, user images, translations and the library installation are not removed.
"""
import argparse
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess

p = argparse.ArgumentParser()
p.add_argument('--dest', required=True)
p.add_argument('--prefix', required=True)
p.add_argument('--mingw', required=True)
p.add_argument('--config', required=True)
a = p.parse_args()
dest, prefix, mingw, config = (Path(x).resolve() for x in (a.dest, a.prefix, a.mingw, a.config))
if not (dest / 'tuxpaint.exe').is_file() or not (dest / 'data').is_dir():
    p.error('Destination must be an installed Tux Paint distribution')
if dest == prefix or dest in prefix.parents or prefix in dest.parents or dest == mingw or dest in mingw.parents or mingw in dest.parents:
    p.error('Distribution and library installation must be separate')
if not config.is_file():
    p.error('Build the lightweight configuration tool first')
keep = {'pixbufloader_svg.dll'}
loader_rel = Path('lib/gdk-pixbuf-2.0/2.10.0/loaders')
loader_dest = dest / loader_rel
loader_dest.mkdir(parents=True, exist_ok=True)
shutil.copy2(config, dest / 'tuxpaint-config.exe')
for name in sorted(keep):
    src = next((root / loader_rel / name for root in (prefix,)
                if (root / loader_rel / name).is_file()), None)
    if src is None:
        raise SystemExit('Missing image loader: ' + name)
    shutil.copy2(src, loader_dest / name)

shutil.copytree(prefix / 'etc/fonts', dest / 'etc/fonts', dirs_exist_ok=True)
shutil.copytree(prefix / 'share/libthai', dest / 'share/libthai', dirs_exist_ok=True)
cache_target = dest / 'lib/gdk-pixbuf-2.0/2.10.0/loaders.cache'
cache_target.parent.mkdir(parents=True, exist_ok=True)
cache_source = prefix / 'lib/gdk-pixbuf-2.0/2.10.0/loaders.cache'
cache_text = cache_source.read_text(encoding='utf-8').replace(prefix.as_posix() + '/', '')
cache_target.write_text(cache_text)
objdump = str(mingw / 'bin/objdump.exe')
strip = str(mingw / 'bin/strip.exe')
system = Path(os.environ.get('WINDIR', 'C:/Windows')) / 'System32'
# Scan every executable, Magic tool and selected run-time image loader.
queue = list(dest.rglob('*.exe')) + list((dest / 'plugins').glob('*.dll'))
queue += [loader_dest / name for name in sorted(keep)]
scanned = set()
required = {}
imports = []
while queue:
    file = queue.pop()
    if file in scanned:
        continue
    scanned.add(file)
    result = subprocess.run([objdump, '-p', str(file)], check=True,
                            capture_output=True, text=True)
    if 'pei-x86-64' not in result.stdout:
        raise SystemExit('Non-MINGW64 binary: ' + str(file))
    for name in re.findall(r'DLL Name:\s*([^\r\n]+)', result.stdout):
        name = name.strip()
        if Path(name).name != name or '/' in name or '\\' in name:
            raise SystemExit('Invalid DLL import name: ' + name)
        imports.append((str(file), name))
        if name.lower() == 'msys-2.0.dll':
            raise SystemExit('MSYS runtime dependency in native Windows build')
        key = name.lower()
        if key in required:
            continue
        source = next((root / 'bin' / name for root in (prefix,)
                       if (root / 'bin' / name).is_file()), None)
        if source is None:
            if (system / name).is_file() or key.startswith(('api-ms-', 'ext-ms-')):
                continue
            raise SystemExit('Unresolved DLL: ' + name + ' (required by ' + str(file) + ')')
        required[key] = source
        queue.append(source)

# All dependencies have been resolved before pruning old generated files.
for source in required.values():
    shutil.copy2(source, dest / source.name)
for file in dest.glob('*.dll'):
    if file.name.lower() not in required:
        if file.resolve().parent != dest:
            raise SystemExit('Refusing to prune a DLL outside the distribution')
        file.unlink()
for file in loader_dest.glob('*.dll'):
    if file.name.lower() not in keep:
        if file.resolve().parent != loader_dest.resolve():
            raise SystemExit('Refusing to prune a loader outside the distribution')
        file.unlink()
for file in list(dest.glob('*.exe')) + list(dest.glob('*.dll')) + list(loader_dest.glob('*.dll')) + list((dest / 'plugins').glob('*.dll')):
    subprocess.run([strip, '-s', str(file)], check=True)

cache = dest / 'etc/gtk-2.0/gdk-pixbuf.loaders'
if cache.exists():
    blocks = re.split(r'\n\s*\n', cache.read_text(encoding='utf-8'))
    selected = []
    for block in blocks:
        match = re.search(r'^"([^"\n]+\.dll)"', block, re.M)
        if not match or PurePosixPath(match.group(1).replace('\\', '/')).name.lower() in keep:
            selected.append(block)
    cache.write_text('\n\n'.join(selected) + '\n', encoding='utf-8')
licenses = prefix / 'share/tuxpaint-source-build/licenses'
if licenses.is_dir():
    shutil.copytree(licenses, dest / 'docs/lightweight-library-licenses', dirs_exist_ok=True)
record = {'profile': 1, 'root_dll_count': len(required),
          'root_dll_bytes': sum((dest / src.name).stat().st_size for src in required.values()),
          'dlls': sorted(src.name for src in required.values()), 'missing_imports': []}
(dest / 'docs/lightweight-build.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')
print('Lightweight distribution: ' + str(len(required)) + ' dependency DLLs; no unresolved imports')
