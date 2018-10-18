/****************************************************************************************** 
 *	D3DGraphics.h																		  *
 *	Copyright 2015 –Èª√¥Û—ß <http://www.oxox.work>								  *
 ******************************************************************************************/
#pragma once
#include "DirectXMath.h"
#include "DirectXPackedVector.h"

using namespace DirectX;
using namespace DirectX::PackedVector;
#include <d3d9.h>

void Swap(int *x1, int *x2);

class D3DGraphics
{
public:
	D3DGraphics( HWND hWnd );
	~D3DGraphics();
	void PutPixel( int x,int y,int r,int g,int b );
	void BeginFrame();
	void EndFrame();
	void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b);
	void DrawCircle(int cx, int cy, int rad, int r, int g, int b);
	void DrawDisc(int cx, int cy, int rad, int r, int g, int b);
private:
	
	IDirect3D9*			pDirect3D;
	IDirect3DDevice9*	pDevice;

	IDirect3DSurface9* pBackBuffer;
	D3DLOCKED_RECT rect;
};