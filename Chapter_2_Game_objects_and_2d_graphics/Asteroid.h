#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
	Asteroid(class Game* game);

	void SetSpin(float spin) { mSpin = spin; }
	float GetSpin() const { return mSpin; }

private:
	float mSpin;
};

