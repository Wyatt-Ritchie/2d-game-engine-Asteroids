#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"

MoveComponent::MoveComponent(Actor* actor) : Component(actor)
											,mAngularSpeed(0.0f)
											,mForwardSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}

	if (!Math::NearZero(mForwardSpeed))
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}

	// For asteroid game we can include some code for screen wrapping
	// for generic funcitions we do not include this.

	// Asteroid wrapping code
	Vector2 pos = mOwner->GetPosition();
	if (pos.x < -16)
	{
		mOwner->SetPosition(Vector2(1040, pos.y));
	}
	if (pos.x > 1040)
	{
		mOwner->SetPosition(Vector2(-16, pos.y));
	}
	if (pos.y < -16)
	{
		mOwner->SetPosition(Vector2(pos.x, 784));
	}
	if (pos.y > 784)
	{
		mOwner->SetPosition(Vector2(pos.x, -16));
	}
	
}