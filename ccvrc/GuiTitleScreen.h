#pragma once

#include "GameState.h"

class GuiTitleScreen : public GameState{

public:
	GuiTitleScreen(void);
	~GuiTitleScreen(void);
	void update(void);
};