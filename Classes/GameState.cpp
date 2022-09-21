#include "GameState.h"

GameState::GameState()
{
}

GameState::~GameState()
{
}

bool GameState::init()
{
	return true;
}

void GameState::OnGameStart()
{

}


void GameState::OnGameEnd()
{
	cocos2d::log("END");

	if (score > Save::current().data->getFloatForKey("Score"))
		Save::current().AddData("Score", score);
}

void GameState::SetScore(float value)
{
	score += value;
	cocos2d::log("%.2f", score);
}
