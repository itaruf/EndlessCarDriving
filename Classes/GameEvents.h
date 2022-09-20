#pragma once

#include <cocos2d.h>
USING_NS_CC;

static class GameEvents
{
public:
	EventCustom gameStartEvent{ "game_start_event" };
	EventCustom gameEndEvent{ "game_end_event" };
	EventCustom playerScoretEvent{ "player_score_event" };
};