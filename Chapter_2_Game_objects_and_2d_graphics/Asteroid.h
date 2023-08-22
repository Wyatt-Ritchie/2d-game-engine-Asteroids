#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
	Asteroid(class Game* game);
	~Asteroid();

	void SetSpin(float spin) { mSpin = spin; }
	float GetSpin() const { return mSpin; }

	class CircleComponent* GetCircle() const { return mCircle; }

private:
	float mSpin;
	CircleComponent* mCircle;
};

