#include "ObjectController.h"

ObjectController::ObjectController(Actor* owner, cocos2d::Vec2& direction) : CustomController(owner), direction(direction)
{
}

ObjectController::~ObjectController()
{
}

void ObjectController::MoveHorizontally(float value)
{
	owner->sprite->setPosition(owner->sprite->getPosition() + direction * owner->movespeed);
}

void ObjectController::MoveVertically(float value) 
{
	owner->sprite->setPosition(owner->sprite->getPosition() + direction * owner->movespeed);
}