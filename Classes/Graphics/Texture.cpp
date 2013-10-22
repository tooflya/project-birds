#ifndef CONST_TEXTURE
#define CONST_TEXTURE

#include "Texture.h"

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

Texture::Texture(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
	mTextureFileName(0),
	mTexture(0),
	mHorizontalFramesCount(0),
	mVerticalFramesCount(0)
	{
		this->mTexture = CCTextureCache::sharedTextureCache()->addImage(pszFileName);

		this->mTextureFileName = pszFileName;
            
		this->mHorizontalFramesCount = pHorizontalFramesCount;
		this->mVerticalFramesCount   = pVerticalFramesCount;
	}

// ===========================================================
// Methods
// ===========================================================

const char* Texture::getTextureFileName()
{
    return this->mTextureFileName;
}

CCTexture2D* Texture::getTexture()
{
    return this->mTexture;
}

int Texture::getHorizontalFramesCount()
{
    return this->mHorizontalFramesCount;
}

int Texture::getVerticalFramesCount()
{
    return this->mVerticalFramesCount;
}

// ===========================================================
// Override Methods
// ===========================================================

#endif