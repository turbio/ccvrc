#pragma once
#include <SFML\Graphics.hpp>

class Sprite{
public:
	Sprite(std::string index);    //sets the index to the given string
	~Sprite(void);

	std::string getIndex(void){
		return index;
	}

	void operator =(sf::Drawable * drawable){
		setDrawObj(drawable);
	}
	void setDrawObj(sf::Drawable* drawable){
		drawObject = drawable;
	}
	sf::Drawable* getDrawObj(void){
		return drawObject;
	}

private:
	sf::Drawable * drawObject;    //this is what will be drawn
	std::string index;    //holds the index or name of the object, this makes it easy to recognize, organize and identify especialy in lua
};