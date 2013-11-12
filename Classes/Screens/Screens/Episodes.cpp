#ifndef CONST_EPISODES
#define CONST_EPISODES

#include "Episodes.h"

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

Episodes::~Episodes()
{
    CC_SAFE_RELEASE(this->mPoints);
    CC_SAFE_RELEASE(this->mStars);
    CC_SAFE_RELEASE(this->mDots);
    CC_SAFE_RELEASE(this->mDarkLayers[0]);
    CC_SAFE_RELEASE(this->mDarkLayers[1]);
    CC_SAFE_RELEASE(this->mDarkLayers[2]);
    CC_SAFE_RELEASE(this->mDarkLayers[3]);
    CC_SAFE_RELEASE(this->mDarkLayers[4]);
}

Episodes::Episodes() :
    mEpisodes(),
    mDarkLayers(),
    mPoints(0),
    mStars(0),
    mDots(0),
    mEpisodeText(),
    mStarsText(),
    mUnlockText(),
    mEpisodeNameText()
    {
        float scale = Options::CAMERA_CENTER_X / Utils::coord(360);
        float shift = abs(Options::CAMERA_HEIGHT - (((Utils::coord(400) * scale) * 2) + (Utils::coord(480) * scale) * 2));
        
        CCLayer* sc = CCLayer::create();
        sc->setContentSize(CCSize(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT + shift));
        
        cocos2d::extension::CCScrollView* scroll = cocos2d::extension::CCScrollView::create(CCSize(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT), sc);
        scroll->setBounceable(false);
        
        this->addChild(scroll);
        
        CCLayer* comingSoon = CCLayer::create();

		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas18");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas18");

        scroll->addChild(spriteBatch);
        scroll->addChild(spriteBatch2, 3);
        
        scroll->addChild(comingSoon);
        
        for(int i = 0; i < 5; i++)
        {
            this->mDarkLayers[i] = CCLayerColor::create(ccc4(0, 0, 0, 180));
            
            if(i == 4)
            {
                this->mDarkLayers[i]->setContentSize(CCSize(Utils::coord(720) * scale, Utils::coord(480) * scale));
            }
            else
            {
                this->mDarkLayers[i]->setContentSize(CCSize(Utils::coord(360) * scale, Utils::coord(400) * scale));
            }
            
            this->mDarkLayers[i]->ignoreAnchorPointForPosition(false);
            scroll->addChild(this->mDarkLayers[i], 2);
        }

		EntityStructure structure1 = {"progress_map_episode1@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure2 = {"progress_map_episode2@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure3 = {"progress_map_episode3@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure4 = {"progress_map_episode4@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure5 = {"progress_map_episode5@2x.png", 1, 1, 0, 0, 720, 480};

		this->mEpisodes[0] = Button::create(structure1, scroll, Options::BUTTONS_ID_MORE_BACK, this);
		this->mEpisodes[1] = Button::create(structure2, spriteBatch, Options::BUTTONS_ID_MORE_BACK, this);
		this->mEpisodes[2] = Button::create(structure3, spriteBatch, Options::BUTTONS_ID_MORE_BACK, this);
		this->mEpisodes[3] = Button::create(structure4, spriteBatch, Options::BUTTONS_ID_MORE_BACK, this);
		this->mEpisodes[4] = Button::create(structure5, spriteBatch, Options::BUTTONS_ID_MORE_BACK, this);
        
		this->mEpisodes[0]->setScale(scale);
		this->mEpisodes[1]->setScale(scale);
		this->mEpisodes[2]->setScale(scale);
		this->mEpisodes[3]->setScale(scale);
		this->mEpisodes[4]->setScale(scale);

		this->mEpisodes[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mEpisodes[0]->getWidthScaled() / 2, this->mEpisodes[0]->getHeightScaled() / 2);
		this->mEpisodes[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[1]->getWidthScaled() / 2, this->mEpisodes[1]->getHeightScaled() / 2);
		this->mEpisodes[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mEpisodes[2]->getWidthScaled() / 2, this->mEpisodes[0]->getCenterY() + this->mEpisodes[2]->getHeightScaled());
		this->mEpisodes[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[3]->getWidthScaled() / 2, this->mEpisodes[1]->getCenterY() + this->mEpisodes[3]->getHeightScaled());
		this->mEpisodes[4]->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mEpisodes[3]->getCenterY() + this->mEpisodes[3]->getHeightScaled() / 2 + this->mEpisodes[4]->getHeightScaled() / 2);
        
        this->mPoints = EntityManager::create(6, Entity::create("progress_map_point_sprite@2x.png", 1, 2), spriteBatch2);
        this->mStars = EntityManager::create(6, Entity::create("end_lvl_star_sprite@2x.png", 3, 2), scroll, 3);
        this->mDots = EntityManager::create(200, Entity::create("progress_map_dot@2x.png"), spriteBatch2, 3);

        this->mPoints->create()->setCenterPosition(Utils::coord(211) * scale, Utils::coord(103) * scale);
        this->mPoints->create()->setCenterPosition(Utils::coord(498) * scale, Utils::coord(77) * scale);
        this->mPoints->create()->setCenterPosition(Utils::coord(166) * scale, Utils::coord(487) * scale);
        this->mPoints->create()->setCenterPosition(Utils::coord(588) * scale, Utils::coord(538) * scale);
        this->mPoints->create()->setCenterPosition(Utils::coord(360) * scale, Utils::coord(980) * scale);
        this->mPoints->create()->setCenterPosition(Utils::coord(266) * scale, Utils::coord(1391) * scale);
        
        static_cast<Entity*>(this->mPoints->objectAtIndex(0))->setCurrentFrameIndex(1);
        
        this->mDarkLayers[0]->setPosition(ccp(this->mEpisodes[0]->getCenterX() - this->mEpisodes[0]->getWidthScaled() / 2, this->mEpisodes[0]->getCenterY() - this->mEpisodes[0]->getHeightScaled() / 2));
        this->mDarkLayers[1]->setPosition(ccp(this->mEpisodes[1]->getCenterX() - this->mEpisodes[1]->getWidthScaled() / 2, this->mEpisodes[1]->getCenterY() - this->mEpisodes[1]->getHeightScaled() / 2));
        this->mDarkLayers[2]->setPosition(ccp(this->mEpisodes[2]->getCenterX() - this->mEpisodes[2]->getWidthScaled() / 2, this->mEpisodes[2]->getCenterY() - this->mEpisodes[2]->getHeightScaled() / 2));
        this->mDarkLayers[3]->setPosition(ccp(this->mEpisodes[3]->getCenterX() - this->mEpisodes[3]->getWidthScaled() / 2, this->mEpisodes[3]->getCenterY() - this->mEpisodes[3]->getHeightScaled() / 2));
        this->mDarkLayers[4]->setPosition(ccp(this->mEpisodes[4]->getCenterX() - this->mEpisodes[4]->getWidthScaled() / 2, this->mEpisodes[4]->getCenterY() - this->mEpisodes[4]->getHeightScaled() / 2));
        
        this->mEpisodeText[0] = Text::create((Textes) {"Episode %d", Options::FONT, 48, -1}, scroll);
        this->mEpisodeText[1] = Text::create((Textes) {"Episode %d", Options::FONT, 48, -1}, scroll);
        this->mEpisodeText[2] = Text::create((Textes) {"Episode %d", Options::FONT, 48, -1}, scroll);
        this->mEpisodeText[3] = Text::create((Textes) {"Episode %d", Options::FONT, 48, -1}, scroll);
        this->mEpisodeText[4] = Text::create((Textes) {"Episode %d", Options::FONT, 48, -1}, scroll);
        this->mEpisodeText[5] = Text::create((Textes) {"Episode %d", Options::FONT, 48, -1}, scroll);
        
        this->mEpisodeText[0]->setZOrder(3);
        this->mEpisodeText[1]->setZOrder(3);
        this->mEpisodeText[2]->setZOrder(3);
        this->mEpisodeText[3]->setZOrder(3);
        this->mEpisodeText[4]->setZOrder(3);
        this->mEpisodeText[5]->setZOrder(3);
        
        this->mEpisodeNameText[0] = Text::create((Textes) {"\"Home\"", Options::FONT, 35, -1}, scroll);
        this->mEpisodeNameText[1] = Text::create((Textes) {"\"Robbed\"", Options::FONT, 35, -1}, scroll);
        this->mEpisodeNameText[2] = Text::create((Textes) {"\"Packing\"", Options::FONT, 35, -1}, scroll);
        this->mEpisodeNameText[3] = Text::create((Textes) {"\"Delivery\"", Options::FONT, 35, -1}, scroll);
        this->mEpisodeNameText[4] = Text::create((Textes) {"\"Selling\"", Options::FONT, 35, -1}, scroll);
        this->mEpisodeNameText[5] = Text::create((Textes) {"\"Coming soon\"", Options::FONT, 35, -1}, scroll);
        
        this->mEpisodeNameText[0]->setZOrder(3);
        this->mEpisodeNameText[1]->setZOrder(3);
        this->mEpisodeNameText[2]->setZOrder(3);
        this->mEpisodeNameText[3]->setZOrder(3);
        this->mEpisodeNameText[4]->setZOrder(3);
        this->mEpisodeNameText[5]->setZOrder(3);
        
        this->mStarsText[0] = Text::create((Textes) {"100", Options::FONT, 38, -1}, scroll);
        this->mStarsText[1] = Text::create((Textes) {"100", Options::FONT, 38, -1}, scroll);
        this->mStarsText[2] = Text::create((Textes) {"100", Options::FONT, 38, -1}, scroll);
        this->mStarsText[3] = Text::create((Textes) {"100", Options::FONT, 38, -1}, scroll);
        this->mStarsText[4] = Text::create((Textes) {"100", Options::FONT, 38, -1}, scroll);
        this->mStarsText[5] = Text::create((Textes) {"100", Options::FONT, 38, -1}, scroll);
        
        this->mUnlockText[0] = Text::create((Textes) {"you need\n \nto unlock", Options::FONT, 22, -1}, scroll);
        this->mUnlockText[1] = Text::create((Textes) {"you need\n \nto unlock", Options::FONT, 22, -1}, scroll);
        this->mUnlockText[2] = Text::create((Textes) {"you need\n \nto unlock", Options::FONT, 22, -1}, scroll);
        this->mUnlockText[3] = Text::create((Textes) {"you need\n \nto unlock", Options::FONT, 22, -1}, scroll);
        this->mUnlockText[4] = Text::create((Textes) {"you need\n \nto unlock", Options::FONT, 22, -1}, scroll);
        this->mUnlockText[5] = Text::create((Textes) {"you need\n \nto unlock", Options::FONT, 22, -1}, scroll);
        
        this->mStarsText[0]->setZOrder(3);
        this->mStarsText[1]->setZOrder(3);
        this->mStarsText[2]->setZOrder(3);
        this->mStarsText[3]->setZOrder(3);
        this->mStarsText[4]->setZOrder(3);
        this->mStarsText[5]->setZOrder(3);
        
        this->mUnlockText[0]->setZOrder(3);
        this->mUnlockText[1]->setZOrder(3);
        this->mUnlockText[2]->setZOrder(3);
        this->mUnlockText[3]->setZOrder(3);
        this->mUnlockText[4]->setZOrder(3);
        this->mUnlockText[5]->setZOrder(3);
        
        for(int i = 0; i < 5; i++)
        {
            this->mEpisodeText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mEpisodeText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(160) * scale - this->mEpisodeText[i]->getHeight() / 2);
            this->mEpisodeNameText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mEpisodeNameText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(110) * scale - this->mEpisodeNameText[i]->getHeight() / 2);
            this->mUnlockText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mUnlockText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(40) * scale - this->mUnlockText[i]->getHeight() / 2);
            this->mStarsText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mStarsText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(40)  * scale - this->mStarsText[i]->getHeight() / 2);
        }
        
        for(int i = 1; i < 5; i++)
        {
            this->mStars->create()->setCenterPosition(this->mStarsText[i]->getCenterX() - this->mStarsText[i]->getWidth() / 2 - Utils::coord(5) * scale, this->mStarsText[i]->getCenterY() + Utils::coord(7) * scale);
            static_cast<Entity*>(this->mStars->objectAtIndex(i - 1))->setCurrentFrameIndex(1);
            static_cast<Entity*>(this->mStars->objectAtIndex(i - 1))->setScale(0.2);
        }
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(245) * scale, Utils::coord(108) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(260) * scale, Utils::coord(111) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(274) * scale, Utils::coord(113) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(292) * scale, Utils::coord(114) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(308) * scale, Utils::coord(111) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(322) * scale, Utils::coord(105) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(336) * scale, Utils::coord(100) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(349) * scale, Utils::coord(95) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(363) * scale, Utils::coord(92) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(377) * scale, Utils::coord(90) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * scale, Utils::coord(85) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(404) * scale, Utils::coord(83) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(418) * scale, Utils::coord(81) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(431) * scale, Utils::coord(81) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(444) * scale, Utils::coord(76) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(460) * scale, Utils::coord(73) * scale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(498) * scale, Utils::coord(112) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(488) * scale, Utils::coord(128) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(478) * scale, Utils::coord(139) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(468) * scale, Utils::coord(150) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(457) * scale, Utils::coord(159) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(444) * scale, Utils::coord(169) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(433) * scale, Utils::coord(178) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(422) * scale, Utils::coord(190) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(409) * scale, Utils::coord(199) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(399) * scale, Utils::coord(210) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * scale, Utils::coord(222) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(385) * scale, Utils::coord(234) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(377) * scale, Utils::coord(245) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(373) * scale, Utils::coord(259) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(271) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(363) * scale, Utils::coord(283) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(357) * scale, Utils::coord(296) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(351) * scale, Utils::coord(308) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(346) * scale, Utils::coord(319) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(342) * scale, Utils::coord(331) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(337) * scale, Utils::coord(345) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(332) * scale, Utils::coord(356) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(328) * scale, Utils::coord(368) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(323) * scale, Utils::coord(380) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(316) * scale, Utils::coord(392) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(303) * scale, Utils::coord(400) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(292) * scale, Utils::coord(408) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(278) * scale, Utils::coord(412) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(263) * scale, Utils::coord(419) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(249) * scale, Utils::coord(423) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(236) * scale, Utils::coord(428) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(225) * scale, Utils::coord(435) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(213) * scale, Utils::coord(440) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(202) * scale, Utils::coord(444) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(192) * scale, Utils::coord(449) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(180) * scale, Utils::coord(457) * scale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(189) * scale, Utils::coord(512) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(202) * scale, Utils::coord(515) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(215) * scale, Utils::coord(515) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(229) * scale, Utils::coord(515) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(242) * scale, Utils::coord(517) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(253) * scale, Utils::coord(522) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(266) * scale, Utils::coord(526) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(278) * scale, Utils::coord(526) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(292) * scale, Utils::coord(526) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(304) * scale, Utils::coord(527) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(317) * scale, Utils::coord(526) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(329) * scale, Utils::coord(522) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(342) * scale, Utils::coord(522) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(354) * scale, Utils::coord(521) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(522) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(378) * scale, Utils::coord(520) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * scale, Utils::coord(516) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(404) * scale, Utils::coord(515) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(416) * scale, Utils::coord(512) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(428) * scale, Utils::coord(510) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(442) * scale, Utils::coord(507) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(454) * scale, Utils::coord(501) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(465) * scale, Utils::coord(496) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(481) * scale, Utils::coord(491) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(494) * scale, Utils::coord(489) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(509) * scale, Utils::coord(487) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(524) * scale, Utils::coord(486) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(538) * scale, Utils::coord(489) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(553) * scale, Utils::coord(496) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(565) * scale, Utils::coord(507) * scale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(560) * scale, Utils::coord(553) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(548) * scale, Utils::coord(558) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(535) * scale, Utils::coord(562) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(524) * scale, Utils::coord(567) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(513) * scale, Utils::coord(572) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(501) * scale, Utils::coord(575) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(488) * scale, Utils::coord(576) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(476) * scale, Utils::coord(579) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(465) * scale, Utils::coord(583) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(454) * scale, Utils::coord(590) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(444) * scale, Utils::coord(597) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(433) * scale, Utils::coord(605) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(424) * scale, Utils::coord(616) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(414) * scale, Utils::coord(625) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(408) * scale, Utils::coord(635) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(402) * scale, Utils::coord(646) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(395) * scale, Utils::coord(657) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(387) * scale, Utils::coord(669) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(383) * scale, Utils::coord(678) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(378) * scale, Utils::coord(690) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(375) * scale, Utils::coord(701) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(373) * scale, Utils::coord(713) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(370) * scale, Utils::coord(724) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(369) * scale, Utils::coord(738) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(369) * scale, Utils::coord(752) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(764) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(779) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(792) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(805) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * scale, Utils::coord(819) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(364) * scale, Utils::coord(832) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(359) * scale, Utils::coord(845) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(354) * scale, Utils::coord(857) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(349) * scale, Utils::coord(870) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(345) * scale, Utils::coord(882) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(340) * scale, Utils::coord(895) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(335) * scale, Utils::coord(908) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(331) * scale, Utils::coord(922) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(329) * scale, Utils::coord(934) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(329) * scale, Utils::coord(947) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(333) * scale, Utils::coord(960) * scale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * scale, Utils::coord(996) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(401) * scale, Utils::coord(999) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(413) * scale, Utils::coord(1004) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(424) * scale, Utils::coord(1010) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(436) * scale, Utils::coord(1015) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(447) * scale, Utils::coord(1020) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(458) * scale, Utils::coord(1024) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(468) * scale, Utils::coord(1032) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(472) * scale, Utils::coord(1045) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(478) * scale, Utils::coord(1054) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(484) * scale, Utils::coord(1063) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * scale, Utils::coord(1074) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(489) * scale, Utils::coord(1086) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(488) * scale, Utils::coord(1098) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * scale, Utils::coord(1110) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * scale, Utils::coord(1121) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * scale, Utils::coord(1134) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(496) * scale, Utils::coord(1144) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(505) * scale, Utils::coord(1152) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(513) * scale, Utils::coord(1161) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(520) * scale, Utils::coord(1171) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(528) * scale, Utils::coord(1182) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(533) * scale, Utils::coord(1193) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(539) * scale, Utils::coord(1203) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(543) * scale, Utils::coord(1215) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(546) * scale, Utils::coord(1227) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(544) * scale, Utils::coord(1239) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(543) * scale, Utils::coord(1252) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(544) * scale, Utils::coord(1265) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(540) * scale, Utils::coord(1275) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(533) * scale, Utils::coord(1286) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(523) * scale, Utils::coord(1295) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(511) * scale, Utils::coord(1295) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(497) * scale, Utils::coord(1296) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(485) * scale, Utils::coord(1300) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(474) * scale, Utils::coord(1303) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(463) * scale, Utils::coord(1306) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(451) * scale, Utils::coord(1308) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(438) * scale, Utils::coord(1308) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(426) * scale, Utils::coord(1309) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(414) * scale, Utils::coord(1311) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(402) * scale, Utils::coord(1314) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(389) * scale, Utils::coord(1316) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(377) * scale, Utils::coord(1319) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(366) * scale, Utils::coord(1323) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(355) * scale, Utils::coord(1326) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(344) * scale, Utils::coord(1330) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(333) * scale, Utils::coord(1335) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(322) * scale, Utils::coord(1340) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(312) * scale, Utils::coord(1345) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(303) * scale, Utils::coord(1353) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(293) * scale, Utils::coord(1359) * scale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(286) * scale, Utils::coord(1367) * scale);

        this->mUnlockText[0]->removeFromParent();
        this->mStarsText[0]->removeFromParent();
	}

Episodes* Episodes::create()
{
    Episodes* screen = new Episodes();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Episodes::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MORE_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);

                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Episodes::onEnter()
{
    Screen::onEnter();
    
    this->mDarkLayers[0]->setVisible(false);
    
    this->mEpisodes[1]->setRegisterAsTouchable(false);
    this->mEpisodes[2]->setRegisterAsTouchable(false);
    this->mEpisodes[3]->setRegisterAsTouchable(false);
    this->mEpisodes[4]->setRegisterAsTouchable(false);
}

void Episodes::onExit()
{
    Screen::onExit();
}

#endif