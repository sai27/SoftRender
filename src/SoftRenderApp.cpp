// *********************************************************************
// Name: SoftRenderApp.h
// Date: 2017/02/12 04:12
// Author: sai27
// Description:
// *********************************************************************
#include "stdafx.h"
#include "SoftRenderApp.h"

// Forward declarations of functions included in this code module:

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		// 		switch (wmId)
		// 		{
		// 		default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		//		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

SoftRenderApp::SoftRenderApp()
{

}

SoftRenderApp::~SoftRenderApp()
{

}

bool SoftRenderApp::Init(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCE(IDC_SOFTRENDERER);
	wcex.lpszClassName = L"SoftRenderer Window Class";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wcex);


	m_hInstance = hInstance; // Store instance handle in our global variable

	const int createWidth = 800;
	const int createHeight = 600;

	m_hWnd = CreateWindow(L"SoftRenderer Window Class", L"SoftRendererApp", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, createWidth, createHeight, NULL, NULL, hInstance, NULL);

	RECT realRect;
	GetClientRect(m_hWnd, &realRect);

	int width = realRect.right - realRect.left;
	int height = realRect.bottom - realRect.top;
	width = createWidth * 2 - width;
	height = createHeight * 2 - height;

	MoveWindow(m_hWnd, GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2, width, height, FALSE);

	if (!m_hWnd)
	{
		return false;
	}

	// ÏÔÊ¾´°¿Ú
	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(m_hWnd);

	// ÇÐ»»½¹µã
	SetFocus(m_hWnd);
	SetForegroundWindow(m_hWnd);

	return true;
}

void SoftRenderApp::Destroy()
{
	 
}

void SoftRenderApp::Run()
{
	for (;;)
	{
		MSG msg;

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message != WM_QUIT)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{

				break;
			}
		}
		else
		{

			if (!Update())
			{
				// need to clean the message loop (WM_QUIT might cause problems in the case of a restart)
				// another message loop might have WM_QUIT already so we cannot rely only on this 
				while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				break;
			}
		}
	}
}

bool SoftRenderApp::Update()
{
	return true;
}

