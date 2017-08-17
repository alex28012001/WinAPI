#include <windows.h>
#include <tchar.h>
#include"resource.h"

int Width = 300;
int Heigth = 200;
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (iMsg)
	{

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		SetTextColor(hdc, RGB(247, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, L"Lesha", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		EndPaint(hWnd, &ps);
	}break;



	case WM_KEYDOWN:
	{
			case VK_RETURN:
				{
					/*for (int i = 0; i<100; ++i)  //
					{
						for (int i = 0; i < 1000; ++i)
						{
							MoveWindow(hWnd, i , 0, Width, Heigth, true);
							ShowWindow(hWnd, 1);
							UpdateWindow(hWnd);
						}
					}
					InvalidateRect(hWnd, NULL, true);*/
					SystemParametersInfo(SPI_GETWORKAREA, 0,&rect, 0);
					MoveWindow(hWnd, 600, 700, rect.right / 2, rect.bottom / 2, true);
				}break;

			case VK_ESCAPE:
			{
				MoveWindow(hWnd, 0, 0,Width, Heigth, true);
				ShowWindow(hWnd, 0);
				UpdateWindow(hWnd);
			}break;	
	}break;
		
		
	
	
	case WM_SYSKEYDOWN:
	{
		switch (wParam)
		{
			case VK_DOWN:
			{
				ShowWindow(hWnd,SW_SHOWMINIMIZED);
			}break;

			case VK_UP:
			{
				ShowWindow(hWnd, SW_SHOWMAXIMIZED);
			}break;

			case VK_LEFT:
			{
				ShowWindow(hWnd, SW_NORMAL);
			}break;

			case VK_RIGHT:
			{
				ShowWindow(hWnd, SW_NORMAL);
			}break;
			
			case VK_F4:
			{
				PostMessage(hWnd, WM_CLOSE, wParam, lParam);
			}break;
		}

	case WM_CHAR:
	{
		if (wParam == 't')
			SetWindowText(hWnd, L"dsguhghsgdjkhdhsgsgg");
	}


	}break;


	case WM_LBUTTONDOWN:
	{
		int x, y;
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hWnd, x, y, 300, 300, true);
	}break;
		 

	case WM_CREATE:
	{
		HWND hWin = CreateWindowEx(WS_EX_TOPMOST, L"STATIC", L"WOW ITS STATIC", WS_CHILD | WS_VISIBLE, 20, 20, 200, 20, hWnd, (HMENU)NULL, GetModuleHandle(NULL), NULL);
		SetTimer(hWnd, Close_timer, 15000, NULL);
		SetTimer(hWnd, Color_timer,100, NULL);
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
			PostMessage(hWnd, WM_CLOSE, wParam, lParam);
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
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
		
		return 0;
	}
}
