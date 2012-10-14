#pragma once

#include "GameState.h"
#include "GuiObject.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

class StateHandler{
public:
	StateHandler(int* width_of_window, int* height_of_window, std::vector<sf::Texture*>*, std::vector<GuiObject*>*);
	~StateHandler(void);
	void setupGui(void);
	void loading(sf::RenderWindow *window, std::string text = "Loading...");
	void loaded();
	sf::Texture* getTexture(int index);
	std::vector<sf::Texture*>* getTextureList(void);
	//sf::SoundBuffer* getSound(int index);
	//std::vector<sf::SoundBuffer*>* getSoundList(void);
	void setState(int index_of_state);
	GameState* getCurrentState(void);
private:
	std::vector<sf::Texture*>* textureList;
	std::vector<GuiObject*>* guiList;
	std::vector<GameState*> states;
	
	GameState* currentState;

	bool gameLoaded;
	int *width, *height;
};

