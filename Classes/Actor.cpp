#include "Actor.h"

Actor::Actor(Sprite* sprite, Vec2 position, Controller* controller) : sprite(sprite), position(position), controller(controller)
{
	if (!sprite)
		return;

	/*this->Node::create();*/
	sprite->setPosition(position);
}

void Actor::update(float delta)
{
	
}

Actor::~Actor()
{
}
