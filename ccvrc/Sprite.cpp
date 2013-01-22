#include "Sprite.h"

Sprite::Sprite(std::string _index, sf::Sprite * _sprite){
	index = _index;
	interpolate = false;

	sprite = _sprite;
	isSprite = true;
	isPoly = false;
	isText = false;
}

Sprite::Sprite(std::string _index, sf::Text * _sprite){
	index = _index;
	interpolate = false;

	text = _sprite;
	isSprite = false;
	isPoly = false;
	isText = true;
}

Sprite::Sprite(std::string _index, sf::ConvexShape * _sprite){
	index = _index;
	interpolate = false;

	poly = _sprite;
	isSprite = false;
	isPoly = true;
	isText = false;
}

Sprite::~Sprite(void){
	//delete drawable;
}

void Sprite::setInterpolate(int _destX, int _destY, float _speed){
	destX = _destX;
	destY = _destY;
	speed = _speed * .00001f;
	interpolate = true;
	progress = 0;
	if(isSprite){
		oldX = sprite->getPosition().x;
		oldY = sprite->getPosition().y;
	}
	distance = abs(destX - oldX) + abs(destY - oldY);
}

void Sprite::update(double delta){
	if(interpolate){
		progress += (speed * delta) / distance;
		if(isSprite){
			sprite->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
		}

		if(progress >= 1){
			progress = 0;
			sprite->setPosition(destX, destY);
			interpolate = false;
		}
	}
}