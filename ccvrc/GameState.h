#pragma once

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
	virtual void callState(void);
	std::string name;

	std::vector<GuiObject*>* getGuiList(void){
		return &guiList;
	};
	std::vector<sf::Sprite*>* getfgList(void){
		return &fgList;
	};
	std::vector<sf::Sprite*>* getmgList(void){
		return &mgList;
	};
	std::vector<sf::Sprite*>* getbgList(void){
		return &bgList;
	};
protected:
	StateHandler* stateHandler;

	std::vector<GuiObject*> guiList;
	std::vector<sf::Sprite*> fgList;
	std::vector<sf::Sprite*> mgList;
	std::vector<sf::Sprite*> bgList;
};

