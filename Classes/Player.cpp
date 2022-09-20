#include "Player.h"

Player::Player(Sprite* sprite, Vec2 position, Controller* controller) : Actor(sprite, position, controller)
{
    init();
}

Player::~Player()
{
}

bool Player::init()
{
    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

    return true;
}

void Player::update(float delta)
{
    /*log("hey");*/
}


void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("PRESSED");
    log("Key with keycode %d pressed", keyCode);
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Released");
    log("Key with keycode %d pressed", keyCode);
}