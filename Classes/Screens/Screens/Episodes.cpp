#ifndef CONST_EPISODES
#define CONST_EPISODES

#include "Episodes.h"

#include "Levels.h"
#include "Mode.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Episodes::ACTION = -1;

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
        this->mScale = Options::CAMERA_CENTER_X / Utils::coord(360);
        float shift = abs(Options::CAMERA_HEIGHT - (((Utils::coord(400) * this->mScale) * 2) + (Utils::coord(480) * this->mScale) * 2)) + Utils::coord(200) * this->mScale;
        
        CCLayer* sc = CCLayer::create();
        sc->setContentSize(CCSize(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT + shift));
        
        this->mScroll = CCScrollView::create(CCSize(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT), sc);
        this->mScroll->setBounceable(false);
        this->mScroll->setDirection(cocos2d::extension::kCCScrollViewDirectionVertical);
        
        this->addChild(this->mScroll);
        
        this->mComingSoon = CCLayerColor::create(ccc4(20, 20, 20, 255));
        this->mComingSoon->setContentSize(CCSize(Utils::coord(720) * this->mScale, Utils::coord(480) * this->mScale));
        this->mComingSoon->ignoreAnchorPointForPosition(false);

		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas18");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas18");
        spriteBatch2->setPosition(ccp(0, Utils::coord(200) * this->mScale));

        this->mScroll->addChild(spriteBatch);
        this->mScroll->addChild(spriteBatch2, 3);
        
        this->mScroll->addChild(this->mComingSoon, 2);
        
        for(int i = 0; i < 5; i++)
        {
            this->mDarkLayers[i] = CCLayerColor::create(ccc4(0, 0, 0, 180));
            
            if(i == 4)
            {
                this->mDarkLayers[i]->setContentSize(CCSize(Utils::coord(720) * this->mScale, Utils::coord(480) * this->mScale));
            }
            else
            {
                this->mDarkLayers[i]->setContentSize(CCSize(Utils::coord(360) * this->mScale, Utils::coord(400) * this->mScale));
            }
            
            this->mDarkLayers[i]->ignoreAnchorPointForPosition(false);
            this->mScroll->addChild(this->mDarkLayers[i], 2);
        }

		EntityStructure structure1 = {"progress_map_episode1@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure2 = {"progress_map_episode2@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure3 = {"progress_map_episode3@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure4 = {"progress_map_episode4@2x.png", 1, 1, 0, 0, 360, 400};
		EntityStructure structure5 = {"progress_map_episode5@2x.png", 1, 1, 0, 0, 720, 480};
		EntityStructure structure6 = {"progress_map_fbconnect@2x.png", 1, 1, 0, 0, 361, 200};
		EntityStructure structure7 = {"progress_map_gplus_share@2x.png", 1, 1, 0, 0, 180, 100};
		EntityStructure structure8 = {"progress_map_vk_share@2x.png", 1, 1, 0, 0, 180, 100};
		EntityStructure structure9 = {"progress_map_tw_share@2x.png", 1, 1, 0, 0, 180, 100};
		EntityStructure structure10 = {"progress_map_fb_share@2x.png", 1, 1, 0, 0, 180, 100};

		this->mEpisodes[0] = Button::create(structure1, spriteBatch, Options::BUTTONS_EPISODE_1, this);
		this->mEpisodes[1] = Button::create(structure2, spriteBatch, Options::BUTTONS_EPISODE_2, this);
		this->mEpisodes[2] = Button::create(structure3, spriteBatch, Options::BUTTONS_EPISODE_3, this);
		this->mEpisodes[3] = Button::create(structure4, spriteBatch, Options::BUTTONS_EPISODE_4, this);
		this->mEpisodes[4] = Button::create(structure5, spriteBatch, Options::BUTTONS_EPISODE_5, this);
		this->mEpisodes[5] = Button::create(structure6, this->mScroll, Options::BUTTONS_EPISODE_FACEBOOK_CONNECT, this);
		this->mEpisodes[6] = Button::create(structure7, spriteBatch, Options::BUTTONS_EPISODE_GOOGLE_PLUS, this);
		this->mEpisodes[7] = Button::create(structure8, spriteBatch, Options::BUTTONS_EPISODE_VK, this);
		this->mEpisodes[8] = Button::create(structure9, spriteBatch, Options::BUTTONS_EPISODE_TWITTER, this);
		this->mEpisodes[9] = Button::create(structure10, spriteBatch, Options::BUTTONS_EPISODE_FACEBOOK, this);
        
        this->mShareIcon = Entity::create("progress_map_share_ico@2x.png", spriteBatch);
        this->mShareIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Options::CAMERA_CENTER_X / 2, Utils::coord(100) * this->mScale);
        
		this->mEpisodes[0]->setScale(this->mScale);
		this->mEpisodes[1]->setScale(this->mScale);
		this->mEpisodes[2]->setScale(this->mScale);
		this->mEpisodes[3]->setScale(this->mScale);
		this->mEpisodes[4]->setScale(this->mScale);
		this->mEpisodes[5]->setScale(this->mScale);
		this->mEpisodes[6]->setScale(this->mScale);
		this->mEpisodes[7]->setScale(this->mScale);
		this->mEpisodes[8]->setScale(this->mScale);
		this->mEpisodes[9]->setScale(this->mScale);

		this->mEpisodes[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mEpisodes[0]->getWidthScaled() / 2, this->mEpisodes[0]->getHeightScaled() / 2 + Utils::coord(200) * this->mScale);
		this->mEpisodes[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[1]->getWidthScaled() / 2, this->mEpisodes[1]->getHeightScaled() / 2 + Utils::coord(200) * this->mScale);
		this->mEpisodes[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mEpisodes[2]->getWidthScaled() / 2, this->mEpisodes[0]->getCenterY() + this->mEpisodes[2]->getHeightScaled());
		this->mEpisodes[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[3]->getWidthScaled() / 2, this->mEpisodes[1]->getCenterY() + this->mEpisodes[3]->getHeightScaled());
		this->mEpisodes[4]->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mEpisodes[3]->getCenterY() + this->mEpisodes[3]->getHeightScaled() / 2 + this->mEpisodes[4]->getHeightScaled() / 2);
		this->mEpisodes[5]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mEpisodes[0]->getWidthScaled() / 2, this->mEpisodes[0]->getHeightScaled() / 2 - this->mEpisodes[5]->getHeightScaled() / 2);
		this->mEpisodes[6]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[1]->getWidthScaled() / 2 - this->mEpisodes[6]->getWidthScaled() / 2, this->mEpisodes[1]->getHeightScaled() / 2 - this->mEpisodes[6]->getHeightScaled() / 2);
		this->mEpisodes[7]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[1]->getWidthScaled() / 2 + this->mEpisodes[7]->getWidthScaled() / 2, this->mEpisodes[1]->getHeightScaled() / 2 - this->mEpisodes[7]->getHeightScaled() / 2);
		this->mEpisodes[8]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[1]->getWidthScaled() / 2 - this->mEpisodes[8]->getWidthScaled() / 2, this->mEpisodes[1]->getHeightScaled() / 2 - this->mEpisodes[8]->getHeightScaled() * 1.5);
		this->mEpisodes[9]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mEpisodes[1]->getWidthScaled() / 2 + this->mEpisodes[9]->getWidthScaled() / 2, this->mEpisodes[1]->getHeightScaled() / 2 - this->mEpisodes[9]->getHeightScaled() * 1.5);
        this->mComingSoon->setPosition(ccp(Options::CAMERA_CENTER_X - this->mComingSoon->getContentSize().width / 2, this->mEpisodes[4]->getCenterY() + this->mEpisodes[4]->getHeightScaled() / 2));
        
        this->mPoints = EntityManager::create(6, Entity::create("progress_map_point_sprite@2x.png", 1, 2), spriteBatch2);
        this->mStars = EntityManager::create(6, Entity::create("end_lvl_star_sprite@2x.png", 3, 2), this->mScroll, 3);
        this->mDots = EntityManager::create(200, Entity::create("progress_map_dot@2x.png"), spriteBatch2, 3);

        this->mPoints->create()->setCenterPosition(Utils::coord(211) * this->mScale, Utils::coord(103) * this->mScale);
        this->mPoints->create()->setCenterPosition(Utils::coord(498) * this->mScale, Utils::coord(77) * this->mScale);
        this->mPoints->create()->setCenterPosition(Utils::coord(166) * this->mScale, Utils::coord(487) * this->mScale);
        this->mPoints->create()->setCenterPosition(Utils::coord(588) * this->mScale, Utils::coord(538) * this->mScale);
        this->mPoints->create()->setCenterPosition(Utils::coord(360) * this->mScale, Utils::coord(980) * this->mScale);
        this->mPoints->create()->setCenterPosition(Utils::coord(266) * this->mScale, Utils::coord(1391) * this->mScale);
        
        static_cast<Entity*>(this->mPoints->objectAtIndex(0))->setCurrentFrameIndex(1);
        
        this->mDarkLayers[0]->setPosition(ccp(this->mEpisodes[0]->getCenterX() - this->mEpisodes[0]->getWidthScaled() / 2, this->mEpisodes[0]->getCenterY() - this->mEpisodes[0]->getHeightScaled() / 2));
        this->mDarkLayers[1]->setPosition(ccp(this->mEpisodes[1]->getCenterX() - this->mEpisodes[1]->getWidthScaled() / 2, this->mEpisodes[1]->getCenterY() - this->mEpisodes[1]->getHeightScaled() / 2));
        this->mDarkLayers[2]->setPosition(ccp(this->mEpisodes[2]->getCenterX() - this->mEpisodes[2]->getWidthScaled() / 2, this->mEpisodes[2]->getCenterY() - this->mEpisodes[2]->getHeightScaled() / 2));
        this->mDarkLayers[3]->setPosition(ccp(this->mEpisodes[3]->getCenterX() - this->mEpisodes[3]->getWidthScaled() / 2, this->mEpisodes[3]->getCenterY() - this->mEpisodes[3]->getHeightScaled() / 2));
        this->mDarkLayers[4]->setPosition(ccp(this->mEpisodes[4]->getCenterX() - this->mEpisodes[4]->getWidthScaled() / 2, this->mEpisodes[4]->getCenterY() - this->mEpisodes[4]->getHeightScaled() / 2));
        
        this->mEpisodeText[0] = Text::create((Textes) {Options::TEXT_LEVELS_EPISODE.string, Options::FONT, 48, -1}, this->mScroll);
        this->mEpisodeText[1] = Text::create((Textes) {Options::TEXT_LEVELS_EPISODE.string, Options::FONT, 48, -1}, this->mScroll);
        this->mEpisodeText[2] = Text::create((Textes) {Options::TEXT_LEVELS_EPISODE.string, Options::FONT, 48, -1}, this->mScroll);
        this->mEpisodeText[3] = Text::create((Textes) {Options::TEXT_LEVELS_EPISODE.string, Options::FONT, 48, -1}, this->mScroll);
        this->mEpisodeText[4] = Text::create((Textes) {Options::TEXT_LEVELS_EPISODE.string, Options::FONT, 48, -1}, this->mScroll);
        this->mEpisodeText[5] = Text::create((Textes) {Options::TEXT_LEVELS_EPISODE.string, Options::FONT, 48, -1}, this->mScroll);
        
        this->mEpisodeText[0]->setZOrder(3);
        this->mEpisodeText[1]->setZOrder(3);
        this->mEpisodeText[2]->setZOrder(3);
        this->mEpisodeText[3]->setZOrder(3);
        this->mEpisodeText[4]->setZOrder(3);
        this->mEpisodeText[5]->setZOrder(3);
        
        this->mEpisodeNameText[0] = Text::create(Options::TEXT_EPISODES_NAMES[0], this->mScroll);
        this->mEpisodeNameText[1] = Text::create(Options::TEXT_EPISODES_NAMES[1], this->mScroll);
        this->mEpisodeNameText[2] = Text::create(Options::TEXT_EPISODES_NAMES[2], this->mScroll);
        this->mEpisodeNameText[3] = Text::create(Options::TEXT_EPISODES_NAMES[3], this->mScroll);
        this->mEpisodeNameText[4] = Text::create(Options::TEXT_EPISODES_NAMES[4], this->mScroll);
        this->mEpisodeNameText[5] = Text::create(Options::TEXT_EPISODES_NAMES[5], this->mScroll);
        
        this->mEpisodeNameText[0]->setZOrder(3);
        this->mEpisodeNameText[1]->setZOrder(3);
        this->mEpisodeNameText[2]->setZOrder(3);
        this->mEpisodeNameText[3]->setZOrder(3);
        this->mEpisodeNameText[4]->setZOrder(3);
        this->mEpisodeNameText[5]->setZOrder(3);
        
        this->mStarsText[0] = Text::create((Textes) {"0", Options::FONT, 38, -1}, this->mScroll);
        this->mStarsText[1] = Text::create((Textes) {"0", Options::FONT, 38, -1}, this->mScroll);
        this->mStarsText[2] = Text::create((Textes) {"0", Options::FONT, 38, -1}, this->mScroll);
        this->mStarsText[3] = Text::create((Textes) {"0", Options::FONT, 38, -1}, this->mScroll);
        this->mStarsText[4] = Text::create((Textes) {"0", Options::FONT, 38, -1}, this->mScroll);
        this->mStarsText[5] = Text::create((Textes) {"0", Options::FONT, 38, -1}, this->mScroll);
        
        this->mUnlockText[0] = Text::create(Options::TEXT_NEED_TO_UNLOCK, this->mScroll);
        this->mUnlockText[1] = Text::create(Options::TEXT_NEED_TO_UNLOCK, this->mScroll);
        this->mUnlockText[2] = Text::create(Options::TEXT_NEED_TO_UNLOCK, this->mScroll);
        this->mUnlockText[3] = Text::create(Options::TEXT_NEED_TO_UNLOCK, this->mScroll);
        this->mUnlockText[4] = Text::create(Options::TEXT_NEED_TO_UNLOCK, this->mScroll);
        this->mUnlockText[5] = Text::create(Options::TEXT_NEED_TO_UNLOCK, this->mScroll);
        
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
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(245) * this->mScale, Utils::coord(108) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(260) * this->mScale, Utils::coord(111) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(274) * this->mScale, Utils::coord(113) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(292) * this->mScale, Utils::coord(114) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(308) * this->mScale, Utils::coord(111) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(322) * this->mScale, Utils::coord(105) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(336) * this->mScale, Utils::coord(100) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(349) * this->mScale, Utils::coord(95) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(363) * this->mScale, Utils::coord(92) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(377) * this->mScale, Utils::coord(90) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * this->mScale, Utils::coord(85) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(404) * this->mScale, Utils::coord(83) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(418) * this->mScale, Utils::coord(81) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(431) * this->mScale, Utils::coord(81) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(444) * this->mScale, Utils::coord(76) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(460) * this->mScale, Utils::coord(73) * this->mScale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(498) * this->mScale, Utils::coord(112) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(488) * this->mScale, Utils::coord(128) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(478) * this->mScale, Utils::coord(139) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(468) * this->mScale, Utils::coord(150) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(457) * this->mScale, Utils::coord(159) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(444) * this->mScale, Utils::coord(169) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(433) * this->mScale, Utils::coord(178) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(422) * this->mScale, Utils::coord(190) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(409) * this->mScale, Utils::coord(199) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(399) * this->mScale, Utils::coord(210) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * this->mScale, Utils::coord(222) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(385) * this->mScale, Utils::coord(234) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(377) * this->mScale, Utils::coord(245) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(373) * this->mScale, Utils::coord(259) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(271) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(363) * this->mScale, Utils::coord(283) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(357) * this->mScale, Utils::coord(296) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(351) * this->mScale, Utils::coord(308) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(346) * this->mScale, Utils::coord(319) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(342) * this->mScale, Utils::coord(331) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(337) * this->mScale, Utils::coord(345) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(332) * this->mScale, Utils::coord(356) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(328) * this->mScale, Utils::coord(368) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(323) * this->mScale, Utils::coord(380) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(316) * this->mScale, Utils::coord(392) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(303) * this->mScale, Utils::coord(400) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(292) * this->mScale, Utils::coord(408) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(278) * this->mScale, Utils::coord(412) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(263) * this->mScale, Utils::coord(419) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(249) * this->mScale, Utils::coord(423) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(236) * this->mScale, Utils::coord(428) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(225) * this->mScale, Utils::coord(435) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(213) * this->mScale, Utils::coord(440) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(202) * this->mScale, Utils::coord(444) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(192) * this->mScale, Utils::coord(449) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(180) * this->mScale, Utils::coord(457) * this->mScale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(189) * this->mScale, Utils::coord(512) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(202) * this->mScale, Utils::coord(515) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(215) * this->mScale, Utils::coord(515) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(229) * this->mScale, Utils::coord(515) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(242) * this->mScale, Utils::coord(517) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(253) * this->mScale, Utils::coord(522) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(266) * this->mScale, Utils::coord(526) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(278) * this->mScale, Utils::coord(526) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(292) * this->mScale, Utils::coord(526) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(304) * this->mScale, Utils::coord(527) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(317) * this->mScale, Utils::coord(526) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(329) * this->mScale, Utils::coord(522) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(342) * this->mScale, Utils::coord(522) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(354) * this->mScale, Utils::coord(521) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(522) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(378) * this->mScale, Utils::coord(520) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * this->mScale, Utils::coord(516) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(404) * this->mScale, Utils::coord(515) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(416) * this->mScale, Utils::coord(512) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(428) * this->mScale, Utils::coord(510) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(442) * this->mScale, Utils::coord(507) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(454) * this->mScale, Utils::coord(501) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(465) * this->mScale, Utils::coord(496) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(481) * this->mScale, Utils::coord(491) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(494) * this->mScale, Utils::coord(489) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(509) * this->mScale, Utils::coord(487) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(524) * this->mScale, Utils::coord(486) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(538) * this->mScale, Utils::coord(489) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(553) * this->mScale, Utils::coord(496) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(565) * this->mScale, Utils::coord(507) * this->mScale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(560) * this->mScale, Utils::coord(553) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(548) * this->mScale, Utils::coord(558) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(535) * this->mScale, Utils::coord(562) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(524) * this->mScale, Utils::coord(567) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(513) * this->mScale, Utils::coord(572) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(501) * this->mScale, Utils::coord(575) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(488) * this->mScale, Utils::coord(576) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(476) * this->mScale, Utils::coord(579) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(465) * this->mScale, Utils::coord(583) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(454) * this->mScale, Utils::coord(590) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(444) * this->mScale, Utils::coord(597) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(433) * this->mScale, Utils::coord(605) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(424) * this->mScale, Utils::coord(616) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(414) * this->mScale, Utils::coord(625) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(408) * this->mScale, Utils::coord(635) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(402) * this->mScale, Utils::coord(646) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(395) * this->mScale, Utils::coord(657) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(387) * this->mScale, Utils::coord(669) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(383) * this->mScale, Utils::coord(678) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(378) * this->mScale, Utils::coord(690) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(375) * this->mScale, Utils::coord(701) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(373) * this->mScale, Utils::coord(713) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(370) * this->mScale, Utils::coord(724) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(369) * this->mScale, Utils::coord(738) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(369) * this->mScale, Utils::coord(752) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(764) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(779) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(792) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(805) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(368) * this->mScale, Utils::coord(819) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(364) * this->mScale, Utils::coord(832) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(359) * this->mScale, Utils::coord(845) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(354) * this->mScale, Utils::coord(857) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(349) * this->mScale, Utils::coord(870) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(345) * this->mScale, Utils::coord(882) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(340) * this->mScale, Utils::coord(895) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(335) * this->mScale, Utils::coord(908) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(331) * this->mScale, Utils::coord(922) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(329) * this->mScale, Utils::coord(934) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(329) * this->mScale, Utils::coord(947) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(333) * this->mScale, Utils::coord(960) * this->mScale);
        
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(390) * this->mScale, Utils::coord(996) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(401) * this->mScale, Utils::coord(999) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(413) * this->mScale, Utils::coord(1004) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(424) * this->mScale, Utils::coord(1010) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(436) * this->mScale, Utils::coord(1015) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(447) * this->mScale, Utils::coord(1020) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(458) * this->mScale, Utils::coord(1024) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(468) * this->mScale, Utils::coord(1032) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(472) * this->mScale, Utils::coord(1045) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(478) * this->mScale, Utils::coord(1054) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(484) * this->mScale, Utils::coord(1063) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * this->mScale, Utils::coord(1074) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(489) * this->mScale, Utils::coord(1086) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(488) * this->mScale, Utils::coord(1098) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * this->mScale, Utils::coord(1110) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * this->mScale, Utils::coord(1121) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(490) * this->mScale, Utils::coord(1134) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(496) * this->mScale, Utils::coord(1144) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(505) * this->mScale, Utils::coord(1152) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(513) * this->mScale, Utils::coord(1161) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(520) * this->mScale, Utils::coord(1171) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(528) * this->mScale, Utils::coord(1182) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(533) * this->mScale, Utils::coord(1193) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(539) * this->mScale, Utils::coord(1203) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(543) * this->mScale, Utils::coord(1215) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(546) * this->mScale, Utils::coord(1227) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(544) * this->mScale, Utils::coord(1239) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(543) * this->mScale, Utils::coord(1252) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(544) * this->mScale, Utils::coord(1265) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(540) * this->mScale, Utils::coord(1275) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(533) * this->mScale, Utils::coord(1286) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(523) * this->mScale, Utils::coord(1295) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(511) * this->mScale, Utils::coord(1295) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(497) * this->mScale, Utils::coord(1296) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(485) * this->mScale, Utils::coord(1300) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(474) * this->mScale, Utils::coord(1303) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(463) * this->mScale, Utils::coord(1306) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(451) * this->mScale, Utils::coord(1308) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(438) * this->mScale, Utils::coord(1308) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(426) * this->mScale, Utils::coord(1309) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(414) * this->mScale, Utils::coord(1311) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(402) * this->mScale, Utils::coord(1314) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(389) * this->mScale, Utils::coord(1316) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(377) * this->mScale, Utils::coord(1319) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(366) * this->mScale, Utils::coord(1323) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(355) * this->mScale, Utils::coord(1326) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(344) * this->mScale, Utils::coord(1330) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(333) * this->mScale, Utils::coord(1335) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(322) * this->mScale, Utils::coord(1340) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(312) * this->mScale, Utils::coord(1345) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(303) * this->mScale, Utils::coord(1353) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(293) * this->mScale, Utils::coord(1359) * this->mScale);
        static_cast<Entity*>(this->mDots->create())->setCenterPosition(Utils::coord(286) * this->mScale, Utils::coord(1367) * this->mScale);
        
        this->mPersonage = Entity::create("progress_map_fbico@2x.png", spriteBatch2);
        this->mPersonage->create()->setZOrder(3);
        
        Text* t = Text::create((Textes) {"?", Options::FONT, 38, -1}, this->mScroll);
        t->setCenterPosition(static_cast<Entity*>(this->mPoints->objectAtIndex(5))->getCenterX() - t->getWidth() / 2, static_cast<Entity*>(this->mPoints->objectAtIndex(5))->getCenterY() - t->getHeight() / 2 + Utils::coord(200) * this->mScale);
        t->setZOrder(3);
        
        this->mFacebookText[0] = Text::create((Textes) {"Connect\nwith Facebook", Options::FONT, 32, -1}, this->mEpisodes[5]);
        this->mFacebookText[1] = Text::create((Textes) {"play with friends", Options::FONT, 22, -1}, this->mEpisodes[5]);
        this->mFacebookText[0]->setCenterPosition(this->mEpisodes[5]->getWidth() / 2 + Utils::coord(60), this->mEpisodes[5]->getHeight() / 2 + Utils::coord(30));
        this->mFacebookText[1]->setCenterPosition(this->mEpisodes[5]->getWidth() / 2 + Utils::coord(60), this->mEpisodes[5]->getHeight() / 2 - Utils::coord(60));
        this->mFacebookText[0]->setZOrder(3);
        this->mFacebookText[1]->setZOrder(3);
        
        this->mPointsAnimationRunning = false;
        
        AppDelegate::clearCache();
	}

