#pragma once

#include "Player.h"
class Player;
#include "cocos2d.h"

static class GameMode
{
public:
	Player* player;
	GameMode();
	~GameMode();

	static GameMode& current()
	{
		static GameMode game;
		return game;
	}
};