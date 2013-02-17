#pragma once
#include "GameState.h"
#include <iostream>

class BattleState : public GameState{

public:
	BattleState(StateHandler *, sf::RenderWindow *);
	~BattleState(void);
	void update(double delta_time);

private:

};