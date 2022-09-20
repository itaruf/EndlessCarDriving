#pragma once

#include "Actor.h"

class Player : public Actor
{
public:
	Player(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), Controller* controller = nullptr);
	~Player();

	void update(float) override;
	bool init() override;

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

