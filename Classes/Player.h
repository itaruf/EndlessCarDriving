#pragma once

#include "Actor.h"

class Player : public Actor
{
public:
	Player(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), Controller* controller = nullptr);
	~Player();
};

