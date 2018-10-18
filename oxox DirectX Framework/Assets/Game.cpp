/****************************************************************************************** 

 ******************************************************************************************/
#include "Game.h"
#include "time.h"
#include "math.h"
#include "DirectXMath.h"
#include "DirectXPackedVector.h"

using namespace DirectX;
using namespace DirectX::PackedVector;


Point MidPoint(Point p1, Point p2)
{
	Point p3;
	p3.x = (p1.x + p2.x) / 2;
	p3.y = (p1.y + p2.y) / 2;
	return p3;
}
Game::Game(HWND hWnd, const KeyboardServer& kServer, const MouseServer& mServer)
	: gfx(hWnd),
	kbd(kServer),
	audio(hWnd),
	mouse(mServer),
	faceX(400),
	faceY(300),
	gameIsOver(false)
	//______________________________________________________________________________-
	/*
	x1(400),
	y1(300),
	x2(200),
	y2(100)*/
{
	srand((unsigned int)time(NULL));
	for (int index = 0; index < nFood; index++)
	{
		food[index].x = rand() % (800 - 24);
		food[index].y = rand() % (600 - 24);

		food[index].vx = (rand() % 8001) / 1000.0f - 4.0f;
		food[index].vy = (rand() % 8001) / 1000.0f - 4.0f;
		ReseGoal();
	}
}
void Game::Go()
{
	gfx.BeginFrame();
	if (!gameIsOver)
	{
		UpateFace();
		UpateFood();
	}

	ComposeFrame();
	gfx.EndFrame();

}

void Game::ComposeFrame()
{
	// TODO: insert frame drawing code here
	//gfx.DrawLine(100, 100, 200, 300, 255, 0, 0);
	//»®Ïß½µÖ¡ÂÊ

	/*
	int _run;
	_run = 10;
	int r, g, b;
	r = 255;
	g = 255;
	b = 255;

	
	if (kbd.RightIsPressed())
	{
		x1 = x1 + 10;
	}
	if (kbd.LeftIsPressed())
	{
		x1 = x1 - 10;
	}
	if (kbd.UpIsPressed())
	{
		y1 = y1- 10;
	}
	if (kbd.DownIsPressed())
	{
		y1 = y1 + 10;
	}
	if (kbd.SpaceIsPressed())
	{
		r = 0;
		b = 0;
	}
	if (y1 < 5)
		y1 = 5;
	if (y1 > 595)
		y1 = 595;
	

DrawReticle(x1, y1, r, g, b);


	if (x2 == 200 && y2 > 100)
	{

		y2= y2 - _run;
	}
	if (y2 == 500)
	{

		x2 = x2 - _run;
	}
	if (x2 == 600) {

		y2 = y2 + _run;
	}
	if (y2 == 100)
	{

		x2 = x2 + _run;
	}

	DrawReticle( x2,  y2,  r, g, b);
	*/
	//____________________________________________________________________________________________________________
	/*gfx.DrawDisc(goalX, goalY, 10, 255, 255, 0);

	Point p1, p2;
	p1.x = faceX;
	p1.y = faceY;
	p2.x = goalX;
	p2.y = goalY;
	Point mid = MidPoint(p1, p2);
	gfx.DrawDisc(mid.x, mid.y, 5, 100, 100, 255);


	for (int index = 0; index < nFood; index++)
	{
		
			DrawFood(food[index].x, food[index].y);
		
	}
DrawFace(faceX, faceY);
	if (gameIsOver)
	{
		DrawFace(375, 275);
	}
	*/

	//_____________________________________________________________________________________________
	if (mouse.IsInWindow())
	{
		gfx.DrawLine(400, 300, mouse.GetMouseX(), mouse.GetMouseY(), 255, 255, 255);
	}
}


	void Game::DrawReticle(int x, int y, int r, int g, int b)
	{
		gfx.PutPixel(x, y, r, g, b);
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
	}
	void Game::DrawFace(int x, int y) {
		int r, g, b;
		r = 0;
		g = 0;
		b = 255;
		gfx.PutPixel(x, y, r, g, b);
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
	}

	void Game::DrawFood(int x, int y) {
		int r, g, b;
		r = 255;
		g = 0;
		b = 0;
		gfx.PutPixel(x, y, r, g, b);
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
	}

	int Game::_keepoutx(int x)
	{
		if (x < 1)
			x = 1;
		if (x > 800)
			x = 800;
		
		return x;
	}
	int Game::_keepouty( int y)
	{
		
		if (y < 1)
			y = 1;
		if (y > 600)
			y = 600;
		return y;
	}

	void Game::UpateFace()
	{
		int speed = 5;
		if (kbd.SpaceIsPressed())
		{
			speed = 10;
		}
		if (kbd.RightIsPressed())
		{
			faceX = faceX + speed;
		}
		if (kbd.LeftIsPressed())
		{
			faceX = faceX - speed;
		}
		if (kbd.UpIsPressed())
		{
			faceY = faceY - speed;
		}
		if (kbd.DownIsPressed())
		{
			faceY = faceY + speed;
		}

		if (faceX < 5)
		{
			faceX = 5;
		}
		if (faceX > 795)
		{
			faceX = 795;
		}
		if (faceY < 5)
		{
			faceY = 5;
		}
		if (faceY > 595)
		{
			faceY = 595;
		}
		int cx = faceX ;
		int cy = faceY ;
		if (sqrt((float)(cx - goalX)*(cx - goalX) + (cy - goalY)*(cy - goalY)) < 5 + GOALRAD)
		{
			ReseGoal();
		}
	}
	void Game::UpateFood()
	{
		int lottery = rand() % 20;
		for (int index = 0; index < nFood; index++)
		{
			if (lottery == index)
			{
				food[index].vx = (rand() % 8001) / 1000.0f - 4.0f;
				food[index].vy = (rand() % 8001) / 1000.0f - 4.0f;
			}
			food[index].x += food[index].vx;
			food[index].y += food[index].vy;

			if (food[index].x-5 < 0)
			{
				food[index].x = 0+5;
				food[index].vx = -food[index].vx;
			}
			else if (food[index].x+5 > 799)
			{
				food[index].x = 799 - 5;
				food[index].vx = -food[index].vx;
			}
			if (food[index].y - 5 < 0)
			{
				food[index].y = 0 + 5;
				food[index].vy = -food[index].vy;
			}
			else if (food[index].y + 5 > 599)
			{
				food[index].y = 599 - 5;
				food[index].vy = -food[index].vy;
			}
			if (faceX - 5 < food[index].x + 5 && faceX + 5 > food[index].x - 5
				&& faceY - 5 < food[index].y + 5 && faceY + 5 > food[index].y - 5)
			{
				gameIsOver = true;
			}

		}
	}

	void Game::ReseGoal()
	{
		goalX = (rand() % (799 - GOALRAD * 2)) + GOALRAD;
		goalY = (rand() % (599 - GOALRAD * 2)) + GOALRAD;
	}