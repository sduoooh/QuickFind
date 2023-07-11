#include <tchar.h>
#include <iomanip>
#include <windows.h>
#include "QuickFind.h"

void spy()
{
    DWORD cbBytes;
    char notify[1024];
    int count = 0; 

    std::string str = spypath;
    std::wstring wstr(str.begin(), str.end());
    TCHAR* dir = (_TCHAR*)(&wstr[0]);

    HANDLE dirHandle = CreateFile(dir,
        GENERIC_READ | GENERIC_WRITE | FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS,
        NULL);

    if (dirHandle == INVALID_HANDLE_VALUE) 
    {
        std::cout << "error" + GetLastError() << std::endl;
    }

    memset(notify, 0, strlen(notify));
    FILE_NOTIFY_INFORMATION* pnotify = (FILE_NOTIFY_INFORMATION*)notify;

    while (true)
    {
        if (ReadDirectoryChangesW(dirHandle, &notify, 1024, true,
            FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_SIZE,
            &cbBytes, NULL, NULL))
        {
            isupdate = true;
            generater.notify_one();
        }
    }
}
