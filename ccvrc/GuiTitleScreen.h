#pragma once
#include "GameState.h"
#include <iostream>

class GuiTitleScreen : public GameState{

public:
	GuiTitleScreen(StateHandler*);
	~GuiTitleScreen(void);
	void update(double delta_time);

private:

};