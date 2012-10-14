#pragma once

#include "StateHandler.h"
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"

class StateHandler;

class GameState{

public:
	GameState(std::string name_of_state, StateHandler* game_state_handler_reference);
	~GameState(void);
	virtual void update(double delta_time);
	std::vector<GuiObject*>* getGuiList(void);

protected:
	std::vector<GuiObject*> objects;
	std::string name;

	StateHandler* stateHandler;
};

