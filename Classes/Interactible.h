#pragma once

#include "Actor.h"

class Interactible : public Actor
{
public:
	Interactible(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), Controller* controller = nullptr, float movespeed = 0);
	~Interactible();

private:

};