#include "Ship.h"
#include "AnimateSpriteComponent.h"
#include <vector>
#include "Game.h"
#include <iostream>
#include "TileMapComponent.h"
Ship::Ship(Game* game) : Actor(game)
						, mRightSpeed(0.0f)
						, mDownSpeed(0.0f)
{
	// create animated sprite component
	AnimateSpriteComponent* shipAsc = new AnimateSpriteComponent(this);
	std::vector<SDL_Texture*> shipAnims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png")
	};
	shipAsc->SetAnimFPS(24.0f);
	shipAsc->SetAnimationTextures(shipAnims, "ship", true);
	shipAsc->SetCurrentAnimation("ship");

	std::vector<SDL_Texture*> walkAnims = {
		game->GetTexture("Assets/Character01.png"),
		game->GetTexture("Assets/Character02.png"),
		game->GetTexture("Assets/Character03.png"),
		game->GetTexture("Assets/Character04.png"),
		game->GetTexture("Assets/Character05.png"),
		game->GetTexture("Assets/Character06.png")
	};
	
	shipAsc->SetAnimationTextures(walkAnims, "walk", true);

	std::vector<SDL_Texture*> punchAnims = {
		game->GetTexture("Assets/Character16.png"),
		game->GetTexture("Assets/Character17.png"),
		game->GetTexture("Assets/Character18.png")
	};

	shipAsc->SetAnimationTextures(punchAnims, "punch", false);

	TileMapComponent* tileMap = new TileMapComponent(this, 50);
}

void Ship::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}

void Ship::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}

}
