#pragma once
#include "GameState.h"

class MatchSetup : public GameState{

public:
	MatchSetup(StateHandler*);
	~MatchSetup(void);
	void update(double delta_time);
};

