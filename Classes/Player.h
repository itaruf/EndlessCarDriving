#pragma once

#include "Actor.h"

class Player : public Actor
{
private:
	Vec2 direction = Vec2(0,0);
	EventListenerKeyboard* listener;
	bool isKeyPressed = false;
public:
	Player(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), Controller* controller = nullptr, float movespeed = 0);
	~Player();

	void update(float) override;
	bool init() override;

	void MoveHorizontally(float value);
	void MoveVertically(float value);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

