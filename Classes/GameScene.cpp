/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    scene->getPhysicsWorld()->setDebugDrawMask(0xffff);

    auto layer = GameScene::create();

    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    if (!Scene::init() || !Scene::initWithPhysics())
        return false;

    PlayerHUD* playerHUD{ new PlayerHUD() };
    addChild(playerHUD, -1);

    /*Adding player to the scene*/

    Player* player = new Player(Sprite::create("Assets/SportsRacingCar_0.png"), Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y), nullptr, 10);
    player->setTag(0);
    addChild(player->sprite, 0);
    objects.emplace_back(player);
    GameMode::current().player = player;

    /*Props*/

    for (int i = 0; i < nbSpawns; ++i)
    {
        SpawnPoint* spawn{ new SpawnPoint() };
        spawn->setPosition(Vec2(Vec2(visibleSize.width / 2 + (i - 1) * 300 + origin.x, visibleSize.height / 2 + origin.y + 400)));
        spawns.insert(std::pair<int, std::pair<SpawnPoint*, bool>>(i+1, std::pair<SpawnPoint*, bool>(spawn, false)));
    }

    ObjectController* controller{ new ObjectController(nullptr, Vec2(0,-1)) };
    Obstacle* obstacle = new Obstacle(Sprite::create("Assets/Icons/pixel_style2_15.png"), spawns[1].first->getPosition(), controller, 10);
    obstacle->setTag(1);
    addChild(obstacle->sprite, 0);
    objects.emplace_back(obstacle);

    ObjectController* controller2{ new ObjectController(nullptr, Vec2(0,-1)) };
    Obstacle* interactible2 = new Obstacle(Sprite::create("Assets/Icons/pixel_style2_15.png"), spawns[2].first->getPosition(), controller2, 10);
    interactible2->setTag(1);
    addChild(interactible2->sprite, 0);
    objects.emplace_back(interactible2);

    ObjectController* controller3{ new ObjectController(nullptr, Vec2(0,-1)) };
    Collectible* collectible = new Collectible(Sprite::create("Assets/Icons/pixel_style2_23.png"), spawns[3].first->getPosition(), 10, controller3, 10);
    collectible->setTag(1);
    addChild(collectible->sprite, 0);
    objects.emplace_back(collectible);

    scheduleUpdate();

    return true;
}

void GameScene::update(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for (const auto& object : objects)
    {
        /*auto actor = dynamic_cast<Actor*>(object);
        if (actor)
        {*/
            object->update(delta);
        /*}*/
    }
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}