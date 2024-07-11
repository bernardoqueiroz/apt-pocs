#include <windows.h>
#include <cpl.h>

LONG CALLBACK CPlApplet(HWND hwndCPL, UINT msg, LPARAM lParam1, LPARAM lParam2) {
    switch (msg) {
        case CPL_INIT:
            return TRUE;

        case CPL_GETCOUNT:
            return 1;

        case CPL_INQUIRE:
            {
                LPCPLINFO info = (LPCPLINFO)lParam2;
                info->idIcon = 101; // ID do ícone
                info->idName = 1; // ID do nome
                info->idInfo = 2; // ID das informações
                info->lData = 0;
            }
            break;

        case CPL_DBLCLK:
            MessageBox(hwndCPL, "Hello, World!", "Example CPL", MB_OK);
            break;

        case CPL_STOP:
        case CPL_EXIT:
            break;

        default:
            break;
    }
    return 0;
}
