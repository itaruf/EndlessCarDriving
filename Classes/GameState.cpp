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
	if (score > Save::current().data->getFloatForKey("Score"))
		Save::current().AddData("Score", score);

	GameState::current().score = 0;

	_eventDispatcher->removeEventListener(GameMode::current().player->listener);
	AudioEngine::stop(GameMode::current().player->car_sfx_id);

	auto value = AppDelegate::scenes.at(0);
	auto scene = MainScene::createScene();

	/*Director::getInstance()->pushScene(value);*/
	Director::getInstance()->replaceScene(scene);
}

void GameState::SetScore(float value)
{
	score += value;
}
