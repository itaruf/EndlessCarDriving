#include "Actor.h"

Actor::Actor(cocos2d::Sprite* sprite, cocos2d::Vec2 position) : sprite(sprite), position(position)
{
	if (!sprite)
		return;

	sprite->setPosition(position);
}

Actor::~Actor()
{
}
