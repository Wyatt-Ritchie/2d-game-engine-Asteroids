#include "Asteroid.h"
#include "Random.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleComponent.h"
#include "Actor.h"
#include <iostream>

Asteroid::Asteroid(Game* game) : Actor(game)
{
	// initialize to random position/orientation
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));

	SetPosition(randPos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	// Create sprite component and set texture
	SpriteComponent* sc = new SpriteComponent(this);
	sc->setTexture(game->GetTexture("Assets/Asteroid.png"));

	// create a move component
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}