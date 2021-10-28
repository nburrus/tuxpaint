#include <windows.h>

int win32_trash(char *path);
int win32_trash(char *path)
{
  SHFILEOPSTRUCT op;
  
  op.wFunc = FO_DELETE;
  op.pFrom = path;
  op.fFlags = FOF_SILENT|FOF_ALLOWUNDO;
  
  return SHFileOperationA(&op);
}
