#pragma once

#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur
#include <SFML\Audio.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "MultiSprite.h"
#include "LogicHandler.h"
#include "GuiObject.h"

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	void update(double delta_time);	//update game stuff
	void run(void);	//main game loop
	void setupSprites(void);

private:
	void handleEvent(sf::Event theEventToBeHandled);	//handles any and all events
	bool loadRes(std::string directory);
	sf::RenderWindow *window;	//the main window (probobaly the only)
	std::vector<sf::Texture*> textureList;	//list of all textures currently loaded

	std::vector<sf::Sprite*> guiList;	//list of all gui sprites drawn first
	std::vector<sf::Sprite*> fgList;	//list of all sprites in the forground drawn after gui
	std::vector<sf::Sprite*> mgList;	//list of all sprites in midle ground drawn after forground
	std::vector<sf::Sprite*> bgList;	//list of all sprites in background drawn last

	bool titleScreen;	//if the game is at the title screen
	double elapsedTime;	//total time elapsed
	sf::Sprite titleScreenBg;	//title screen background
};