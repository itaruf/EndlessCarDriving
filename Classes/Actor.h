#pragma once

#include "cocos2d.h"

class CustomController;
#include "CustomController.h"

USING_NS_CC;

class Actor : public Node
{
//friend class CustomController;
private:
protected:
public:
	EventDispatcher* _eventCollisionDispatcher = _director->getEventDispatcher();
	/*EventDispatcher* _eventKeyBoard = _director->getEventDispatcher();*/

	// fields
	Sprite* sprite{ nullptr };
	Vec2 position{ Vec2(0, 0) };
	CustomController* controller{ nullptr };
	float movespeed{ 0 };

	Actor(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), CustomController* controller = nullptr, float movespeed = 0);
	~Actor();

	void update(float) override;
	bool init() override;

	void isColliding(std::vector<Actor*>& objects);

	bool onContactBegin(PhysicsContact& contact);
	/*void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);*/

};

