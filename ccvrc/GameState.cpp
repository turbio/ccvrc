#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(std::string _path, StateHandler* _stateHandler){
	stateHandler = _stateHandler;
	luaInterface = new LuaInterface(_path.c_str(), this);
	luaPath = _path;

	width = 800;
	height = 600;
}

GameState::~GameState(void){

}

void GameState::update(double delta){

}

void GameState::callState(void){

}

void GameState::resetState(void){
	for(int i = 0; i < sprites.size(); i++){
		delete sprites.at(i);
	}
	sprites.clear();
	delete luaInterface;
	luaInterface = new LuaInterface(luaPath.c_str(), this);
}

std::string GameState::getProp(int target, std::string type){
	if(target < 0){
		if(type == "width"){
			return std::to_string((long long)width);    //TODO FIX THIS NOAW;
		}else if(type == "height"){
			return std::to_string((long long)height);    //TODO FIIIXIXIX THISS TOOOO SFSA+ FSEGE
		}
	}else{
		if(type == "width"){
			return 0;
		}else if(type == "height"){
			return 0;
		}
	}

	return "err";
}

void GameState::addSprite(std::string index, sf::Drawable* draw){
	if(index == "null" || index == ""){
		printf("the sprite did not have a name / index\n");
		return;
	}
	for(int i = 0; i < sprites.size(); i++){
		if(index == sprites.at(i)->getIndex()){
			printf("a sprite with this name / index already excists\n");
			return;
		}
	}

	Sprite * sprite = new Sprite(index);
	*sprite = draw;

	sprites.push_back(sprite);
}

void GameState::addSprite(std::string index, int xpos, int ypos, std::string src, int width, int height){
	sf::Sprite * sprite = new sf::Sprite();

	sprite->setPosition(xpos, ypos);
	sprite->setTexture(*stateHandler->getTexture(src));
	
	if(width != 0 && height == 0){
		sprite->scale((float)width / sprite->getTexture()->getSize().x, 1);
	}else if(height != 0 && width == 0){
		sprite->scale(1, (float)height /  sprite->getTexture()->getSize().y);
	}else if(width == 0 && height == 0){
		sprite->scale(1, 1);
	}else{
		sprite->scale((float)width / sprite->getTexture()->getSize().x, (float)height /  sprite->getTexture()->getSize().y);
	}

	addSprite(index, sprite);
}



void GameState::addPolySprite(int index, int color, int length, int * vertexData){

	sf::ConvexShape * poly = new sf::ConvexShape();

	poly->setPointCount(length / 2);

	for(int i = 0; i < length; i += 2){
		poly->setPoint(((i + 2) / 2) - 1, sf::Vector2f(vertexData[i], vertexData[1 + i]));
	}

	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	poly->setFillColor(sf::Color(255, 0, 255));

	addSprite("null", poly);
}

void GameState::addStringSprite(int index, int x, int y, int size, std::string text, int color){
	printf("adding string sprite: index: %d x: %d y: %d size: %d string: %s color: %d\n", index, x, y, size, text.c_str(), color);

	sf::Text * spr = new sf::Text(text, *stateHandler->getFont(), size);

	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	spr->setColor(sf::Color(r, g, b));
	spr->setPosition(x, y);

	addSprite("null", spr);
}