#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();

    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    if (!Scene::init())
        return false;

    listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MainScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

    /*Props*/
    PlayerHUD* playerHUD{ new PlayerHUD() };
    addChild(playerHUD, 0);

    auto button = ui::Button::create("Assets/Icons/pixel_style2_15.png", "Assets/Icons/pixel_style2_15.png", "Assets/Icons/pixel_style2_15.png");

    button->setTitleText("Button Text");
    button->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    button->setScale(4);

    button->addTouchEventListener(CC_CALLBACK_2(MainScene::buttonPressed, this));
    
    this->addChild(button);

    scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for (const auto& object : objects)
        if (object)
            object->update(delta);
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_ESCAPE:
        Director::getInstance()->end();

    default:
        break;
    }
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("here2");
}

void MainScene::buttonPressed(Ref* pSender, ui::Widget::TouchEventType eventType)
{
    switch (eventType)
    {
    case ui::Widget::TouchEventType::BEGAN:
    {
        auto scene = GameScene::createScene();
        Director::getInstance()->replaceScene(scene);
        _eventDispatcher->removeEventListener(listener);
    }
        break;
    case ui::Widget::TouchEventType::ENDED:
        break;
    default:
        break;
    }
}

void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}