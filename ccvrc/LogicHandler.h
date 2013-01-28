#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#pragma once

#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur
#include <SFML\Audio.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "GuiObject.h"
#include "StateHandler.h"
#include "GameState.h"

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	sf::Texture* LogicHandler::getTexture(std::string index);
	void run(void);	//main game loop / lets get this party started

	struct texRes{
		sf::Texture texture;
		char name[1];
	};

private:
	void update(double delta_time);	//update game stuff
	void render(void);
	void setupSprites(void);
	void handleEvent(sf::Event evt);
	bool loadRes(std::string directory);
	sf::RenderWindow *window;	//the main window (probobaly the only)
	//std::vector<sf::Texture*> textureList;	//list of all textures currently loade
	std::map<std::string, sf::Texture*> textureList;

	bool titleScreen;	//if the game is at the title screen
	double elapsedTime;	//total time elapsed

	StateHandler *stateHandler;

	int width, height;
};

#endif