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
	cocos2d::log("Init");

	// Collision with the player
	/*auto cListener = EventListenerPhysicsContactWithBodies::create(sprite->getPhysicsBody(), GameMode::current().player->sprite->getPhysicsBody());
	cListener->onContactBegin = CC_CALLBACK_1(Collectible::onContactBegin, this);
	_eventCollisionDispatcher->removeAllEventListeners();
	_eventCollisionDispatcher->addEventListenerWithFixedPriority(cListener, 2);*/

	// On Collect Event Dispatcher
	collectListener = EventListenerCustom::create("player_score_event", [this](EventCustom* event)
		{
			GameState::current().SetScore(points);
		});

	_eventCollectDispatcher->addEventListenerWithFixedPriority(collectListener, 1);

	return true;
}

void Collectible::Collect()
{
	cocos2d::log("Collected");
	_eventCollectDispatcher->dispatchEvent(&GameEvents::current().playerScoreEvent);

	unscheduleUpdate();
	dynamic_cast<ObjectController*>(controller)->ResetPosition();
	scheduleUpdate();
}

bool Collectible::onContactBegin(PhysicsContact& contact)
{
	Collect();
	return true;
}

void Collectible::Test()
{
	cocos2d::log("CALLEEEEEED");

}