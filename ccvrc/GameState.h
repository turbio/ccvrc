#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"

class GameState{

public:
	GameState(void);
	~GameState(void);
	void update(void);

private:
	std::vector<GuiObject*> objects;

};

