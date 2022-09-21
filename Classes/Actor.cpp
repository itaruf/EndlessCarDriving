#include "Actor.h"

Actor::Actor(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : sprite(sprite), position(position), controller(controller), movespeed(movespeed)
{
	/*if (!sprite)
		return;*/

	if (controller)
		controller->owner = this;

	init();
}

bool Actor::init()
{
	sprite->setPosition(position);

	/*auto cListener = EventListenerPhysicsContact::create();
	cListener->onContactBegin = CC_CALLBACK_1(Actor::onContactBegin, this);
	eventCollisionDispatcher->addEventListenerWithFixedPriority(cListener, 1);*/

	/*auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Actor::onKeyPressed, this);
	_eventKeyBoard->addEventListenerWithFixedPriority(listener, 1);*/
	return true;
}

void Actor::update(float delta)
{
	/*log("hey");*/
}

bool Actor::onContactBegin(PhysicsContact& contact)
{
	PhysicsBody* bodyA = contact.getShapeA()->getBody();
	PhysicsBody* bodyB = contact.getShapeB()->getBody();

	if (((bodyA->getCategoryBitmask() & bodyB->getCollisionBitmask()) == 0) ||
		((bodyB->getCategoryBitmask() & bodyA->getCategoryBitmask()) == 0))
	{
		cocos2d::log("COLLISION");
		return true;
	}
	return false;
}

Actor::~Actor()
{
}
