#pragma once

#include "GuiObject.h"
#include "GameState.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

class StateHandler{
public:
	StateHandler(int* width_of_window, int* height_of_window, std::vector<sf::Texture*>*, std::vector<GuiObject*>*);
	~StateHandler(void);
	void setupGui(void);
	void loading(sf::RenderWindow *window, std::string text = "Loading...");
	void loaded();
private:
	std::vector<sf::Texture*>* textureList;
	std::vector<GuiObject*>* guiList;
	std::vector<GameState*> states;

	bool gameLoaded;
	int *width, *height;
};

