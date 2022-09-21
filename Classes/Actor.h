#pragma once

#include "cocos2d.h"
#include "GameEvents.h"

class CustomController;
#include "CustomController.h"

USING_NS_CC;

class Actor : public Node
{
//friend class CustomController;
private:
protected:
public:
	EventDispatcher* eventCollisionDispatcher = _director->getEventDispatcher();

	// fields
	Sprite* sprite{ nullptr };
	Vec2 position{ Vec2(0, 0) };
	CustomController* controller{ nullptr };
	float movespeed{ 0 };

	Actor(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), CustomController* controller = nullptr, float movespeed = 0);
	~Actor();

	void update(float) override;
	bool init() override;

	virtual bool onContactBegin(PhysicsContact& contact);
};

