#include "Actor.h"

Actor::Actor(Sprite* sprite, Vec2 position, Controller* controller, float movespeed) : sprite(sprite), position(position), controller(controller), movespeed(movespeed)
{
	if (!sprite)
		return;

	/*this->Node::create();*/
    init();
	sprite->setPosition(position);
}

bool Actor::init()
{
    return true;
}

void Actor::update(float delta)
{
	/*log("hey");*/
}


Actor::~Actor()
{
}
