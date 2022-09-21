#include "ObjectController.h"

ObjectController::ObjectController(Actor* owner, cocos2d::Vec2& direction) : CustomController(owner), direction(direction)
{
}

ObjectController::~ObjectController()
{
}

void ObjectController::MoveHorizontally(float value)
{
	if (owner == nullptr)
		return;

	if (owner->sprite == nullptr)
		return;

	owner->sprite->setPosition(owner->sprite->getPosition() + direction * owner->movespeed);

	/*auto sprite = owner->sprite;
	auto position = owner->sprite->getPosition();
	owner->sprite->setPosition(position + direction * owner->movespeed);

	if (position.y < 0 - (owner->getBoundingBox().size.width / 2))
		position.y = owner->sprite->getParent()->getBoundingBox().getMaxY() + owner->sprite->getParent()->getBoundingBox().size.width / 2;
	sprite->setPosition(position);*/
}

void ObjectController::MoveVertically(float value) 
{
	auto sprite = owner->sprite;
	auto position = owner->sprite->getPosition();
	owner->sprite->setPosition(position + direction * owner->movespeed);

	if (position.y < 0 - (owner->getBoundingBox().size.width / 2))
		ResetPosition();
	else
		sprite->setPosition(position);

}

void ObjectController::ResetPosition()
{
	auto sprite = owner->sprite;
	auto position = owner->sprite->getPosition();

	auto map_size = GameMode::current().spawns.size();
	auto random = cocos2d::random(1, (int) map_size);

	position = GameMode::current().spawns[random].first->getPosition();

	sprite->setPosition(position);
}