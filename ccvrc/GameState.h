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
	GameState(std::string stateName, std::string lua_path, StateHandler* game_state_handler_reference, sf::RenderWindow * window);
	~GameState(void);
	virtual void update(double delta_time);
	virtual void callState(void);
	virtual void closeState(void);
	void resetState(void);
	std::vector<Sprite*>* getSpriteList(void){
		return &sprites;
	};

	void addPolySprite(std::string index, int x, int y, int color, int length, int * vertDat);
	void addStringSprite(std::string index, int x, int y, int size, std::string text, int color);
	void addSprite(Sprite*);
	void addSprite(std::string, int x, int y, std::string tex, int w, int h);
	void interpolateSprite(std::string target = "null", int destinationX = 0, int destinationY = 0, float speed = 1);
	void setState(std::string);
	std::string getProp(std::string target, std::string type);
	void setProp(std::string target, std::string type);
	Sprite* findSprite(std::string);

	void keyDown(int key);
	void mouseDown(int btn);
	std::string getIndex(void){
		return stateName;
	}
protected:
	StateHandler* stateHandler;
	LuaInterface* luaInterface;

	std::vector<Sprite*> sprites;

	int width, height;

private:
	std::string luaPath;
	std::string stateName;

	sf::RenderWindow * window;
};