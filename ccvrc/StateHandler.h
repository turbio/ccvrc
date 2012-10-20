#pragma once

#include "GuiObject.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include "GameState.h"

//game states
#include "GuiTitleScreen.h"

class LogicHandler;

class StateHandler{
public:
	StateHandler(int* width_of_window, int* height_of_window);
	~StateHandler(void);
	void setupGui(void);
	void loading(sf::RenderWindow *window, std::string text = "Loading...");
	void loaded();
	void setState(int index_of_state);
	GameState* getCurrentState(void);
private:
	std::vector<GameState*> states;
	
	GameState* currentState;

	bool gameLoaded;
	int *width, *height;
};

