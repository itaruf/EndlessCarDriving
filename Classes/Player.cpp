#include "Player.h"

Player::Player(Sprite* sprite, Vec2 position, Controller* controller, float movespeed) : Actor(sprite, position, controller, movespeed)
{
    init();
}

Player::~Player()
{
}

bool Player::init()
{
    listener = EventListenerKeyboard::create();

    listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

    return true;
}

void Player::update(float delta)
{

    MoveHorizontally(direction.x);
    MoveVertically(direction.y);

    /*log("hey");*/
}


void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
        // MOVE UP
    case EventKeyboard::KeyCode::KEY_W:
    case EventKeyboard::KeyCode::KEY_Z:
        direction = Vec2(direction.x, 1);
        break;

        // MOVE DOWN
    case EventKeyboard::KeyCode::KEY_S:
        direction = Vec2(direction.x, -1);
        break;

        // MOVE LEFT
    case EventKeyboard::KeyCode::KEY_A:
    case EventKeyboard::KeyCode::KEY_Q:
        direction = Vec2(-1, direction.y);
        break;

        // MOVE RIGHT
    case EventKeyboard::KeyCode::KEY_D:
        direction = Vec2(1, direction.y);
        break;        

    default:
        break;
    }

    cocos2d::log("PRESSED");
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    /*isKeyPressed = false;*/
    switch (keyCode)
    {
        // MOVE UP
    case EventKeyboard::KeyCode::KEY_W:
    case EventKeyboard::KeyCode::KEY_Z:
        direction = Vec2(direction.x, 0);
        break;

        // MOVE DOWN
    case EventKeyboard::KeyCode::KEY_S:
        direction = Vec2(direction.x, 0);
        break;

        // MOVE LEFT
    case EventKeyboard::KeyCode::KEY_A:
    case EventKeyboard::KeyCode::KEY_Q:
        direction = Vec2(0, direction.y);
        break;

        // MOVE RIGHT
    case EventKeyboard::KeyCode::KEY_D:
        direction = Vec2(0, direction.y);
        break;

    default:
        break;
    }

    cocos2d::log("Released");
}

void Player::MoveHorizontally(float value)
{
    cocos2d::log("%.2f", value);

    float position = sprite->getPosition().x + (value * movespeed);

    sprite->setPosition(position, sprite->getPosition().y);
}

void Player::MoveVertically(float value)
{
    cocos2d::log("%.2f", value);

    float position = sprite->getPosition().y + (value * movespeed);

    sprite->setPosition(sprite->getPosition().x, position);
}