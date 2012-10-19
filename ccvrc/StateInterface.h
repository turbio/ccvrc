#pragma once
#include <SFML\Graphics.hpp>
#include "LogicHandler.h"

class GameState;
class GuiObject;

class StateInterface{
public:
	StateInterface(LogicHandler*);

	~StateInterface(void);
	sf::Texture* getTexture(int index_of_texture);
	std::vector<GuiObject*>* getGuiList(void);
	std::vector<sf::Sprite*>* getFgList(void);
	std::vector<sf::Sprite*>* getMgList(void);
	std::vector<sf::Sprite*>* getBgList(void);

private:
	LogicHandler* logicHandler;
};

