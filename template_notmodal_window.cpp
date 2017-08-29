#include<windows.h>
#include"resource.h"
#include<string>
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hWnd, 1);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	wchar_t buf[20];
	static HWND hBUTOK;
	switch (iMsg)
	{
	case WM_COMMAND:
	{
		

	}break;
	
	case WM_INITDIALOG:
		hBUTOK = GetDlgItem(hwnd,IDOK);
		break;

	


	case WM_CLOSE:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
	return true;
	}
	return false;
}
