#include "Ship.h"
#include "AnimateSpriteComponent.h"
#include <vector>
#include "Game.h"
#include <iostream>
#include "InputComponent.h"
#include "Laser.h"
Ship::Ship(Game* game) : Actor(game)
						,mLaserCooldown(0.0f)
{
	// create animated sprite component
	AnimateSpriteComponent* shipAsc = new AnimateSpriteComponent(this);
	std::vector<SDL_Texture*> shipAnims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png")
	};
	SetPosition(Vector2(512.0f, 384.0f));
	shipAsc->SetAnimFPS(24.0f);
	shipAsc->SetAnimationTextures(shipAnims, "ship", true);
	shipAsc->SetCurrentAnimation("ship");
	
	InputComponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	ic->SetBackKey(SDL_SCANCODE_S);
	ic->SetClockwiseKey(SDL_SCANCODE_A);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_D);
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;
	
}

void Ship::ActorInput(const uint8_t* keyState)
{
	
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f)
	{
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());
		mLaserCooldown = 0.5;
	}
}

