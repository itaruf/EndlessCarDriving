#pragma once

#include "Actor.h"
#include "audio/include/AudioEngine.h"

class Player : public Actor
{
public:
	Vec2 direction{ Vec2(0,0) };
	EventListenerKeyboard* listener{ nullptr };
	int  car_sfx_id{ 0 };

	Player(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), CustomController* controller = nullptr, float movespeed = 0);
	~Player();

	void update(float) override;
	bool init() override;

	void MoveHorizontally(float value);
	void MoveVertically(float value);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

