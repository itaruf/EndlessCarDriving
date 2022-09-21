#include "GameState.h"

GameState::GameState()
{
}

GameState::~GameState()
{
}

bool GameState::init()
{
	/*auto listener = EventListenerCustom::create(GameEvents::current().gameEndEvent.getEventName(), CC_CALLBACK_0(GameState::OnGameEnd, this));

	eventCollectDispatcher->addEventListenerWithFixedPriority(listener, 1);*/

	return true;
}

void GameState::OnGameStart()
{

}


void GameState::OnGameEnd()
{
	cocos2d::log("END");
	Save::current().AddData("Score", score);
}

void GameState::SetScore(float value)
{
	score += value;
	cocos2d::log("%.2f", score);
}
