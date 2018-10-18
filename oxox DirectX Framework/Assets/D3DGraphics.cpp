/****************************************************************************************** 

 ******************************************************************************************/
#include "D3DGraphics.h"
#include "math.h"
#include "Game.h"
#include "DirectXMath.h"
#include "DirectXPackedVector.h"

using namespace DirectX;
using namespace DirectX::PackedVector;
D3DGraphics::D3DGraphics( HWND hWnd )
{
	rect.pBits = NULL;
	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );

	pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
}

D3DGraphics::~D3DGraphics()
{
	if( pDevice )
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if( pDirect3D )
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
	if (pBackBuffer)
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
	}
}

void Swap(int *x1, int *x2)
{
	
	int temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{

	((D3DCOLOR*)rect.pBits)[ x + (rect.Pitch >> 2) * y ] = D3DCOLOR_XRGB( r,g,b );
}

void D3DGraphics::BeginFrame()
{
	pDevice->Clear( 0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),0.0f,0 );
	pBackBuffer->LockRect(&rect, NULL, NULL);
}

void D3DGraphics::EndFrame()
{
	pBackBuffer->UnlockRect();
	pDevice->Present( NULL,NULL,NULL,NULL );
}

void D3DGraphics::DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (abs(dy) > abs(dx))
	{
		if (y1 > y2)
		{
			Swap(&x1,&x2);
			Swap(&y1,&y2);
		}

		float m = (float)dx / (float)dy;
		float b1 = x1 - m * y1;
		for (int y = y1; y < y2; y++)
		{
			int x = m * y + b1;
			PutPixel(x, y, r, g, b);
		}
	}
	else
	{
		if (x1 > x2)
		{
			Swap(&x1, &x2);
			Swap(&y1, &y2);
		}

		float m = (float)dy / (float)dx;
		float b1 = y1 - m * x1;
		for (int x = x1; x < x2; x++)
		{
			int y = m * x + b1;
			PutPixel(x, y, r, g, b);
		}
	}
}
void D3DGraphics::DrawDisc(int cx, int cy, int rad, int r, int g, int b)
{
	for (int x = cx - rad; x < cx + rad; x++)
	{
		for (int y = cy - rad; y < cy + rad; y++)
		{
			if (sqrt((float)(x - cx)*(x - cx) + (y - cy)*(y - cy)) < rad)
			{

				PutPixel(x, y, r, g, b);
			}
		}
	}
}
void D3DGraphics::DrawCircle(int cx, int cy, int rad, int r, int g, int b)
{
	float radSqr = rad * rad;
	float x0 = (sqrt(2.0)) / 2 * rad;
	for (int x = 0; x < x0; x++)
	{
		int y = sqrt(radSqr - x * x);//x*x+y*y==rad*rad,
		PutPixel(x + cx, y + cy, r, g, b);
		PutPixel(x + cx, -y + cy, r, g, b);
		PutPixel(-x + cx, y + cy, r, g, b);
		PutPixel(-x + cx, -y + cy, r, g, b);
		PutPixel(y + cx, x + cy, r, g, b);
		PutPixel(y + cx, -x + cy, r, g, b);
		PutPixel(-y + cx, x + cy, r, g, b);
		PutPixel(-y + cx, -x + cy, r, g, b);
	}
}