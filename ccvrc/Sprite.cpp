#include "Sprite.h"

Sprite::Sprite(std::string _index, sf::Sprite * _sprite, int xs, int ys){
	index = _index;
	interpolate = false;
	hasArrived = false;
	scaleX = xs;
	scaleY = ys;

	sprite = _sprite;
	isSprite = true;
	isPoly = false;
	isText = false;

	xpos = _sprite->getPosition().x;
	ypos = _sprite->getPosition().y;

	if(xs != 0 && ys == 0){
		sprite->scale((float)xs / sprite->getTexture()->getSize().x, 1);
	}else if(xs == 0 && ys != 0){
		sprite->scale(1, (float)ys / sprite->getTexture()->getSize().y);
	}else if(xs == 0 && ys == 0){

	}else{
		sprite->scale((float)xs / sprite->getTexture()->getSize().x, (float)ys /  sprite->getTexture()->getSize().y);
	}
}

Sprite::Sprite(std::string _index, sf::Text * _sprite){
	index = _index;
	interpolate = false;
	hasArrived = false;

	text = _sprite;
	isSprite = false;
	isPoly = false;
	isText = true;

	xpos = _sprite->getPosition().x;
	ypos = _sprite->getPosition().y;
}

Sprite::Sprite(std::string _index, sf::ConvexShape * _sprite){
	index = _index;
	interpolate = false;
	hasArrived = false;

	poly = _sprite;
	isSprite = false;
	isPoly = true;
	isText = false;

	xpos = _sprite->getPosition().x;
	ypos = _sprite->getPosition().y;
}

Sprite::~Sprite(void){
	//delete drawable;
}

bool Sprite::isCollision(int x, int y){
	if(isPoly){
		return poly->getTextureRect().contains(x - xpos, y - ypos);
	}if(isText){
		return false;
	}else if(isSprite){
		return sprite->getLocalBounds().contains((x - xpos) * ((float)scaleX / sprite->getTexture()->getSize().x),
			(y - ypos) * ((float)scaleY / sprite->getTexture()->getSize().y));
	}

	return false;
}

void Sprite::setInterpolate(int _destX, int _destY, float _speed){
	hasArrived = false;
	destX = _destX;
	destY = _destY;
	speed = _speed * .00001f;
	interpolate = true;
	progress = 0;
	if(isSprite){
		oldX = sprite->getPosition().x;
		oldY = sprite->getPosition().y;
	}
	if(isText){
		oldX = text->getPosition().x;
		oldY = text->getPosition().y;
	}
	if(isPoly){
		oldX = poly->getPosition().x;
		oldY = poly->getPosition().y;
	}
	distance = abs(destX - oldX) + abs(destY - oldY);
}

void Sprite::update(double delta){
	if(interpolate){
		progress += (speed * delta) / distance;
		if(isSprite){
			sprite->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
			xpos = sprite->getPosition().x;
			ypos = sprite->getPosition().y;
		}
		if(isText){
			text->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
			xpos = text->getPosition().x;
			ypos = text->getPosition().y;
		}
		if(isPoly){
			poly->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
			xpos = poly->getPosition().x;
			ypos = poly->getPosition().y;
		}

		if(progress >= 1){
			xpos = destX;
			ypos = destY;

			if(isSprite){
				sprite->setPosition(destX, destY);
			}
			if(isText){
				text->setPosition(destX, destY);
			}
			if(isPoly){
				poly->setPosition(destX, destY);
			}

			progress = 0;
			interpolate = false;

			hasArrived = true;
		}
	}
}

bool Sprite::checkArrived(void){
	if(hasArrived && !interpolate && progress == 0){

		hasArrived = false;
		return true;
	}

	return false;
}