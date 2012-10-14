#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"

class LogicHandler;
class StateHandler;

class GameState{

public:
	GameState(std::string name);
	~GameState(void);
	virtual void update(void);
	std::vector<GuiObject*>* getGuiList(void);

protected:
	std::vector<GuiObject*> objects;
	std::string name;
	LogicHandler* logicHandler;
	StateHandler* stateHandler;
};

