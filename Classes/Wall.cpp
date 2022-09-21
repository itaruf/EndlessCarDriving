#include "Wall.h"

Wall::Wall(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed, Size size) : Actor(sprite, position, controller, movespeed), size(size)
{
	Wall::init();
}

//Wall::Wall(Sprite* sprite, Vec2& position, Size& size) : sprite(sprite), position(position), size(size)
//{
//	Wall::init();
//}

Wall::~Wall()
{
}

bool Wall::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	sprite->setPhysicsBody(cocos2d::PhysicsBody::createBox(Size(50, 500)));

	sprite->getPhysicsBody()->setMass(1000);
	sprite->getPhysicsBody()->setEnabled(true);
	sprite->getPhysicsBody()->setDynamic(true);

	/*this->sprite->setPosition(this->position);
	this->sprite->setPhysicsBody(cocos2d::PhysicsBody::createBox(this->size));
	this->sprite->getPhysicsBody()->setEnabled(true);
	this->sprite->getPhysicsBody()->setDynamic(true);*/

	this->sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	/*log("%f", this->sprite->getPosition().x);*/

	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	sprite->getPhysicsBody()->setContactTestBitmask(0x01);

	log("HERE");

	return true;
}
