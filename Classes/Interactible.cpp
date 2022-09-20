#include "Interactible.h"

Interactible::Interactible(Sprite* sprite, Vec2 position, Controller* controller, float movespeed) : Actor(sprite,  position, controller, movespeed)
{
}

Interactible::~Interactible()
{
}