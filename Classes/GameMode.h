#pragma once

class Player;
#include "cocos2d.h"
#include "SpawnPoint.h"

static class GameMode
{
public:
	Player* player;

	int nbSpawns{ 4 };
	std::vector<SpawnPoint*> spawnPoints;
	std::unordered_map<int, std::pair<SpawnPoint*, bool>> spawns;

	GameMode();
	~GameMode();

	static GameMode& current()
	{
		static GameMode game;
		return game;
	}
};