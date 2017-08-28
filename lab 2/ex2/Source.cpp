#include <windows.h>
#include <tchar.h>
#include<ctime>
#include<string>
#define ID_BUTTON 100
int Width = 700;
int Heigth = 500;


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	LPWSTR szClassName = L"Window";
	LPWSTR szTitleName = L"Window";

	WNDCLASSEX wnd;
	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(hInstance, IDC_ARROW);
	wnd.hCursor = LoadCursor(hInstance, IDI_APPLICATION);
	wnd.hbrBackground = CreateSolidBrush(RGB(42, 200, 34));
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = _TEXT("Window");
	wnd.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wnd)) 
		return false;
	


	HWND hWnd = CreateWindowEx(WS_EX_TOPMOST, _TEXT("Window"), TEXT("Hello"), WS_OVERLAPPEDWINDOW,50, 50, Width, Heigth,NULL, NULL, hInstance, NULL);
		
		

	if (!hWnd) 
		return false;




	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);





	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	srand(time(NULL));
	HWND hbut_play;
	switch (iMsg)
	{
	case WM_CREATE:
	{
					  hbut_play = CreateWindowEx(NULL, L"BUTTON", L"PLAY", WS_CHILD | WS_VISIBLE, 250, 170, 190, 50, hWnd, (HMENU)ID_BUTTON, GetModuleHandle(NULL), NULL);
	}break;

	case WM_COMMAND:
	{
					   if (LOWORD(wParam) == ID_BUTTON)
					   {
						   bool game = true;
						   int min = 0;
						   int max = 101;
						   int attempts = 1;
						   int x = 0 + rand() % 100;
						   std::wstring str = L"Загадайте чило от 0 до 100\nВаше число : " + std::to_wstring(x) + L"?";
						   if (MessageBox(hWnd, str.c_str(), L"Информация", MB_YESNO) == IDYES)
						   {
							   std::wstring str = L"Игра окончена ваше задуманное число: " + std::to_wstring(x) + L"\nСделано попыток: " + std::to_wstring(attempts);
							   MessageBox(hWnd, str.c_str(), L"Информация", MB_OK);
						   }
						   else
						   {
							   while (game)
							   {
								   if (MessageBox(hWnd, L"Ваше число больше?", L"Информация", MB_YESNO) == IDYES)
								   {
									   ++attempts;
									   min = x;
									   x = (min + max)/2;
									   std::wstring str = L"Ваше число: " + std::to_wstring(x) + L"?";
									   if (MessageBox(hWnd, str.c_str(), L"Информация", MB_YESNO) == IDYES)
									   {
										   std::wstring str = L"Игра окончена ваше задуманное число: " + std::to_wstring(x) + L"\nСделано попыток: " + std::to_wstring(attempts);
										   MessageBox(hWnd, str.c_str(), L"Информация", MB_OK);
										   game = false;
									   }
								   }
								   else
								   {
									   ++attempts;
									   max = x;
									   x = (min + max) / 2;
									   std::wstring str = L"Ваше число: " + std::to_wstring(x) + L"?";
									   if (MessageBox(hWnd, str.c_str(), L"Информация", MB_YESNO) == IDYES)
									   {
										   std::wstring str = L"Игра окончена ваше задуманное число: " + std::to_wstring(x) + L"\nСделано попыток: " + std::to_wstring(attempts);
										   MessageBox(hWnd, str.c_str(), L"Информация", MB_OK);
										   game = false;
									   }
								   }
							   }
						   }
					   }
					 
						  
	}break;


	case WM_DESTROY:
	{
					   PostQuitMessage(0);
	}break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);

		return 0;

	}
}
