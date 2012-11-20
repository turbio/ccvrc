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
	std::vector<std::vector<sf::Drawable*>>* getSpriteList(void){
		return &sprites;
	};

	void addPolySprite(int index, int x_position, int y_postion,
		int width, int height, int color);
	void addStringSprite(int index, int x, int y, int size, std::string text, int color);
	void addSprite(int index, sf::Drawable*);
	void addSprite(int index, int x, int y, std::string tex, int scaleX, int scaleY);
protected:
	StateHandler* stateHandler;
	LuaInterface* luaInterface;

	//std::vector<GuiObject*> guiList;
	//std::vector<sf::Drawable*> fgList;
	//std::vector<sf::Drawable*> mgList;
	//std::vector<sf::Drawable*> bgList;

	std::vector<std::vector<sf::Drawable*>> sprites;

};