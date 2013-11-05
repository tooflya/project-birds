#ifndef CONST_MAPDESCRIPTIONLIST
#define CONST_MAPDESCRIPTIONLIST

#include "MapDescriptionList.h"

#include "Menu.h"

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

MapDescriptionList::~MapDescriptionList()
{
    this->removeAllChildrenWithCleanup(true);
}

MapDescriptionList::MapDescriptionList(CCNode* pParent) :
    List(Utils::coord(512), Utils::coord(640), Utils::coord(512), Utils::coord(/** 750 **/0), ((Entity*) pParent)->getWidth() / 2, ((Entity*) pParent)->getHeight() / 2 + Utils::coord(0), "about_scroll_fill_small@2x.png", pParent),
	mIcon(),
	mSilverCoinsIcon(0),
    mGoldCoinsIcon(0)
	{
        this->setListType(List::TYPE_VERTICAL);
        this->setParentType(List::PARENT_TYPE_POPUP);

        this->mSpriteBatch = SpriteBatch::create("TextureAtlas5");

        this->addChild(this->mSpriteBatch);
        
        this->mIcon[0] = Entity::create("day1.png", this);
        this->mIcon[1] = Entity::create("day2.png", this);
        this->mIcon[2] = Entity::create("day3.png", this);
        this->mIcon[3] = Entity::create("day4.png", this);
        this->mIcon[4] = Entity::create("day5.png", this);

        this->mSilverCoinsIcon = Entity::create("coins_silver@2x.png", 5, 4, this->mSpriteBatch);
        this->mGoldCoinsIcon = Entity::create("coins@2x.png", 5, 4, this->mSpriteBatch);
        
        this->mSilverCoinsIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(25), Options::CAMERA_CENTER_Y + Utils::coord(0));
        this->mSilverCoinsIcon->setRotation(-45);
        this->mSilverCoinsIcon->setScale(0.75);
        this->mSilverCoinsIcon->animate(0.05);
        
        this->mGoldCoinsIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(25), Options::CAMERA_CENTER_Y - Utils::coord(50));
        this->mGoldCoinsIcon->setRotation(-45);
        this->mGoldCoinsIcon->setScale(0.75);
        this->mGoldCoinsIcon->animate(0.05);
        
        for(int i = 0; i < 5; i++)
        this->mIcon[i]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(120), Options::CAMERA_CENTER_Y + Utils::coord(20));
        
        this->mTopText = Text::create(Options::TEXT_MAPDESCRIPTION_TOP, this);
        this->mBottomText = Text::create(Options::TEXT_MAPDESCRIPTION_BOTTOM, this);
        this->mMiddleText = Text::create(Options::TEXT_MAPDESCRIPTION_MIDDLE, this);
        
        Textes textes1 = {"", "Comic Sans MS", 32, -1};
        
        this->mSilverCoinsCountText = Text::create(textes1, this);
        this->mGoldCoinsCountText = Text::create(textes1, this);
        
        this->mTopText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(230));
        this->mBottomText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200));
        this->mMiddleText->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(90), Options::CAMERA_CENTER_Y + Utils::coord(110));
        
        this->mSilverCoinsCountText->setCenterPosition(this->mSilverCoinsIcon->getCenterX() + this->mSilverCoinsCountText->getWidth(), Options::CAMERA_CENTER_Y - Utils::coord(0));
        this->mGoldCoinsCountText->setCenterPosition(this->mGoldCoinsIcon->getCenterX() + this->mGoldCoinsCountText->getWidth(), Options::CAMERA_CENTER_Y - Utils::coord(50));
        
        this->mTopText->setColor(ccc3(167.0, 65.0, 7.0));
        this->mBottomText->setColor(ccc3(255.0, 130.0, 0.0));
        this->mMiddleText->setColor(ccc3(255.0, 130.0, 0.0));
        
        this->mSilverCoinsCountText->setColor(ccc3(255.0, 130.0, 0.0));
        this->mGoldCoinsCountText->setColor(ccc3(255.0, 130.0, 0.0));
    }

MapDescriptionList* MapDescriptionList::create(CCNode* pParent)
{
    MapDescriptionList* list = new MapDescriptionList(pParent);
    list->autorelease();
    list->retain();
    
    return list;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void MapDescriptionList::onEnter()
{
    List::onEnter();
    
    int d = static_cast<Menu*>(this->mParent->getParent())->mMapPopup->day;
    
    int s = 0;
    int g = 0;
    
    switch(d)
    {
        case 1:
            
        s = 500;
        g = 10;
            
        break;
        case 2:
            
        s = 1000;
        g = 25;
            
        break;
        case 3:
            
        s = 4000;
        g = 05;
            
        break;
        case 4:
            
        s = 8000;
        g = 100;
            
        break;
        case 5:
            
        s = 10000;
        g = 500;
            
        break;
    }
    
    this->mSilverCoinsCountText->setString(ccsf("%d", s));
    this->mGoldCoinsCountText->setString(ccsf("%d", g));
    
    this->mMiddleText->setString(ccsf(Options::TEXT_MAPDESCRIPTION_MIDDLE.string, d));
    
    for(int i = 0; i < 5; i++)
        this->mIcon[i]->destroy();
    
    this->mIcon[d - 1]->create();
    
    this->mSilverCoinsCountText->setCenterPosition(this->mSilverCoinsIcon->getCenterX() + this->mSilverCoinsCountText->getWidth(), Options::CAMERA_CENTER_Y - Utils::coord(0));
    this->mGoldCoinsCountText->setCenterPosition(this->mGoldCoinsIcon->getCenterX() + this->mGoldCoinsCountText->getWidth(), Options::CAMERA_CENTER_Y - Utils::coord(50));
}

#endif