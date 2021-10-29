#include <windows.h>
#include <string.h>
#include <stdlib.h>

int win32_trash(char *path);
int win32_trash(char *path)
{
  SHFILEOPSTRUCT op;
  int ret;

  op.wFunc = FO_DELETE;
  op.pFrom = path;
  op.fFlags = FOF_SILENT|FOF_ALLOWUNDO;
  ret = SHFileOperationA(&op);

  return ret;
}
