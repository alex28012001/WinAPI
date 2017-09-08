#include<windows.h>
#include"resource.h"
#include<string>
#include<fstream>
#include<iostream>
#include <locale>
#include <codecvt>
#include <map>
#include <vector>
#include<CommCtrl.h>
#include<commdlg.h>
#pragma comment(lib, "comctl32")
namespace alex
{
	std::wstring login = L"alex";
	std::wstring password = L"5555";
	bool authorization = false;
}
std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc2(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow)
{
	LoadLibrary(L"Riched20.dll");
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINDLG), NULL, DlgProc);
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

	static HWND hedit1, hedit2,hedit3, hbutlogin, hbutopen, hbutclear, hbut4, hbut5, hbutclear2, hbutpaste, hbut8, hlist, hedittemp, hbutdeletelist, hbutclearlist, hbutwrite, hstatic5,hcombobox,hbut12,hstatbar,hbut13;
	static int lengthlist = 0;
	std::wstring textLengthList;
	std::map<std::wstring, std::wstring> dict;
	RECT rect;
	static int pParts[3];
	static OPENFILENAME openFile;
	wchar_t szFileName[256];
	wchar_t szFileTitle[100];

	std::wstring text = L"Неизвестный текст";

		
	switch (iMsg)
	{
	case WM_COMMAND:
	{
					   if (LOWORD(wParam) == IDC_BUTTON1)
					   {
						   DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc2);
						   if (alex::authorization == true)
						   {
							   EnableWindow(hedit1, 1);
							   EnableWindow(hbutopen, 1);
							   EnableWindow(hbutclear, 1);
							   SendMessage(hstatbar, SB_SETTEXT, 0, LPARAM(alex::login.c_str()));
							  // SendMessage(hstatbar, SB_SETTEXT, 1, LPARAM(buf));
							   SendMessage(hstatbar, SB_SETTEXT, 1, LPARAM(L"Единство предмета речи — это тема"));
							  
						   }

					   }

					   if (LOWORD(wParam) == IDC_BUTTON2)
					   {
						   SetWindowText(hedit1, L"Единство предмета речи — это тема высказывания. Тема — это смысловое ядро текста, конденсированное и обобщённое содержание текста. Понятие «содержание высказывания» связано с категорией ");				  
					   }

					   if (LOWORD(wParam) == IDC_BUTTON3)
					   {
						   SendMessage(hedit1, EM_SETSEL, 0, -1);
						   SendMessage(hedit1, WM_CLEAR, 0, 0);
					   }

					   if (LOWORD(wParam) == IDC_BUTTON6)
					   {
						   SendMessage(hedit1, WM_COPY, 0, -1);
						   SendMessage(hedit2, WM_PASTE, 0, 0);
					   }

					   if (LOWORD(wParam) == IDC_BUTTON7)
					   {
						   wchar_t buf[255];
						   SendMessage(hedit1, WM_GETTEXT, 255, (LPARAM)buf);
						   SendMessage(hedit2, WM_SETTEXT, 0, (LPARAM)buf);
					   }


					   if (LOWORD(wParam) == IDC_BUTTON4)
					   {
						   SendMessage(hedit2, EM_SETSEL, 0, -1);
						   SendMessage(hedit2, WM_CLEAR, 0, 0);
					   }


					   if (LOWORD(wParam) == IDC_BUTTON5)
					   {
						   std::wofstream file("new_text.txt");
						   if (!file.is_open())
							   MessageBox(hwnd, L"Файл не найден", L"Информация", MB_OK);
						   file.imbue(loc);
						   wchar_t buf[255];
						   SendMessage(hedit2, WM_GETTEXT, 255, (LPARAM)buf);
						   SendMessage(hedit2, WM_SETTEXT, 0, (LPARAM)buf);

						   file << buf;
						   file.close();
					   }


					   if (LOWORD(wParam) == IDC_BUTTON8)
					   {
						   ++lengthlist;
						   wchar_t buf[20];
						   int count_str = SendMessage(hlist, LB_GETCOUNT, 0, 0);
						   
							   SendMessage(hedit2, WM_COPY, 0, 0);
							   SendMessage(hedittemp, WM_PASTE, 0, 0);
							   SendMessage(hedittemp, WM_GETTEXT, 20, (LPARAM)buf);
							   SendMessage(hlist, LB_ADDSTRING, 0, (LPARAM)buf);
							   SendMessage(hedittemp, EM_SETSEL, 0, -1);
							   SendMessage(hedittemp, WM_CLEAR, 0, 0);
							   textLengthList = std::to_wstring(lengthlist);
							   SetWindowText(hstatic5, textLengthList.c_str());
							   
					   }



					   if (LOWORD(wParam) == IDC_BUTTON9)
					   {
						 --lengthlist;
						int index = SendMessage(hlist, LB_GETCURSEL, 0, 0);
						SendMessage(hlist, LB_DELETESTRING,index, 0);
						textLengthList = std::to_wstring(lengthlist);
						SetWindowText(hstatic5, textLengthList.c_str());
					   }




					   if (LOWORD(wParam) == IDC_BUTTON10)
					   {
						   SendMessage(hlist, LB_RESETCONTENT, 0, 0);
					   }




					   if (LOWORD(wParam) == IDC_BUTTON11)
					   {

						   std::wofstream file("list.txt");
						   if (!file.is_open())
							   MessageBox(hwnd, L"Файл не найден", L"Информация", MB_OK);
						   file.imbue(loc);
						   
						   lengthlist = SendMessage(hlist, LB_GETCOUNT, 0, 0);
						   wchar_t buf[200];
						   for (int i = 0; i < lengthlist; ++i)
						   {	
								SendMessage(hlist, LB_GETTEXT, i, (LPARAM)buf);
								file << buf<<"\n";
						   }
							
						file.close();
					   }

					   if (LOWORD(wParam) == IDC_BUTTON12)
					   {
							  std::wstring word;
							  std::wstring buf;
							  SendMessage(hedit3, WM_GETTEXT, 255, (LPARAM)buf.c_str());
							
								  int index = SendMessage(hlist, LB_GETCURSEL, 0, 0);
								  SendMessage(hlist, LB_GETTEXT, index, (LPARAM)word.c_str());
								  dict.insert(std::pair<std::wstring, std::wstring>(word.c_str(), buf.c_str()));				   
						  
					   }

					   if (LOWORD(wParam) == IDC_BUTTON13)
					   {
						   setlocale(0, "");
						   std::wofstream file("dict.txt");
						   if (!file.is_open())
							   MessageBox(hwnd, L"Файл не найден", L"Информация", MB_OK);
						   file.imbue(loc);

						   for (auto it : dict)
						   {
							   file << it.first.c_str() << "  " << it.second.c_str() << "\n";
						   }


						   file.close();
					   }
					   

	}break;

	case WM_INITDIALOG:
	{

						  hedit1 = GetDlgItem(hwnd, IDC_EDIT1);
						  EnableWindow(hedit1, 0);
						  hedit2 = GetDlgItem(hwnd, IDC_EDIT3);
						  hbutlogin = GetDlgItem(hwnd, IDC_BUTTON1);
						  hbutopen = GetDlgItem(hwnd, IDC_BUTTON2);
						  EnableWindow(hbutopen, 0);
						  hbutclear = GetDlgItem(hwnd, IDC_BUTTON3);
						  EnableWindow(hbutclear, 0);
						  hbut4 = GetDlgItem(hwnd, IDC_BUTTON6);
						  hbut5 = GetDlgItem(hwnd, IDC_BUTTON7);
						  hbutclear2 = GetDlgItem(hwnd, IDC_BUTTON4);
						  hbutpaste = GetDlgItem(hwnd, IDC_BUTTON5);
						  hbut8 = GetDlgItem(hwnd, IDC_BUTTON8);
						  hlist = GetDlgItem(hwnd, IDC_LIST1);
						  hedittemp = GetDlgItem(hwnd, IDC_EDIT5);
						  hbutdeletelist = GetDlgItem(hwnd, IDC_BUTTON9);
						  hbutclearlist = GetDlgItem(hwnd, IDC_BUTTON10);
						  hbutwrite = GetDlgItem(hwnd, IDC_BUTTON11);
						  hstatic5 = GetDlgItem(hwnd, IDC_STATIC5);
						  hcombobox = GetDlgItem(hwnd, IDC_COMBO1); 
						  SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"Значение");
						  SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"Перевод");
						  SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"Синоним");
						  SendMessage(hcombobox, CB_ADDSTRING, 0, (LPARAM)L"Антоним");
						  hedit3 = GetDlgItem(hwnd, IDC_EDIT2);
						  hbut12 = GetDlgItem(hwnd, IDC_BUTTON12);
						  hbut13 = GetDlgItem(hwnd, IDC_BUTTON13);
						  
						  hstatbar = CreateWindowEx(NULL, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 5, 5, 100, 100, hwnd, NULL, GetModuleHandle(NULL), NULL);
						  SendMessage(hstatbar, SB_SIMPLE, false, 0);
						  pParts[0] = 200;
						  pParts[1] = -1;
						  SendMessage(hstatbar, SB_SETPARTS, 2, (LPARAM)pParts);
						  SendMessage(hstatbar, SB_SETTEXT, 0, LPARAM(L"Неизвестный пользаватель"));
						  SendMessage(hstatbar, SB_SETTEXT, 1, LPARAM(L"Неизвестный текст"));
						 
							
						
						  
	}break;



	case WM_CLOSE:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}

