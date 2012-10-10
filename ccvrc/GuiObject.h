#pragma once
#include <SFML\Graphics.hpp>

class GuiObject: public sf::Sprite{

public:
	GuiObject(char[]);	//CONSTRUCTOR obvously
	~GuiObject(void);	//I HOPE YOU KNOW WHAT THIS IS...
	void setDefTexture(sf::Texture);	//set the primary/default texture should be set
	void setOverTexture(sf::Texture);	//set secondary texture for when the mouse is over
	void setDownTexture(sf::Texture);	//set to mouse clicked texture
	sf::Event pollEvent(sf::Event);	//check to see

private:
	//holds textures of main, mouse hover, and mouse clicked
	sf::Texture defaultTexture, mouseOverTexture, mouseDownTexture;
	bool mouseOver(void);	//returns if the mouse is over this gui object
	char *name;	//name for object
};

