#ifndef CONST_PIRATEBOX
#define CONST_PIRATEBOX

#include "PirateBox.h"

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

PirateBox::PirateBox() :
    ImpulseEntity("pirate_box@2x.png", 1, 1)
    {
    }

PirateBox* PirateBox::create()
{
    PirateBox* entity = new PirateBox();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void PirateBox::onCreate()
{
    ImpulseEntity::onCreate();
}

void PirateBox::onDestroy()
{
    ImpulseEntity::onDestroy();
}

void PirateBox::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
}

// ===========================================================
// Virtual Methods
// ===========================================================

PirateBox* PirateBox::deepCopy()
{
    return PirateBox::create();
}

#endif