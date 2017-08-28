#include<windows.h>
#include<iostream>
#include"resource.h"
#include<string>
#include<map>
#include<CommCtrl.h>
#pragma comment(lib, "comctl32")
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
#define IDC_STATUSBAR 100
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
	static HWND hcombobox, hbutshow, hstatic1 , hstatic2, hstatbar;
	static HMENU hMenu;


	switch (iMsg)
	{
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			std::map <int, std::pair<std::wstring, std::wstring> > mapa = { { 2, { L"Оценка: 7", L"ЭТО ЯЗЫК ПРОГРАММИРОВАНИЯ СИ!ДЛЯ ПРОГРАМММИСТОВ"}},
			{1, {L"Оценка: 8", L"ЭТО ЯЗЫК ПРОГРАММИРОВАНИЯ С++!БЛА БЛА БЛА"}},
			{3, { L"Оценка: 9", L"ЭТО ЯЗЫК ПРОГРАММИРОВАНИЯ PYTHONE!"}},
			{0, { L"Оценка: 10", L"ЭТО ЯЗЫК ПРОГРАММИРОВАНИЯ C#!" }} };
			
			int index = SendMessage(hcombobox, CB_GETCURSEL, 0, 0);
			
				SetWindowText(hstatic1, mapa[index].first.c_str());
				SetWindowText(hstatic2, mapa[index].second.c_str());
				}		
			
	}break;

	

	case WM_INITDIALOG:
		hcombobox = GetDlgItem(hwnd, IDC_COMBO1);
		hbutshow = GetDlgItem(hwnd, IDC_BUTTON1);
		hstatic1 = GetDlgItem(hwnd, IDC_STATIC1);
		hstatic2 = GetDlgItem(hwnd, IDC_STATIC2);
		SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"Cpp");
		SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"C++");
		SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"Pythone");
		SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"C#");
		hstatbar = CreateWindowEx(NULL, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 5, 5, 100, 100, hwnd, NULL, GetModuleHandle(NULL), NULL);
		SendMessage(hstatbar, SB_SIMPLE, false, 0);
	//	SendMessage(hstatbar, SB_SIMPLE, false, (LPARAM)(parts);
		hMenu = GetMenu(hwnd);
		EnableMenuItem(hMenu, ID_40006, MF_GRAYED);
		
		
	break;

	
	
	

	case WM_CLOSE:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
