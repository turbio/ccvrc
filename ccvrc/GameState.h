#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"

class StateHandler;
sf::Texture* getTexture(int index);
std::vector<sf::Texture*>* getTextureList(void);
void setState(int index_of_state);
std::vector<GuiObject*>* getGuiList(void);

class GameState{

public:
	GameState(std::string name_of_state, StateHandler* game_state_handler_reference);
	~GameState(void);
	virtual void update(double delta_time);

protected:
	std::string name;

	StateHandler* stateHandler;
};

