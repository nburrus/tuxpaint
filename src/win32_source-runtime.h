/* Locate bundled dependency data independently of the current directory. */
#if defined(_WIN32) && defined(TUXPAINT_SOURCE_RUNTIME)
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static void source_runtime_init(void)
{
  wchar_t wide[32768];
  char base[98304], value[98560];
  DWORD length = GetModuleFileNameW(NULL, wide, 32768);
  if (!length || length >= 32768) return;
  if (!WideCharToMultiByte(CP_UTF8, 0, wide, -1, base, sizeof(base), NULL, NULL)) return;
  char *slash = strrchr(base, '\\');
  if (!slash) return;
  *slash = 0;
  snprintf(value, sizeof(value), "%s/etc/fonts", base);
  _putenv_s("FONTCONFIG_PATH", value);
  snprintf(value, sizeof(value), "%s/etc/fonts/fonts.conf", base);
  _putenv_s("FONTCONFIG_FILE", value);
  snprintf(value, sizeof(value), "%s/share/libthai", base);
  _putenv_s("LIBTHAI_DICTDIR", value);
  snprintf(value, sizeof(value), "%s/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache", base);
  _putenv_s("GDK_PIXBUF_MODULE_FILE", value);
}
#endif
