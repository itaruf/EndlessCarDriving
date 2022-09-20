#pragma once

#include <cocos2d.h>
USING_NS_CC;

static class GameEvents : public Node
{
public:

	EventCustom gameStartEvent{ "game_start_event" };
	EventCustom gameEndEvent{ "game_end_event" };
	EventCustom playerScoretEvent{ "player_score_event" };

	static GameEvents& current() 
	{ 
		static GameEvents game;
		return game;
	}

	void CallEvent(EventCustom& event)
	{
		_eventDispatcher->dispatchEvent(&event);
	}

	// Pour utiliser l'instance statique : exemple : GameEvents.current().gameStartEvent
};