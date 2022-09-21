#include "Wall.h"

//Wall::Wall(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed, Size size) : Actor(sprite, position, controller, movespeed), size(size)
//{
//	Wall::init();
//}

Wall::Wall(Sprite* sprite, Vec2& position, Size& size) : sprite(sprite), position(position), size(size)
{
	this->sprite->setPhysicsBody(cocos2d::PhysicsBody::createBox(size));
	this->sprite->getPhysicsBody()->setMass(2000);
	sprite->getPhysicsBody()->setRotationEnable(false);

	this->sprite->getPhysicsBody()->setAngularDamping(1);
	this->sprite->getPhysicsBody()->setVelocityLimit(0);

	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	sprite->getPhysicsBody()->setContactTestBitmask(0x01);

	this->sprite->setPosition(position);

	/*log("%f", this->this->sprite->getPosition().x);*/

	this->sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	this->sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	this->sprite->getPhysicsBody()->setContactTestBitmask(0x01);
}

Wall::~Wall()
{
}
