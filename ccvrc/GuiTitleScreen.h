#pragma once

#include "GameState.h"
#include "StateHandler.h"

class GuiTitleScreen : public GameState{

public:
	GuiTitleScreen(StateHandler* h);
	~GuiTitleScreen(void);
	void update(double delta);

private:
};