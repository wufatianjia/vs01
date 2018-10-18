/****************************************************************************************** 
 *	Game.h																				  *
	Copyright 2015 –Èª√¥Û—ß <http://www.oxox.work>
 ******************************************************************************************/
#pragma once
#include "DirectXMath.h"
#include "DirectXPackedVector.h"


using namespace DirectX;
using namespace DirectX::PackedVector;
#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Sound.h"


#define nFood 10
#define GOALRAD 10
struct Point
{
	int x;
	int y;
};

Point MidPoint(Point p1, Point p2);
class Game
{
public:
	Game( HWND hWnd,const KeyboardServer& kServer , const MouseServer& mServer);
	void Go();

	struct Food
	{
		float x;
		float y;
		float vx;
		float vy;
	};
private:
	void ComposeFrame();
	
	void DrawReticle(int x, int y, int r, int g, int b);
	void DrawFace(int x, int y);
	void DrawFood(int x, int y);

	void UpateFace();
	void UpateFood();

	void ReseGoal();

	int _keepoutx(int x);
	int _keepouty(int x);
	
	/********************************/
	/*  User Functions              */

	// TODO: User functions go here

	/********************************/
private:
	D3DGraphics gfx;
	KeyboardClient kbd;
	MouseClient mouse;
	DSound audio;
	int x1;
	int y1;
	int faceX;
	int faceY;
	int goalX;
	int goalY;

	bool gameIsOver;

	Food food[nFood];

	/*float foodX[nFood];
	float foodY[nFood];
	float foodXVelocity[nFood];
	float foodYVelocity[nFood];
	*/
	//bool EatFood[nFood];
	//bool allFoodEat;
	
	//_____________________________________________________________________________________________________
	/*
	int x1;
	int y1;
	int x2;
	int y2;*/
	/********************************/
	/*  User Variables              */
	
	// TODO: User variables go here

	/********************************/
};