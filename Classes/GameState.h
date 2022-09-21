#pragma once

#include "Save.h"
#include "cocos2d.h"
#include "GameEvents.h"

USING_NS_CC;

class GameState : public cocos2d::Node
{
public:
	float score = 0;

	GameState();
	~GameState();

	static GameState& current()
	{
		static GameState game;
		return game;
	}

	bool init();

	void OnGameStart();
	void OnGameEnd();
	void SetScore(float value);
};