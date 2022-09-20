#pragma once

#include "cocos2d.h"

class Actor : public cocos2d::Node
{
private:
protected:
public:
	// fields
	cocos2d::Sprite* sprite = nullptr;
	cocos2d::Vec2 position = cocos2d::Vec2(0, 0);

	Actor(cocos2d::Sprite* sprite, cocos2d::Vec2 position);
	~Actor();
};

