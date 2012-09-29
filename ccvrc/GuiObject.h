#pragma once
#include <SFML\Graphics.hpp>

class GuiObject: public sf::Sprite{

public:
	GuiObject(void);
	~GuiObject(void);
	bool mouseOver(void);
	bool mouseDown(void);
	void setTexture(sf::Texture);
	void setOverTexture(sf::Texture);
	void setDownTexture(sf::Texture);
	bool pollEvent(sf::Event);

private:
	sf::Texture defaultTexture, mouseOverTexture, mouseDownTexture;
};

