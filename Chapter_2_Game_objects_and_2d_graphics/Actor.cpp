#include "Actor.h"
#include "Component.h"
#include "Game.h"
#include <iostream>
Actor::Actor(class Game* game) : mGame(game), 
								 mState(EActive), 
								 mPosition(Vector2( 0.0f, 0.0f )), 
								 mScale(1.0f), 
								 mRotation(0.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	std::cout << "Actor removed" << std::endl;
	// delete components
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	if (mState == EActive)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::AddComponent(Component* component)
{
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();

	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}
	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
	std::cout << "Components Removed" << std::endl;
}

void Actor::SetPosition(Vector2 position)
{
	mPosition = position;
}

void Actor::SetScale(float scale)
{
	mScale = scale;
}

Actor::State Actor::getState()
{
	return mState;
}
