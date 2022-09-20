#pragma once

#include "Interactible.h"
#include "GameMode.h"
#include "ObjectController.h"

class Collectible : public Interactible
{
public:
	Collectible(Sprite* sprite = nullptr, Vec2 position = Vec2(0, 0), CustomController* controller = nullptr, float movespeed = 0);
	~Collectible();

	bool init() override;

	bool onContactBegin(PhysicsContact& contact) override;

	void Collect();

private:

};
