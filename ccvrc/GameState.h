#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"
#include "LuaInterface.h"

class StateHandler;

class GameState{

public:
	GameState(const char * lua_path, StateHandler* game_state_handler_reference);
	~GameState(void);
	virtual void update(double delta_time);
	virtual void callState(void);
	void addSprite(int index, sf::Drawable*);
	std::vector<std::vector<sf::Drawable*>>* getSpriteList(void){
		return &sprites;
	};

	void addPolySprite(int index, int x_position, int y_postion,
		int width, int height, int color);
protected:
	StateHandler* stateHandler;
	LuaInterface* luaInterface;

	//std::vector<GuiObject*> guiList;
	//std::vector<sf::Drawable*> fgList;
	//std::vector<sf::Drawable*> mgList;
	//std::vector<sf::Drawable*> bgList;

	std::vector<std::vector<sf::Drawable*>> sprites;

};