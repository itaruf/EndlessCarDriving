#include "Collectible.h"

Collectible::Collectible(Sprite* sprite, Vec2 position, float points, CustomController* controller, float movespeed) : Interactible(sprite, position, controller, movespeed), points(points)
{
	Interactible::init();
	init();
}

Collectible::~Collectible()
{
	/*if (sprite)
		delete sprite;

	if (controller)
		delete controller;*/
}

bool Collectible::init()
{
	// Collision with the player
	collisionListener = EventListenerPhysicsContactWithBodies::create(sprite->getPhysicsBody(), GameMode::current().player->sprite->getPhysicsBody());
	collisionListener->onContactBegin = CC_CALLBACK_1(Collectible::onContactBegin, this);
	eventCollisionDispatcher->addEventListenerWithFixedPriority(collisionListener, 1);

	// On Collect Event Dispatcher
	collectListener = EventListenerCustom::create(GameEvents::current().playerScoreEvent.getEventName(), [this](EventCustom* event)
		{
			GameState::current().SetScore(points);
		});

	eventCollectDispatcher->addEventListenerWithFixedPriority(collectListener, 1);

	return true;
}

void Collectible::Collect()
{
	cocos2d::log("Collected");
	eventCollectDispatcher->dispatchEvent(&GameEvents::current().playerScoreEvent);

	unscheduleUpdate();
	dynamic_cast<ObjectController*>(controller)->ResetPosition();
	scheduleUpdate();
}

bool Collectible::onContactBegin(PhysicsContact& contact)
{
	Collect();
	return true;
}