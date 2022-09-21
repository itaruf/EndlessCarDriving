#pragma once
#include "Save.h"
#include "cocos2d.h"

class GameState
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