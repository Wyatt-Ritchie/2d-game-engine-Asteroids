#pragma once
#include "Actor.h"
class Laser : public Actor
{
public:

	Laser(class Game* game, Vector2 forward);
	void UpdateActor(float deltaTime) override;
	

private:
	class CircleComponent* mCircle;
	float mLaserLife;
};

