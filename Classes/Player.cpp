#include "Player.h"

Player::Player(Sprite* sprite, Vec2 position, CustomController* controller, float movespeed) : Actor(sprite, position, controller, movespeed)
{
    init();
}

Player::~Player()
{
}

bool Player::init()
{
    sprite->setPhysicsBody(PhysicsBody::createBox(Size(50, 50)));
    /*sprite->getPhysicsBody()->setEnabled(true);
    sprite->getPhysicsBody()->setDynamic(true);*/

    sprite->setScale(2);
    sprite->getPhysicsBody()->setMass(1);
    sprite->getPhysicsBody()->setCategoryBitmask(0x01);
    sprite->getPhysicsBody()->setCollisionBitmask(0x02);
    sprite->getPhysicsBody()->setContactTestBitmask(0x02);
    sprite->getPhysicsBody()->setRotationEnable(false);

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
}


void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    auto playerX{ sprite->getPosition().x };
    auto playerY{ sprite->getPosition().y };

    switch (keyCode)
    {
        // MOVE UP
    case EventKeyboard::KeyCode::KEY_W:
    /*case EventKeyboard::KeyCode::KEY_Z:*/
        direction.y = 1;
        /*playerY += movespeed;*/
        break;

        // MOVE DOWN
    case EventKeyboard::KeyCode::KEY_S:
        direction.y = -1;
        /*playerY -= movespeed;*/
        break;

        // MOVE LEFT
    case EventKeyboard::KeyCode::KEY_A:
    /*case EventKeyboard::KeyCode::KEY_Q:*/
        direction.x = -1;
        playerX += movespeed;
        break;

        // MOVE RIGHT
    case EventKeyboard::KeyCode::KEY_D:
        direction.x = 1;
        /*playerX -= movespeed;*/
        break;

    case EventKeyboard::KeyCode::KEY_ESCAPE:
        GameEvents::current().CallEvent(GameEvents::current().gameEndEvent);
        Director::getInstance()->end();

    default:
        break;
    }
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    /*return;*/

    switch (keyCode)
    {
        // MOVE UP
    case EventKeyboard::KeyCode::KEY_W:
    /*case EventKeyboard::KeyCode::KEY_Z:*/
        direction = Vec2(direction.x, 0);
        break;

        // MOVE DOWN
    case EventKeyboard::KeyCode::KEY_S:
        direction = Vec2(direction.x, 0);
        break;

        // MOVE LEFT
    case EventKeyboard::KeyCode::KEY_A:
    /*case EventKeyboard::KeyCode::KEY_Q:*/
        direction = Vec2(0, direction.y);
        break;

        // MOVE RIGHT
    case EventKeyboard::KeyCode::KEY_D:
        direction = Vec2(0, direction.y);
        break;

    default:
        break;
    }
}

void Player::MoveHorizontally(float value)
{
    float position = sprite->getPosition().x + (value * movespeed);

    sprite->setPosition(position, sprite->getPosition().y);
}

void Player::MoveVertically(float value)
{
    float position = sprite->getPosition().y + (value * movespeed);

    sprite->setPosition(sprite->getPosition().x, position);
}