Episodes* Episodes::create()
{
    Episodes* screen = new Episodes();
    screen->autorelease();
    
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
                case Options::BUTTONS_EPISODE_1:
                    
                ACTION = 1;

                AppDelegate::screens->set(Levels::create());

                break;
                case Options::BUTTONS_EPISODE_2:
                    
                ACTION = 2;
                    
                AppDelegate::screens->set(Levels::create());
                    
                break;
                case Options::BUTTONS_EPISODE_3:
                    
                ACTION = 3;
                    
                AppDelegate::screens->set(Levels::create());
                    
                break;
                case Options::BUTTONS_EPISODE_4:
                    
                ACTION = 4;
                    
                AppDelegate::screens->set(Levels::create());
                    
                break;
                case Options::BUTTONS_EPISODE_5:
                    
                ACTION = 5;
                    
                AppDelegate::screens->set(Levels::create());
                    
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

void Episodes::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    for(int i = 0; i < this->mPoints->getCount(); i++)
    {
        Entity* point = static_cast<Entity*>(this->mPoints->objectAtIndex(i));
        
        point->setRotation(point->getRotation() + 1.0);
    }
    
    if(this->mPointsAnimationRunning)
    {
        this->mPointsAnimationTimeElapsed += pDeltaTime;
        
        if(this->mPointsAnimationTimeElapsed >= 0.02)
        {
            this->mPointsAnimationTimeElapsed = 0;
            
            static_cast<Entity*>(this->mDots->objectAtIndex(this->mPointsAnimationCounter--))->setVisible(true);
            //this->mPersonage->runAction(CCMoveTo::create(0.02, ccp(static_cast<Entity*>(this->mDots->objectAtIndex(this->mPointsAnimationCounter))->getPosition().x, static_cast<Entity*>(this->mDots->objectAtIndex(this->mPointsAnimationCounter--))->getPosition().y + this->mPersonage->getHeight() / 2)));
        
            if(this->mPointsAnimationCounter <= 0)
            {
                this->mPointsAnimationRunning = false;
            }
            else
            {
                switch(this->mPointsAnimationCounter)
                {
                    case 170:
                    static_cast<Entity*>(this->mPoints->objectAtIndex(5))->runAction(CCSequence::create(CCScaleTo::create(0.1, 1.3), CCScaleTo::create(0.1, 1.0), NULL));
                    break;
                    case 123:
                    static_cast<Entity*>(this->mPoints->objectAtIndex(4))->runAction(CCSequence::create(CCScaleTo::create(0.1, 1.3), CCScaleTo::create(0.1, 1.0), NULL));
                    break;
                    case 82:
                    static_cast<Entity*>(this->mPoints->objectAtIndex(3))->runAction(CCSequence::create(CCScaleTo::create(0.1, 1.3), CCScaleTo::create(0.1, 1.0), NULL));
                    break;
                    case 52:
                    static_cast<Entity*>(this->mPoints->objectAtIndex(2))->runAction(CCSequence::create(CCScaleTo::create(0.1, 1.3), CCScaleTo::create(0.1, 1.0), NULL));
                    break;
                    case 16:
                    static_cast<Entity*>(this->mPoints->objectAtIndex(1))->runAction(CCSequence::create(CCScaleTo::create(0.1, 1.3), CCScaleTo::create(0.1, 1.0), NULL));
                    break;
                    case 1:
                    static_cast<Entity*>(this->mPoints->objectAtIndex(0))->runAction(CCSequence::create(CCScaleTo::create(0.1, 1.3), CCScaleTo::create(0.1, 1.0), NULL));
                    break;
                        
                        // SOund
                }
            }
        }
    }
}

