#include "Interactible.h"

Interactible::Interactible(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : Actor(sprite,  position, controller, movespeed)
{
	init();
}

Interactible::~Interactible()
{
}

bool Interactible::init()
{
	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	sprite->getPhysicsBody()->setContactTestBitmask(0x01);

	return true;
}

void Interactible::update(float delta)
{
	if (controller)
	{
		controller->MoveHorizontally(0);
		controller->MoveVertically(0);
	}
}

