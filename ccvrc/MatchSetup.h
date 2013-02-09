#pragma once
#include "GameState.h"

class MatchSetup : public GameState{

public:
	MatchSetup(StateHandler*, sf::RenderWindow *);
	~MatchSetup(void);
	void update(double delta_time);
};