void Episodes::onEnter()
{
    Screen::onEnter();

    int totalStars = AppDelegate::getLevelStarsTotalCount();
    
    if(true) {                           this->mDarkLayers[0]->setVisible(false); this->mUnlockText[0]->setVisible(false); this->mStarsText[0]->setVisible(false); }
    if(totalStars >= Levels::STARS[1]) { this->mDarkLayers[1]->setVisible(false); this->mUnlockText[1]->setVisible(false); this->mStarsText[1]->setVisible(false); } else { this->mDarkLayers[1]->setVisible(true); this->mUnlockText[1]->setVisible(true); this->mStarsText[1]->setVisible(true); }
    if(totalStars >= Levels::STARS[2]) { this->mDarkLayers[2]->setVisible(false); this->mUnlockText[2]->setVisible(false); this->mStarsText[2]->setVisible(false); } else { this->mDarkLayers[2]->setVisible(true); this->mUnlockText[2]->setVisible(true); this->mStarsText[2]->setVisible(true); }
    if(totalStars >= Levels::STARS[3]) { this->mDarkLayers[3]->setVisible(false); this->mUnlockText[3]->setVisible(false); this->mStarsText[3]->setVisible(false); } else { this->mDarkLayers[3]->setVisible(true); this->mUnlockText[3]->setVisible(true); this->mStarsText[3]->setVisible(true); }
    if(totalStars >= Levels::STARS[4]) { this->mDarkLayers[4]->setVisible(false); this->mUnlockText[4]->setVisible(false); this->mStarsText[4]->setVisible(false); } else { this->mDarkLayers[4]->setVisible(true); this->mUnlockText[4]->setVisible(true); this->mStarsText[4]->setVisible(true); }

    if(this->mStarsText[0]) this->mStarsText[0]->setString(ccsf("%d", Levels::STARS[0] - totalStars));
    if(this->mStarsText[1]) this->mStarsText[1]->setString(ccsf("%d", Levels::STARS[1] - totalStars));
    if(this->mStarsText[2]) this->mStarsText[2]->setString(ccsf("%d", Levels::STARS[2] - totalStars));
    if(this->mStarsText[3]) this->mStarsText[3]->setString(ccsf("%d", Levels::STARS[3] - totalStars));
    if(this->mStarsText[4]) this->mStarsText[4]->setString(ccsf("%d", Levels::STARS[4] - totalStars));
    
    for(int i = 1; i < 6; i++)
    {
        this->mEpisodeText[i - 1]->setString(ccsf(Options::TEXT_LEVELS_EPISODE.string, i));
    }
    
    for(int i = 0; i < 6; i++)
    {
        if(i == 5)
        {
            float x = this->mComingSoon->getPosition().x;
            float y = this->mComingSoon->getPosition().y;
            float w = this->mComingSoon->getContentSize().width;
            float h = this->mComingSoon->getContentSize().height * this->mScale;
            
            this->mEpisodeText[i]->setVisible(false);
            this->mUnlockText[i]->setVisible(false);
            this->mStarsText[i]->setVisible(false);
            
            this->mEpisodeNameText[i]->setCenterPosition(x - this->mEpisodeNameText[i]->getWidth() / 2 + w / 2, y - this->mEpisodeNameText[i]->getHeight() / 2 + h / 2);
        }
        else
        {
            if(this->mEpisodeText[i]) this->mEpisodeText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mEpisodeText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(160) * this->mScale - this->mEpisodeText[i]->getHeight() / 2);
            if(this->mEpisodeNameText[i]) this->mEpisodeNameText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mEpisodeNameText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(110) * this->mScale - this->mEpisodeNameText[i]->getHeight() / 2);
            if(this->mUnlockText[i]) this->mUnlockText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mUnlockText[i]->getWidth() / 2, this->mEpisodes[i]->getCenterY() + Utils::coord(40) * this->mScale - this->mUnlockText[i]->getHeight() / 2);
            if(this->mStarsText[i]) this->mStarsText[i]->setCenterPosition(this->mEpisodes[i]->getCenterX() - this->mStarsText[i]->getWidth() / 2 + Utils::coord(20), this->mEpisodes[i]->getCenterY() + Utils::coord(40)  * this->mScale - this->mStarsText[i]->getHeight() / 2);
        }
    }
    
    for(int i = 1; i < 5; i++)
    {
        if(totalStars >= Levels::STARS[i]) continue;
        
        this->mStars->create()->setCenterPosition(this->mStarsText[i]->getCenterX() + this->mStarsText[i]->getWidth() / 2 - this->mStarsText[i]->getWidth() / 2 - Utils::coord(45), this->mStarsText[i]->getCenterY() + Utils::coord(7) * this->mScale);
        static_cast<Entity*>(this->mStars->objectAtIndex(this->mStars->getCount() - 1))->setCurrentFrameIndex(1);
        static_cast<Entity*>(this->mStars->objectAtIndex(this->mStars->getCount() - 1))->setScale(0.2);
    }
    
    float shift = abs(Options::CAMERA_HEIGHT - (((Utils::coord(400) * this->mScale) * 2) + (Utils::coord(480) * this->mScale) * 2));
    this->mScroll->getContainer()->setPosition(ccp(0, -shift));
    this->mScroll->getContainer()->runAction(CCMoveTo::create(0.02 * this->mDots->getCount(), ccp(0, 0)));
    
    for(int i = 0; i < this->mDots->getCount(); i++)
    {
        static_cast<Entity*>(this->mDots->objectAtIndex(i))->setVisible(false);
    }
    
    this->mPointsAnimationRunning = true;
    this->mPointsAnimationCounter = this->mDots->getCount() - 1;
    
    this->mPersonage->setCenterPosition(static_cast<Entity*>(this->mPoints->objectAtIndex(0))->getCenterX(), static_cast<Entity*>(this->mPoints->objectAtIndex(0))->getCenterY() + static_cast<Entity*>(this->mPoints->objectAtIndex(0))->getHeight() / 2 + Utils::coord(10) * this->mScale);
}

void Episodes::onExit()
{
    Screen::onExit();
    
    this->mStars->clear();
    
    this->mScroll->getContainer()->stopAllActions();
}

void Episodes::keyBackClicked()
{
    Screen::keyBackClicked();
    
    AppDelegate::screens->set(Mode::create());
}

#endif