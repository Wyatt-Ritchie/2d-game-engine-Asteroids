#include "SpriteComponent.h"
#include "Game.h"
#include "Actor.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder) :Component(owner),
															   mDrawOrder(drawOrder),
															   mTexture(nullptr),
															   mTexWidth(0),
															   mTexHeight(0)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		SDL_Rect r;

		// Scale the width and height by owner scale
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale());
		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

		// Draw
		SDL_RenderCopyEx(renderer,
			mTexture,
			nullptr,
			&r,
			-Math::ToDegrees(mOwner->GetRoation()),
			nullptr,
			SDL_FLIP_NONE);
	}
}

void SpriteComponent::setTexture(SDL_Texture* texture)
{
	mTexture = texture;

	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}