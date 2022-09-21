#pragma once

#include "Interactible.h"
#include "GameMode.h"
#include "ObjectController.h"
#include "GameState.h"
#include "cocos2d.h"
#include "Actor.h"

class Wall :/* public Node*/ public Actor
{
public:
	/*Sprite* sprite{ nullptr };*/
	/*Vec2 position{ Vec2(0,0) };*/
	Size size{ Size(0, 0) };

	Wall(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), CustomController* controller = nullptr, float movespeed = 0, Size size = Size(0,0));
	/*Wall(Sprite* sprite = nullptr, Vec2& position = Vec2(0, 0), Size& size = Size(0,0));*/

	~Wall();


    bool init() override;

	/*bool onContactBegin(PhysicsContact& contact) override; */
};
