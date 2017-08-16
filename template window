#include <windows.h>
#include <tchar.h>
#include"resource.h"

int Width = 200;
int Heigth = 100;
int Close_timer = 1;
int Color_timer = 2;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	LPWSTR szClassName = L"Window";
	LPWSTR szTitleName = L"Window";

	WNDCLASSEX wnd;
	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON2));
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wnd.hbrBackground = CreateSolidBrush(RGB(42, 200, 34));//(HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = _TEXT("Window");
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS ;

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	
	HWND hWnd = CreateWindowEx(WS_EX_TOPMOST, _TEXT("Window"), TEXT("Hello"), WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX,
		50,50,Width,Heigth,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM IParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
	{
		SetTimer(hWnd, Close_timer, 1000, NULL);
		SetTimer(hWnd, Color_timer, 100, NULL);
	}break;
		

	case WM_TIMER:
	{
		
		if (wParam == Color_timer)
			{
				SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand()%25, rand() % 256, rand() % 256)));
				InvalidateRect(hWnd, NULL, true);
			}
		else if (wParam == Close_timer)
		{
			if (MessageBox(NULL, L"Вы действительно хотите завершить работу приложения?", L"Информация", MB_YESNO) == IDYES)
				{
					DestroyWindow(0);
					PostQuitMessage(0);
				}
		}

					
	}break;
		


	case WM_CLOSE:
	{
		if (MessageBox(NULL, L"Вы действительно хотите завершить работу приложения?", L"Информация", MB_YESNO) == IDYES) {
			DestroyWindow(0);
			PostQuitMessage(0);
			}
	}break;
		
	case WM_DESTROY:
	{
		KillTimer(hWnd, Close_timer);
		KillTimer(hWnd, Color_timer);
		PostQuitMessage(0);
	}break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, IParam);
		
		return 0;
	}
}
