#include "Collectible.h"

Collectible::Collectible(Sprite* sprite, Vec2 position, float points, CustomController* controller, float movespeed) : Interactible(sprite, position, controller, movespeed), points(points)
{
	init();
}

Collectible::~Collectible()
{
	/*if (sprite)
		delete sprite;

	if (controller)
		delete controller;*/
}

bool Collectible::init()
{
	sprite->setPhysicsBody(PhysicsBody::createBox(Size(32, 32)));
	Interactible::init();

	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	sprite->getPhysicsBody()->setContactTestBitmask(0x01);
	sprite->setScale(2);

	// Collision with the player

	collisionListener = EventListenerPhysicsContactWithBodies::create(sprite->getPhysicsBody(), GameMode::current().player->sprite->getPhysicsBody());
	collisionListener->onContactBegin = CC_CALLBACK_1(Collectible::onContactBegin, this);
	eventCollisionDispatcher->addEventListenerWithFixedPriority(collisionListener, 1);

	// On Collect Event Dispatcher
	/*collectListener = EventListenerCustom::create(GameEvents::current().playerScoreEvent.getEventName(), [this](EventCustom* event)
		{
			GameState::current().SetScore(points);
		});

	eventCollectDispatcher->addEventListenerWithFixedPriority(collectListener, 1);*/

	return true;
}

void Collectible::Collect()
{
	cocos2d::log("Collected");

	/*cocos2d::AudioEngine::play2d("Assets/coin.mp3", false, 0.05f);*/
	cocos2d::AudioEngine::play2d("Assets/coin.mp3", false, 0.05f);

	//eventCollectDispatcher->dispatchEvent(&GameEvents::current().playerScoreEvent);
	GameState::current().SetScore(points);

	unscheduleUpdate();
	dynamic_cast<ObjectController*>(controller)->ResetPosition();
	scheduleUpdate();
}

bool Collectible::onContactBegin(PhysicsContact& contact)
{
	Collect();
	return true;
}