/****************************************************************************************** 
 *	Timer.h																				  *
	Copyright 2015 –Èª√¥Û—ß <http://www.oxox.work>
 ******************************************************************************************/
#pragma once
#include "DirectXMath.h"
#include "DirectXPackedVector.h"

using namespace DirectX;
using namespace DirectX::PackedVector;
#include <windows.h>

class Timer
{
public:
	Timer();
	void StartWatch();
	void StopWatch();
	float GetTimeMilli() const;
private:
	float invFreqMilli;
	bool watchStopped;
	__int64 currentCount;
	__int64 startCount;
};