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
	mc->SetMass(1.0f);
	mc->SetDamper(0.999f);
	mc->SetAcceleration(Vector2(0.0f, 0.0f));
	mc->SetMaxVelocity(150.0f);
	mc->SetVelocity(Vector2(Random::GetFloatRange(-150.0f, 150.0f), Random::GetFloatRange(-150.0f, 150.0f)));
	mc->SetAngularSpeed(Random::GetFloatRange(0.0f, Math::TwoPi));


	mCircle = new CircleComponent(this);
	mCircle->SetRadius(25.0f);

	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}