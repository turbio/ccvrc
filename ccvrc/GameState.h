#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"
#include "LuaInterface.h"

class StateHandler;

class GameState : public LuaInterface{

public:
	GameState(const char * lua_path, StateHandler* game_state_handler_reference);
	~GameState(void);
	virtual void update(double delta_time);
	virtual void callState(void);

	std::vector<GuiObject*>* getGuiList(void){
		return &guiList;
	};
	std::vector<sf::Drawable*>* getfgList(void){
		return &fgList;
	};
	std::vector<sf::Drawable*>* getmgList(void){
		return &mgList;
	};
	std::vector<sf::Drawable*>* getbgList(void){
		return &bgList;
	};

	void addPolySprite(int index, int x_position, int y_postion,
		int width, int height, int color);
protected:
	StateHandler* stateHandler;

	std::vector<GuiObject*> guiList;
	std::vector<sf::Drawable*> fgList;
	std::vector<sf::Drawable*> mgList;
	std::vector<sf::Drawable*> bgList;

};

