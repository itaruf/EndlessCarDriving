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

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    scene->getPhysicsWorld()->setDebugDrawMask(0xffff);

    auto layer = HelloWorld::create();

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
bool HelloWorld::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 1. super init first
    if (!Scene::init() || !Scene::initWithPhysics())
        return false;

    /*Adding player to the scene*/

    Player* player = new Player(Sprite::create("Assets/SportsRacingCar_0.png"), Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y), nullptr, 10);
    player->setTag(0);
    player->sprite->getPhysicsBody()->setCategoryBitmask(0x01);
    player->sprite->getPhysicsBody()->setCollisionBitmask(0x02);
    player->sprite->getPhysicsBody()->setContactTestBitmask(0x02);

    this->addChild(player->sprite, 0);
    objects.emplace_back(player);

    ObjectController* controller{ new ObjectController(nullptr, Vec2(0,-1)) };

    Interactible* interactible = new Interactible(Sprite::create("Assets/SportsRacingCar_0.png"), Vec2(visibleSize.width / 2 - 200 + origin.x , visibleSize.height / 2 + origin.y + 400), controller, 1);
    interactible->setTag(1);
    this->addChild(interactible->sprite, 0);
    objects.emplace_back(interactible);

    ObjectController* controller2{ new ObjectController(nullptr, Vec2(0,-1)) };
    Interactible* interactible2 = new Interactible(Sprite::create("Assets/SportsRacingCar_0.png"), Vec2(visibleSize.width / 2 + 200 + origin.x, visibleSize.height / 2 + origin.y + 400), controller2, 1);
    interactible2->setTag(1);
    this->addChild(interactible2->sprite, 0);
    objects.emplace_back(interactible2);

    this->scheduleUpdate();

    return true;
}

void HelloWorld::update(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for (const auto& object : objects) 
    {
        auto player = dynamic_cast<Player*>(object);
        if (player)
        {
            player->update(delta);
        }

        auto interactible = dynamic_cast<Interactible*>(object);
        if (interactible)
        {
            interactible->update(delta);
        }
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}