#pragma once

#include "cocos2d.h"
#include "Actor.h"
#include "GameMode.h"

class Actor;
class CustomController
{
public:
	Actor* owner = nullptr;
	CustomController(Actor* owner = nullptr);
	~CustomController();

	virtual void MoveHorizontally(float value) = 0;
	virtual void MoveVertically(float value) = 0;
private:

};