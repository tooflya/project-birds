#ifndef CONST_UTILS
#define CONST_UTILS

#include "Utils.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

float Utils::Pi = atan(1.0) * 4;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

float Utils::randomf(float min, float max)
{
	return min + (float) arc4random() / ((float) RAND_MAX / (max - min));
}

int Utils::random(int min, int max)
{
	return min + arc4random() / (RAND_MAX / (max + 1 - min));
}

float Utils::coord(float pCoordinate)
{
	return pCoordinate / CCDirector::sharedDirector()->getContentScaleFactor();
}

float Utils::coordP(float pCoordinate)
{
	return pCoordinate / sqrt(Options::CAMERA_WIDTH * Options::CAMERA_WIDTH + Options::CAMERA_HEIGHT * Options::CAMERA_HEIGHT) / CCDevice::getDPI() / 3.5;
}

float Utils::round(float x)
{
	float x2 = x * 100;

 	return (x2 - floor(x2) >= 0.5 ? ceil(x2) : floor(x2)) / 100;
}

float Utils::distance(float dX0, float dY0, float dX1, float dY1)
{
    return sqrt((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0));
}

bool Utils::probably(int pProbably)
{
	return Utils::random(0, 100) < pProbably;
}

CCPoint Utils::vectorNormalize(float pVectorX, float pVectorY, float pMultipleFactor)
{
	float x = pVectorX / sqrt(pVectorX * pVectorX + pVectorY * pVectorY) * pMultipleFactor;
	float y = pVectorY / sqrt(pVectorX * pVectorX + pVectorY * pVectorY) * pMultipleFactor;

	return ccp(x, y);
}

long Utils::millisecondNow()
{
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now, NULL);
    return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

string Utils::intToString(int i)
{
	stringstream s;
    
    s << i;
    
    return s.str();
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif