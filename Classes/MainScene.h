#pragma once

#include "cocos2d.h"
#include "SpawnPoint.h" 
#include "Player.h"
#include "ObjectController.h"
#include "Collectible.h"
#include <algorithm>
#include "Save.h"
#include "Obstacle.h"
#include "PlayerHUD.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"

USING_NS_CC;

class MainScene : public Scene
{
public:
    std::vector<Actor*> objects;
    EventListenerKeyboard* listener{ nullptr };

    static Scene* createScene();

    virtual bool init();

    void update(float) override;

    // a selector callback
    void menuCloseCallback(Ref* pSender);

    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    void buttonPressed(Ref* pSender, ui::Widget::TouchEventType eventType);

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
};
