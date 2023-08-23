#include "Laser.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"
#include "MoveComponent.h"
#include "Asteroid.h"
#include <iostream>
#include "Actor.h"
Laser::Laser(Game* game, Vector2 forward) : Actor(game) 
						   ,mLaserLife(1.0f)				
{
	// add sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->setTexture(game->GetTexture("Assets/Laser.png"));

	// add circle component
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);

	// add move component
	MoveComponent* mc = new MoveComponent(this);
	mc->SetAcceleration(Vector2(0.0f, 0.0f));
	mc->SetDamper(0.9999f);
	mc->SetMass(0.1f);
	mc->SetMaxVelocity(800.0f);
	mc->SetVelocity(forward * 800.0f);
}

void Laser::UpdateActor(float deltaTime)
{
	// If we run out of time, laser is dead
	mLaserLife -= deltaTime;
	
	if (mLaserLife <= 0.0f)
	{
		SetState(EDead);
	}
	else
	{
		// Do we intersect with an asteroid?
		for (auto ast : GetGame()->GetAsteroids())
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				// The first asteroid we intersect with,
				// set ourselves and the asteroid to dead
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}
}
