// *********************************************************************
// Name: main.cpp
// Date: 2017/02/12 04:12
// Author: sai27
// Description:
// *********************************************************************
#include "stdafx.h"
#include "SoftRenderApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	SoftRenderApp app;
	if (app.Init(hInstance))
	{
		app.Run();
		app.Destroy();
	}
	return 0;
}