#pragma once

#include "cocos2d.h"
#include "GameState.h"

USING_NS_CC;

class PlayerHUD : public Layer
{
public:
	PlayerHUD();
	~PlayerHUD();

	Label* score_label;
	Label* high_score_label;

	bool init() override;
	void update(float delta) override;
};

