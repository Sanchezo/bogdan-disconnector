#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _cdecl _tmain(
    int argc,
    TCHAR* argv[])
{
    if (RegisterHotKey(
        NULL,
        1,
        MOD_ALT | MOD_NOREPEAT,
        0x42))  //0x42 is 'b'
    {
        _tprintf(_T("Everything ready. Press alt+b to disconnect your internet connection for 5 sec\n"));
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {   
            system("ipconfig /release");
            Sleep(5000);
                system("ipconfig /renew");
        }
    }

    return 0;
}
