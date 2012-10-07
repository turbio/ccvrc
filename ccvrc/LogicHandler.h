#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#pragma once

#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur
#include <SFML\Audio.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "LogicHandler.h"
#include "GuiObject.h"
#include "GuiHandler.h"

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	void update(double delta_time);	//update game stuff
	void run(void);	//main game loop
	void setupSprites(void);
	void addGuiObj(GuiObject* opbject_to_be_added);	//add an object to the gui list
	sf::Texture* LogicHandler::getTexture(int index);

	struct texRes{
		sf::Texture texture;
		char name[1];
	};

private:
	void handleEvent(sf::Event theEventToBeHandled);	//handles any and all events
	bool loadRes(std::string directory);
	sf::RenderWindow *window;	//the main window (probobaly the only)
	std::vector<sf::Texture*> textureList;	//list of all textures currently loade

	std::vector<GuiObject*> guiList;	//list of all gui sprites drawn first
	std::vector<sf::Sprite*> fgList;	//list of all sprites in the forground drawn after gui
	std::vector<sf::Sprite*> mgList;	//list of all sprites in midle ground drawn after forground
	std::vector<sf::Sprite*> bgList;	//list of all sprites in background drawn last

	bool titleScreen;	//if the game is at the title screen
	double elapsedTime;	//total time elapsed

	GuiHandler *guiHandler;

	int width, height;
};

#endif