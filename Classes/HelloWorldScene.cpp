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
#include "Actor.h"

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

    auto listener = EventListenerCustom::create("game_start_event", [=](EventCustom* event) {
        std::string str("Custom event 1 received, ");

        const std::string& tmp = "JE BOUGE";
        auto label = Label::createWithTTF(tmp, "fonts/Marker Felt.ttf", 24);
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);

        });

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // 1. super init first
    if (!Scene::init() || !Scene::initWithPhysics())
    {
        return false;
    }


    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    // you may modify it. add a "close" icon to exit the progress. it's an autorelease object

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    Actor* actor = new Actor(Sprite::create("Assets/SportsRacingCar_0.png"), Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    actor->sprite->setPhysicsBody(PhysicsBody::createBox(Size(50, 50)));
    this->addChild(actor->sprite, 0);
    objects.emplace_back(actor);

    /*auto objects{ this->getChildren() };*/
    const std::string& tmp = std::to_string(objects.size());
    auto label = Label::createWithTTF(tmp, "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    this->scheduleUpdate();

    return true;
}

void HelloWorld::update(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for (const auto& object : objects) 
    {
        auto actor = dynamic_cast<Actor*>(object);
        if (!actor)
            continue;
       
        actor->update(delta);

    }

   /* for (const auto& object : objects)
    {
        object->setPosition(object->getPosition() + Vec2(0, 10));
        auto moveTo = MoveTo::create(2, Vec2(0, 20));
        auto actor = dynamic_cast<Actor*>(object);

        GameEvents::current().CallEvent(GameEvents::current().gameStartEvent);

        if (!actor)
            continue;

        auto sprite = actor->sprite;

        if (!sprite)
            continue;

        auto position = sprite->getPosition();
        position.x -= 250 * delta;
        if (position.x < 0 - (actor->getBoundingBox().size.width / 2))
            position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
        sprite->setPosition(position);
    }*/
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}