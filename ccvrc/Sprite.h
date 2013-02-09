//oh gawd this whole class is horible, don't look at it...

#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>

class Sprite{
public:
	Sprite(std::string index, sf::Sprite*, int, int);
	Sprite(std::string index, sf::Text*);
	Sprite(std::string index, sf::ConvexShape*);
	~Sprite(void);
	void setInterpolate(int destX, int destY, float speed);
	virtual void update(double delta);
	bool isCollision(int x, int y);
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

	float getX(void){
		return xpos;
	}float getY(void){
		return ypos;
	}

	bool checkArrived(void);

private:
	sf::Sprite * sprite;
	sf::Text * text;
	sf::ConvexShape * poly;
	bool isSprite, isText, isPoly;
	std::string index;
	float xpos, ypos, scaleX, scaleY;

	//used for interpolation
	bool interpolate;
	int destX, destY, oldX, oldY;
	float speed, progress, distance;
	bool hasArrived;
};