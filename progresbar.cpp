#include<windows.h>
#include"resource.h"
#include<CommCtrl.h>
#pragma comment(lib, "comctl32")
#define ID_TIMER 100
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hWnd, 1);

	INITCOMMONCONTROLSEX win;
	win.dwSize = sizeof(win);
	win.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&win);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (msg.message == WM_CHAR)
		{
			SendMessage(hWnd, msg.message, msg.wParam, msg.lParam);
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hbar;
	switch (iMsg)
	{
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			SetTimer(hwnd, ID_TIMER, 10, NULL);
		}
	}break;

	case WM_INITDIALOG:
	{
		hbar = GetDlgItem(hwnd, IDC_PROGRESS2);
		//hEdit = CreateWindowEx(NULL, L"EDIT", L"", WS_CHILD | WS_VISIBLE, 20, 20, 300, 20, hwnd, (HMENU)ID_EDIT, hInst, NULL);
		SendMessage(hbar, PBM_SETBKCOLOR, 0, (LPARAM)RGB(255, 255, 230));
		SendMessage(hbar, PBM_SETBARCOLOR, 0, (LPARAM)RGB(242, 168, 19));
		SendMessage(hbar, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendMessage(hbar, PBM_SETSTEP, 1, 0);
	}
	return true;
	case WM_TIMER:
	{
		SendMessage(hbar, PBM_STEPIT ,0,0 );
		//SendMessage(hbar, PBM_DELTAPOS, 1,0 );
	}
	return true;


	case WM_CLOSE:
		KillTimer(hwnd, ID_TIMER);
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
