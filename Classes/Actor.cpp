#include "Actor.h"

Actor::Actor(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : sprite(sprite), position(position), controller(controller), movespeed(movespeed)
{
	/*if (!sprite)
		return;*/

	if (controller)
		controller->owner = this;
	/*this->Node::create();*/
    init();
}

bool Actor::init()
{
	sprite->setPosition(position);
	sprite->setPhysicsBody(PhysicsBody::createBox(Size(50, 50)));
	sprite->getPhysicsBody()->setEnabled(true);
	sprite->getPhysicsBody()->setDynamic(true);

	
	auto cListener = EventListenerPhysicsContact::create();
	cListener->onContactBegin = CC_CALLBACK_1(Actor::onContactBegin, this);
	_eventCollisionDispatcher->addEventListenerWithFixedPriority(cListener, 1);

	/*auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Actor::onKeyPressed, this);
	_eventKeyBoard->addEventListenerWithFixedPriority(listener, 1);*/
	return true;
}

void Actor::update(float delta)
{
	/*log("hey");*/
}


void Actor::isColliding(std::vector<Actor*>& objects)
{
	return;

	/*cocos2d::log("Checking");*/
	for (const auto& object : objects)
	{
		if (object == this)
			continue;

		if ((sprite->getPhysicsBody()->getCategoryBitmask() & object->sprite->getPhysicsBody()->getCollisionBitmask()) == 0
			|| (object->sprite->getPhysicsBody()->getCategoryBitmask() & sprite->getPhysicsBody()->getCollisionBitmask()) == 0)
		{
			cocos2d::log("%d / %d", getTag(), object->getTag());
		}
		else
			cocos2d::log("NO COLLISION");

	}
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

//void Actor::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
//{
//	cocos2d::log("HERE");
//}


Actor::~Actor()
{
}
