#include <windows.h>
#include <string>

class Window
{
private:
	int height;
	int width;
	HWND hWnd;

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

public:
	Window()
	{
		// Register the window class
		const char CLASS_NAME[] = "WindowClass";
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);

		// Get screen dimensions
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		width = desktop.right;
		height = desktop.bottom;

		// Create the window
		hWnd = CreateWindowEx(
			0, CLASS_NAME, L"bazuu", WS_OVERLAPPEDWINDOW,
			0, 0, width, height, NULL, NULL, NULL, NULL);

		if (hWnd == NULL)
		{
			MessageBox(NULL, L"Window creation failed!", L"Error", MB_ICONERROR);
			return;
		}

		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, width, height, SWP_SHOWWINDOW);
	}

	void showWindowInfo()
	{
		RECT rect;
		GetClientRect(hWnd, &rect);
		MessageBox(hWnd, (L"Width: " + std::to_wstring(rect.right) + L"\nHeight: " + std::to_wstring(rect.bottom)).c_str(), L"Window Info", MB_OK);
	}

	void runMessageLoop()
	{
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
};

// #include <string>
// #include "wtypes.h"

// class Window {

// private:
// 	int height;
// 	int width;

// public:
// 	Window() {
// 		RECT desktop;
// 		// Get a handle to the desktop window
// 		const HWND hDesktop = GetDesktopWindow();
// 		// Get the size of screen to the variable desktop
// 		GetWindowRect(hDesktop, &desktop);
// 		// The top left corner will have coordinates (0,0)
// 		// and the bottom right corner will have coordinates
// 		// (horizontal, vertical)
// 		width = desktop.right;
// 		height = desktop.bottom;
// 	}

// 	int getHeight() {
// 		return height;
// 	}
// 	int getWidth() {
// 		return width;
// 	}
}
;