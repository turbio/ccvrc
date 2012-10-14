#pragma once

#include "GameState.h"

class GuiTitleScreen : public GameState{

public:
	GuiTitleScreen(StateHandler*);
	~GuiTitleScreen(void);
	void update(double delta_time);

private:
};