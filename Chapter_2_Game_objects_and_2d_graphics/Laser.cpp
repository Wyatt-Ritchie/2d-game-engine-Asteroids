#include "Laser.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"
#include "MoveComponent.h"
#include "Asteroid.h"
#include <iostream>

Laser::Laser(Game* game) : Actor(game) 
						 ,mLaserLife(1.0f)
{
	// add sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->setTexture(game->GetTexture("Assets/Laser.png"));
	std::cout << "spawn laser" << std::endl;

	// add circle component
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);

	// add move component
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(800.0f);
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
				std::cout << "Hit" << std::endl;
				// The first asteroid we intersect with,
				// set ourselves and the asteroid to dead
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}
}
