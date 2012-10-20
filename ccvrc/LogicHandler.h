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
	void addGuiObj(GuiObject* opbject_to_be_added);	//add an object to the gui list
	sf::Texture* LogicHandler::getTexture(int index);
	void run(void);	//main game loop / lets get this party started

	struct texRes{
		sf::Texture texture;
		char name[1];
	};

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
private:
	void update(double delta_time);	//update game stuff
	void setupSprites(void);
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

	StateHandler *stateHandler;

	int width, height;
};

#endif