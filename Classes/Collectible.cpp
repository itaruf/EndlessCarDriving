#include "Collectible.h"

Collectible::Collectible(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : Interactible(sprite, position, controller, movespeed)
{
	Interactible::init();
}

Collectible::~Collectible()
{
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

	sprite->getParent()->removeChild(this, true);
}

bool Collectible::onContactBegin(PhysicsContact& contact)
{
	cocos2d::log("CONTACT");
	return true;
}