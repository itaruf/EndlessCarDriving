#pragma once

#include "Interactible.h"
#include "GameMode.h"
#include "ObjectController.h"
#include "GameState.h"
#include "audio/include/AudioEngine.h"

class Collectible : public Interactible
{
public:
	float points = 10.2f;
	Collectible(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), float points = 10.2f, CustomController* controller = nullptr, float movespeed = 0);
	~Collectible();

	EventDispatcher* eventCollectDispatcher = _director->getEventDispatcher();
	EventListenerPhysicsContactWithBodies* collisionListener;
	EventListenerCustom* collectListener;

	bool init() override;

	bool onContactBegin(PhysicsContact& contact) override;

	void Collect();

private:

};
