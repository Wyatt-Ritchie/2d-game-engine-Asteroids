#include "InputComponent.h"
#include "Math.h"
InputComponent::InputComponent(Actor* actor) : MoveComponent(actor)
											  ,mMaxAngularSpeed(Math::Pi)
											  ,mMaxForwardSpeed(150.0f)
											  
{
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
	// calculate the forward speed of movecomponent
	float forwardSpeed = 0.0f;

	if (keyState[mForwardKey])
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mBackKey])
	{
		forwardSpeed -= mMaxForwardSpeed;
	} 

	SetForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (keyState[mClockwiseKey])
	{
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState[mCounterClockwiseKey])
	{
		angularSpeed -= mMaxAngularSpeed;
	}

	SetAngularSpeed(angularSpeed);
}