#pragma once

#include "CustomController.h"

class ObjectController : public CustomController
{
	cocos2d::Vec2 direction = cocos2d::Vec2(0, -1);
public:
	ObjectController(Actor* owner, cocos2d::Vec2& direction);
	~ObjectController();

	void MoveHorizontally(float value) override;
	void MoveVertically(float value) override;
	void ResetPosition();

private:

};