BOOL CALLBACK DlgProc2(HWND hwnd, UINT iMsg2, WPARAM wParam, LPARAM lParam)
{
	static HWND hedit1, hedit2, hbut1, hbutcancel;
	switch (iMsg2)
	{

	case WM_COMMAND:
	{
					   if (LOWORD(wParam) == IDC_BUTTONCANCEL)
					   {
						   SendMessage(hwnd, WM_CLOSE, 0, 0);
					   }

					   if (LOWORD(wParam) == IDC_BUTTONVOI)
					   {

						   wchar_t buf[20];
						   wchar_t buf2[10];
						   GetWindowText(hedit1, buf, 20);
						   GetWindowText(hedit2, buf2, 10);

						   if (std::wstring(buf) != L"" || std::wstring(buf2) != L"")
						   {
							   if (std::wstring(buf) == alex::login && std::wstring(buf2) == alex::password)
							   {
								   alex::authorization = true;
								   SendMessage(hwnd, WM_CLOSE, 0, 0);
							   }
							   else
								   MessageBox(hwnd, L"Данные введены неверно!", L"Информация", MB_OK);
						   }
						   else
						   {
							   MessageBox(hwnd, L"Данные введены неверно!", L"Информация", MB_OK);
						   }
					   }



	}return true;

	case WM_INITDIALOG:
	{
						  hedit1 = GetDlgItem(hwnd, IDC_EDIT4);
						  hedit2 = GetDlgItem(hwnd, IDC_EDIT5);
						  hbut1 = GetDlgItem(hwnd, IDC_BUTTONVOI);
						  hbutcancel = GetDlgItem(hwnd, IDC_BUTTONCANCEL);

	}return true;

	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return true;

	}
	return false;
}
