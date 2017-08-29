#include<windows.h>
#include"resource.h"
#include<string>
#include<CommCtrl.h>
#include<commdlg.h>
#pragma comment(lib, "comctl32")
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow)
{
	LoadLibrary(L"Riched20.dll");
	HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hWnd, 1);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(hWnd, hAccel, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	wchar_t buf[20];
	static HWND hrich,hstatbar;
	static HMENU hMenu;
	RECT rect;
	static int pParts[3];
	static OPENFILENAME openFile;
	wchar_t szFileName[256];
	wchar_t szFileTitle[100];

	ZeroMemory(&openFile, sizeof(OPENFILENAME));
	openFile.lStructSize = sizeof(OPENFILENAME);
	openFile.hInstance = GetModuleHandle(NULL);
	openFile.hwndOwner = hwnd;
	openFile.lpstrCustomFilter = L"All Files(*.txt)\0*.txt\0\0";
	openFile.nMaxFile = 256;
	openFile.nMaxFileTitle = 30;
	openFile.lpstrDefExt = L"txt";
	openFile.lpstrFileTitle = szFileTitle;
	openFile.lpstrFile = szFileName;


	switch (iMsg)
	{


	case WM_COMMAND:
		{
			if (LOWORD(wParam) == ID_INFORMATION)
			{
				MessageBox(hwnd, L"Это создал я!",L"Информация", MB_OK);
			}

			if (LOWORD(wParam) == ID_CUT)
			{
				SendMessage(hrich, WM_CUT, 0, 0);
			}

			if (LOWORD(wParam) == ID_COPY)
			{
				SendMessage(hrich, WM_COPY, 0, 0);
			}

			if (LOWORD(wParam) == ID_PASTE)
			{
				SendMessage(hrich, WM_PASTE, 0, 0);
			}

			if (LOWORD(wParam) == ID_DELETE)
			{
				SetWindowText(hrich, NULL);
			}

			if (LOWORD(wParam) == ID_EXIT)
			{
				SendMessage(hwnd,WM_CLOSE,0,0);
			}

			if (LOWORD(wParam) == ID_OPEN)
			{
				GetOpenFileName(&openFile);
			}

			

			
		}break;

	case WM_INITDIALOG:
		GetClientRect(hwnd, &rect);
		hrich = GetDlgItem(hwnd, IDC_EDIT1);
		hMenu = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hwnd, hMenu);
		EnableMenuItem(hMenu, ID_SRIFT, MF_BYCOMMAND | MF_GRAYED);
		hstatbar = CreateWindowEx(NULL, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 5, 5, 100, 100, hwnd, NULL, GetModuleHandle(NULL), NULL);
		SendMessage(hstatbar, SB_SIMPLE, false, 0);
		SendMessage(hstatbar, SB_SETTEXT, 2, LPARAM(L"Lesha"));
		MoveWindow(hstatbar, 0, rect.bottom - 10, rect.right, 10, TRUE);
		pParts[0] = 150;
		pParts[1] = 300;
		pParts[2] = -1;
		SendMessage(hstatbar, SB_SETPARTS, 3, (LPARAM)pParts);
		CheckMenuItem(hMenu, ID_STATUSBAR, MF_BYCOMMAND | MF_CHECKED);
	break;

	

	case WM_SIZE:
	{
		GetClientRect(hwnd, &rect);
		MoveWindow(hrich,0,0,rect.right,rect.bottom,true);
		MoveWindow(hstatbar, 0, rect.bottom - 10, rect.right, 10, TRUE);
	}break;

	




	case WM_CLOSE:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
