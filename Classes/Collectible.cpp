#include "Collectible.h"

Collectible::Collectible(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : Interactible(sprite, position, controller, movespeed)
{
	Interactible::init();
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
	auto cListener = EventListenerPhysicsContactWithBodies::create(sprite->getPhysicsBody(), GameMode::current().player->sprite->getPhysicsBody());
	cListener->onContactBegin = CC_CALLBACK_1(Collectible::onContactBegin, this);
	_eventCollisionDispatcher->removeAllEventListeners();
	_eventCollisionDispatcher->addEventListenerWithFixedPriority(cListener, 1);

	return true;
}

void Collectible::Collect()
{
	cocos2d::log("Collected");
	GameEvents::current().CallEvent(GameEvents::current().playerScoretEvent);	

	/*sprite->removeFromParentAndCleanup(true);*/
	unscheduleUpdate();
	dynamic_cast<ObjectController*>(controller)->ResetPosition();
	scheduleUpdate();

}

bool Collectible::onContactBegin(PhysicsContact& contact)
{
	Collect();
	return true;
}