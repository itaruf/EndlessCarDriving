#include "Actor.h"

Actor::Actor(Sprite* sprite, Vec2 position, Controller* controller, float movespeed) : sprite(sprite), position(position), controller(controller), movespeed(movespeed)
{
	if (!sprite)
		return;

	/*this->Node::create();*/
    init();
}

bool Actor::init()
{
	sprite->setPosition(position);
	sprite->setPhysicsBody(PhysicsBody::createBox(Size(50, 50)));
	sprite->getPhysicsBody()->setDynamic(true);

	/*sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	sprite->getPhysicsBody()->setContactTestBitmask(0x02);*/

	auto cListener = EventListenerPhysicsContact::create();
	cListener->onContactBegin = CC_CALLBACK_1(Actor::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cListener, this);

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
	cocos2d::log("Detection");

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
