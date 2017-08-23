#include<windows.h>

int timer_1 = 1;
int timer_2 = 2;
int timer_3 = 3;
HINSTANCE hChild_1;
HINSTANCE hChild_2;
HINSTANCE hChild_3;
HWND child, child_2, child_3;

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LPWSTR szClassName = L"Window";
	LPWSTR szTitleName = L"Window";


	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hbrBackground = CreateSolidBrush(RGB(228, 16, 235));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass))
		return false;


	HWND hWnd = CreateWindowEx
		(
		WS_EX_TOPMOST,
		szClassName,
		szTitleName,
		WS_OVERLAPPEDWINDOW,
		0, 0, 500, 500,
		NULL,
		NULL,
		hInstance,
		NULL
		);


	if (!hWnd)
		return false;



	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;



}

LRESULT CALLBACK WinProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	
	switch (iMsg)
	{

	case WM_CREATE:
	{
					  SetTimer(hwnd, timer_1, 1000, NULL);
					  SetTimer(hwnd, timer_2, 2000, NULL);
					  SetTimer(hwnd, timer_3, 3000, NULL);

	}break;

	case WM_TIMER:
	{
					 if (wParam == timer_1)
					 {
						 WNDCLASS w;
						 memset(&w, 0, sizeof(WNDCLASS));
						 w.lpfnWndProc = ChildProc;
						 w.hInstance = hChild_1;
						 w.hbrBackground = CreateSolidBrush(RGB(0, 230, 0));
						 w.lpszClassName = L"ChildWClass";
						 w.hCursor = LoadCursor(NULL, IDC_CROSS);
						 RegisterClass(&w);

						  child = CreateWindowEx(0, L"ChildWClass", L"ChildWClass",
							 WS_CHILD | WS_OVERLAPPEDWINDOW, 0, 0,
							 400, 400, hwnd, NULL, hChild_1, NULL);
						 ShowWindow(child, SW_NORMAL);
						 UpdateWindow(child);
						 KillTimer(hwnd, timer_1);
					 }

					 else if (wParam == timer_2)
					 {
						 WNDCLASS wn;
						 memset(&wn, 0, sizeof(WNDCLASS));
						 wn.lpfnWndProc = ChildProc;
						 wn.hInstance = hChild_2;
						 wn.hbrBackground = CreateSolidBrush(RGB(230, 0, 0));
						 wn.lpszClassName = L"ChildWClass_2";
						 wn.hCursor = LoadCursor(NULL, IDC_CROSS);
						 RegisterClass(&wn);

						  child_2 = CreateWindowEx(0, L"ChildWClass_2", L"ChildWClass_2",
							 WS_CHILD | WS_OVERLAPPEDWINDOW, 0, 0,
							 300, 300, child, NULL, hChild_2, NULL);
						 ShowWindow(child_2, SW_NORMAL);
						 UpdateWindow(child_2);
						 KillTimer(hwnd, timer_2);
					 }

					 else if (wParam == timer_3)
					 {
						 WNDCLASS wnd;
						 memset(&wnd, 0, sizeof(WNDCLASS));
						 wnd.lpfnWndProc = ChildProc;
						 wnd.hInstance = hChild_3;
						 wnd.hbrBackground = CreateSolidBrush(RGB(0, 0, 230));
						 wnd.lpszClassName = L"ChildWClass_3";
						 wnd.hCursor = LoadCursor(NULL, IDC_CROSS);
						 RegisterClass(&wnd);

						  child_3 = CreateWindowEx(0, L"ChildWClass_3", L"ChildWClass_3",
							 WS_CHILD | WS_OVERLAPPEDWINDOW, 0, 0,
							 200, 200, child_2, NULL, hChild_3, NULL);
						 ShowWindow(child_3, SW_NORMAL);
						 UpdateWindow(child_3);
						 KillTimer(hwnd, timer_3);
					 }

	}break;




	case WM_DESTROY:
	{  					  
					   PostQuitMessage(0);
	}break;

	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);

		return 0;
	}
}

LRESULT CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	if (Message == WM_DESTROY)
	{
		return 0;
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}
