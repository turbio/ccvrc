#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"
#include "LuaInterface.h"

class StateHandler;

class GameState{

public:
	GameState(const char * lua_path, StateHandler* game_state_handler_reference, int * widht, int * height);
	~GameState(void);
	virtual void update(double delta_time);
	virtual void callState(void);
	std::vector<std::vector<sf::Drawable*>>* getSpriteList(void){
		return &sprites;
	};

	void addPolySprite(int index, int color, int length, int * vertDat);
	void addStringSprite(int index, int x, int y, int size, std::string text, int color);
	void addSprite(int index, sf::Drawable*);
	void addSprite(int index, int x, int y, std::string tex, int w, int h);
	std::string getProp(int target, std::string type);
protected:
	StateHandler* stateHandler;
	LuaInterface* luaInterface;

	std::vector<std::vector<sf::Drawable*>> sprites;

	int * width, * height;
};