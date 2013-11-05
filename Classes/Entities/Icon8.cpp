#ifndef CONST_ICON8
#define CONST_ICON8

#include "Icon8.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Icon8::Icon8(const char* pTextureFileName, CCNode* pParent) :
    Entity(pTextureFileName, 3, 3, pParent)
    {
    }

Icon8* Icon8::create(const char* pTextureFileName, CCNode* pParent)
{
	Icon8* entity = new Icon8(pTextureFileName, pParent);
    entity->autorelease();

    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Icon8::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
}

void Icon8::onCreate()
{
    Entity::onCreate();
}

void Icon8::onDestroy()
{
    Entity::onDestroy();
}

#endif