#pragma once

#include "cocos2d.h"
USING_NS_CC;

class Actor : public Node
{
private:
protected:
public:
	// fields
	Sprite* sprite = nullptr;
	Vec2 position = Vec2(0, 0);
	Controller* controller = nullptr;
	float movespeed = 0;

	void update(float) override;
	bool init() override;

	Actor(Sprite* sprite = nullptr, Vec2 position = Vec2(0,0), Controller* controller = nullptr, float movespeed = 0);
	~Actor();
};

