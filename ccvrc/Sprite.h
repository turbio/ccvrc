#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>

class Sprite{
public:
	Sprite(std::string index, sf::Sprite*);
	Sprite(std::string index, sf::Text*);
	Sprite(std::string index, sf::ConvexShape*);
	~Sprite(void);
	void setInterpolate(int destX, int destY, float speed);
	virtual void update(double delta);
	std::string getIndex(void){
		return index;
	}

	sf::Drawable* getDrawable(void){
		if(isSprite){
			return sprite;
		}else if(isText){
			return text;
		}else if(isPoly){
			return poly;
		}
	}

private:
	sf::Sprite * sprite;
	sf::Text * text;
	sf::ConvexShape * poly;
	bool isSprite, isText, isPoly;
	std::string index;    //holds the index or name of the object, this makes it easy to recognize, organize and identify especialy in lua

	//used for interpolation
	bool interpolate;
	int destX, destY, oldX, oldY;
	float speed, progress, distance;
};