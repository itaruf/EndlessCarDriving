#pragma once

#include "Interactible.h"
#include "GameMode.h"
#include "ObjectController.h"
#include "GameState.h"

class Obstacle : public Interactible
{
public:
	Obstacle(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), CustomController* controller = nullptr, float movespeed = 0);
	~Obstacle();

	EventDispatcher* eventCollectDispatcher = _director->getEventDispatcher();
	EventListenerPhysicsContactWithBodies* collisionListener;
	EventListenerCustom* collectListener;

	bool init() override;

	bool onContactBegin(PhysicsContact& contact) override;
};
