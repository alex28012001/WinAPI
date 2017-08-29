#include<windows.h>
#include"resource.h"
#include<CommCtrl.h>
#include<string>
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
	
	static HWND hbar,hslider, hstatbar;
	RECT rect;
	static int pParts[3];
	switch (iMsg)
	{
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			SetTimer(hwnd, ID_TIMER, 5, NULL);
		}
	}break;

	case WM_INITDIALOG:
	{
		hslider = GetDlgItem(hwnd, IDC_SLIDER1);
		hbar = GetDlgItem(hwnd, IDC_PROGRESS2);
		hstatbar = CreateWindowEx(NULL, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 5, 5, 100, 100, hwnd, NULL, GetModuleHandle(NULL), NULL);
		SendMessage(hbar, PBM_SETRANGE, 0, MAKELPARAM(0, 200));
		SendMessage(hbar, PBM_SETSTEP, 1, 0);
		SendMessage(hslider, TBM_SETRANGE, 0, MAKELPARAM(0, 255));
		SendMessage(hslider, TBM_SETPOS, true, 50);
		SendMessage(hslider, TBM_SETLINESIZE, 0,10);
		SendMessage(hstatbar, SB_SIMPLE, false, 0);
		//SendMessage(hstatbar, SB_SETTEXT, 255, LPARAM(L"Lesha"));
		MoveWindow(hstatbar, 0, rect.bottom - 10, rect.right, 10, TRUE);
		pParts[0] = 50;
		pParts[1] = 100;
		pParts[2] = -1;
		SendMessage(hstatbar, SB_SETPARTS, 3, (LPARAM)pParts);
	}

	return true;
	

	case WM_TIMER:
	{
		SendMessage(hbar, PBM_STEPIT ,0,0 );
		//SendMessage(hbar, PBM_DELTAPOS, 1,0 );
	}
	return true;

	case WM_HSCROLL:
	{
		 int pos = SendMessage(hslider, TBM_GETPOS , 0, 0);
		 SendMessage(hbar, PBM_SETBKCOLOR, 0, (LPARAM)RGB(255, 255, 230));
		 SendMessage(hbar, PBM_SETBARCOLOR, 0, (LPARAM)RGB(pos, 168, 19));

		  
	}return true;


	case WM_CLOSE:
		KillTimer(hwnd, ID_TIMER);
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
