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

    if (!Scene::init() || !Scene::initWithPhysics())
        return false;

    /*Adding player to the scene*/

    Player* player = new Player(Sprite::create("Assets/SportsRacingCar_0.png"), Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y), nullptr, 10);
    player->setTag(0);
    player->sprite->getPhysicsBody()->setCategoryBitmask(0x01);
    player->sprite->getPhysicsBody()->setCollisionBitmask(0x02);
    player->sprite->getPhysicsBody()->setContactTestBitmask(0x02);

    addChild(player->sprite, 0);
    objects.emplace_back(player);
    GameMode::current().player = player;

    /*Props*/

  ObjectController* controller{ new ObjectController(nullptr, Vec2(0,-1)) };
   Obstacle* obstacle = new Obstacle(Sprite::create("Assets/Icons/pixel_style2_15.png"), Vec2(visibleSize.width / 2 - 200 + origin.x , visibleSize.height / 2 + origin.y + 400), controller, 10);
   obstacle->setTag(1);
   addChild(obstacle->sprite, 0);
   objects.emplace_back(obstacle);

   ObjectController* controller2{ new ObjectController(nullptr, Vec2(0,-1)) };
   Obstacle* interactible2 = new Obstacle(Sprite::create("Assets/Icons/pixel_style2_15.png"), Vec2(visibleSize.width / 2 + 200 + origin.x, visibleSize.height / 2 + origin.y + 400), controller2, 10);
   interactible2->setTag(1);
   addChild(interactible2->sprite, 0);
   objects.emplace_back(interactible2);

    ObjectController* controller3{ new ObjectController(nullptr, Vec2(0,-1)) };
    Collectible* collectible = new Collectible(Sprite::create("Assets/Icons/pixel_style2_23.png"), Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 400), 10, controller3, 10);
    collectible->setTag(1);
    addChild(collectible->sprite, 0);
    objects.emplace_back(collectible);

    /*Save::current().AddData("Hello", "Hello Message");*/
    scheduleUpdate();

    return true;
}

void HelloWorld::update(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Current Score
     /*const std::string& score = std::to_string(GameState::current().score);
     auto score_label = Label::createWithTTF(score, "fonts/Marker Felt.ttf", 24);
     score_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
         origin.y + visibleSize.height - score_label->getContentSize().height));
     addChild(score_label, 1);*/

     // Highest registered score
     /*const std::string& high_score = std::to_string(Save::current().data->getFloatForKey("Score"));
     auto high_score_label = Label::createWithTTF(high_score, "fonts/Marker Felt.ttf", 24);
     high_score_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
         origin.y - 50 + visibleSize.height - high_score_label->getContentSize().height));
     addChild(high_score_label, 1);*/

    /*cocos2d::log("%s", Save::current().data->getStringForKey("Hello").c_str());*/

    for (const auto& object : objects)
    {
        auto actor = dynamic_cast<Actor*>(object);
        if (actor)
        {
            actor->update(delta);
        }
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}