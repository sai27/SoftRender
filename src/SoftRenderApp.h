// *********************************************************************
// Name: SoftRenderApp.h
// Date: 2017/02/12 04:12
// Author: sai27
// Description:
// *********************************************************************
#ifndef __SOFTRENDERAPP_H__
#define __SOFTRENDERAPP_H__

class SoftRenderApp
{
public:
	SoftRenderApp();
	~SoftRenderApp();

	bool Init(HINSTANCE hInstance);
	void Destroy();
	void Run();

	bool Update();
private:
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
};

#endif
