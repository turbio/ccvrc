#pragma once

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "GuiObject.h"
#include "LuaInterface.h"
#include "Sprite.h"

class StateHandler;

class GameState{

public:
	GameState(std::string lua_path, StateHandler* game_state_handler_reference);
	~GameState(void);
	virtual void update(double delta_time);
	virtual void callState(void);
	void resetState(void);
	std::vector<Sprite*>* getSpriteList(void){
		return &sprites;
	};

	void addPolySprite(int index, int color, int length, int * vertDat);
	void addStringSprite(int index, int x, int y, int size, std::string text, int color);
	void addSprite(std::string, sf::Drawable*);
	void addSprite(std::string, int x, int y, std::string tex, int w, int h);
	std::string getProp(int target, std::string type);
protected:
	StateHandler* stateHandler;
	LuaInterface* luaInterface;

	std::vector<Sprite*> sprites;

	int width, height;

private:
	std::string luaPath;
};