#pragma once
#include "Component.h"
class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* actor);
	

	void Update(float deltaTime) override;

	// Getters
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }

	// Setters
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }

private:
	// constrols the rotation (radians per sec)
	float mAngularSpeed;
	// constrols the forward speed (units per sec)
	float mForwardSpeed;
};

