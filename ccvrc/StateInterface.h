#pragma once
#include <SFML\Graphics.hpp>

class GameState;
class GuiObject;

class StateInterface{
public:
	StateInterface(std::vector<sf::Texture*>*,
	std::vector<GuiObject*>*,
	std::vector<sf::Sprite*>*,
	std::vector<sf::Sprite*>*,
	std::vector<sf::Sprite*>*);

	~StateInterface(void);
	sf::Texture* getTexture(int index_of_texture);
	std::vector<GuiObject*>* getGuiList(void);
	std::vector<sf::Sprite*>* getFgList(void);
	std::vector<sf::Sprite*>* getMgList(void);
	std::vector<sf::Sprite*>* getBgList(void);

private:
	std::vector<std::vector<sf::Sprite*>*> spritelists;	//list of sprite lists hehe
};

