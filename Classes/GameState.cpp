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

	GameState::current().score = 0;

	auto value = AppDelegate::scenes.at(0);
	auto scene = MainScene::createScene();

	/*_eventDispatcher->remove*/
	_eventDispatcher->removeAllEventListeners();
	/*Director::getInstance()->pushScene(value);*/
	Director::getInstance()->replaceScene(scene);
}

void GameState::SetScore(float value)
{
	score += value;
	cocos2d::log("%.2f", score);
}
