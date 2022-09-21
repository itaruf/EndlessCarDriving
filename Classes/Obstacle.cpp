#include "Obstacle.h"

Obstacle::Obstacle(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : Interactible(sprite, position, controller, movespeed)
{
	init();
}

Obstacle::~Obstacle()
{
	/*if (sprite)
		delete sprite;

	if (controller)
		delete controller;*/
}

bool Obstacle::init()
{
	// Collision with the player
	collisionListener = EventListenerPhysicsContactWithBodies::create(sprite->getPhysicsBody(), GameMode::current().player->sprite->getPhysicsBody());
	collisionListener->onContactBegin = CC_CALLBACK_1(Obstacle::onContactBegin, this);
	eventCollisionDispatcher->addEventListenerWithFixedPriority(collisionListener, 1);

	//auto listener = EventListenerCustom::create(GameEvents::current().gameEndEvent.getEventName(), [this](EventCustom* event)
	//	{
	//		GameState::current().OnGameEnd();
	//	});

	//eventCollisionDispatcher->addEventListenerWithFixedPriority(listener, 1);
	return true;
}


bool Obstacle::onContactBegin(PhysicsContact& contact)
{
	eventCollisionDispatcher->dispatchEvent(&GameEvents::current().gameEndEvent);
	GameState::current().OnGameEnd();

	return true;
}