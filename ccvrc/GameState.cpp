#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(std::string name, std::string _path, StateHandler* _stateHandler, sf::RenderWindow * w){
	stateHandler = _stateHandler;
	stateName = name;
	luaPath = _path;

	window = w;

	width = 800;
	height = 600;
}

GameState::~GameState(void){

}

void GameState::keyDown(int key){
	luaInterface->luaEvent("keydown", std::to_string(key));
}
void GameState::mouseDown(int btn){
	luaInterface->luaEvent("mousedown", std::to_string(btn));

	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	for(int i = 0; i < sprites.size(); i++){
		if(sprites.at(i)->isCollision(mousePos.x, mousePos.y)){
			std::printf("clicked\n");
			luaInterface->luaEvent(sprites.at(i)->getIndex(), "clicked");
		}
	}
}

void GameState::update(double delta){
	for(int i = 0; i < sprites.size(); i++){
		sprites.at(i)->update(delta);

		if(sprites.at(i)->checkArrived()){
			luaInterface->luaEvent(sprites.at(i)->getIndex(), "arrived");
		}
	}
}

void GameState::callState(void){
	luaInterface = new LuaInterface(luaPath.c_str(), this);
	luaInterface->luaInit();
}

void GameState::closeState(void){
	delete luaInterface;
}

void GameState::resetState(void){
	
	for(int i = 0; i < sprites.size(); i++){
		delete sprites.at(i);
	}
	sprites.clear();

	callState();
}

std::string GameState::getProp(std::string target, std::string type){
	if(target == "stage" || target == "" || target == "window" || target == "screen" || target == "null"){
		if(type == "width"){
			return std::to_string((long long)width);    //TODO FIX THIS NOAW;
		}else if(type == "height"){
			return std::to_string((long long)height);    //TODO FIIIXIXIX THISS TOOOO SFSA+ FSEGE
		}if(type == "mousex" || type == "mouseX"){
			sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
			return std::to_string(localPosition.x);
		}if(type == "mousey" || type == "mouseY"){
			sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
			return std::to_string(localPosition.y);
		}
	}else{
		if(type == "width"){
			return 0;
		}else if(type == "height"){
			return 0;
		}if(type == "xpos" || type == "x"){
			return std::to_string(findSprite(target)->getX());
			std::printf("xolo");
		}if(type == "ypos" || type == "y"){
			return std::to_string(findSprite(target)->getY());
		}
	}

	return "err";
}

void GameState::setProp(std::string target, std::string type){
	if(target == "stage" || target == "" || target == "window" || target == "screen" || target == "null"){

	}else{
		if(type == "xpos" || type == "x"){
			findSprite(target)->getX();
		}if(type == "ypos" || type == "y"){
			findSprite(target)->getY();
		}
	}
}

void GameState::addSprite(Sprite* sprite){
	if(sprite->getIndex() == "null" || sprite->getIndex() == ""){
		printf("the sprite did not have a name / index\n");
		return;
	}
	for(int i = 0; i < sprites.size(); i++){
		if(sprite->getIndex() == sprites.at(i)->getIndex()){
			printf("a sprite with this name / index already excists\n");
			return;
		}
	}

	sprites.push_back(sprite);
}

void GameState::addSprite(std::string index, int xpos, int ypos, std::string src, int width, int height){
	sf::Sprite * sprite = new sf::Sprite();

	sprite->setTexture(*stateHandler->getTexture(src));
	sprite->setPosition(xpos, ypos);

	Sprite * spr = new Sprite(index, sprite, width, height);

	addSprite(spr);
}



void GameState::addPolySprite(std::string index, int x, int y, int color, int length, int * vertexData){

	sf::ConvexShape * poly = new sf::ConvexShape();

	poly->setPointCount(length / 2);
	for(int i = 0; i < length - 2; i += 2){
		poly->setPoint(((i + 2) / 2) - 1, sf::Vector2f(vertexData[i], vertexData[1 + i]));
	}

	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	poly->setFillColor(sf::Color(r, g, b));
	poly->setPosition(x, y);

	Sprite * spr = new Sprite(index, poly);

	addSprite(spr);
}

void GameState::addStringSprite(std::string index, int x, int y, int size, std::string text, int color){
	sf::Text * spr = new sf::Text(text, *stateHandler->getFont(), size);

	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	spr->setColor(sf::Color(r, g, b));
	spr->setPosition(x, y);

	Sprite * sprite = new Sprite(index, spr);

	addSprite(sprite);
}

void GameState::interpolateSprite(std::string target, int destX, int destY, float speed){
	findSprite(target)->setInterpolate(destX, destY, speed);
}

void GameState::setState(std::string state){
	stateHandler->setState(state);
}

Sprite* GameState::findSprite(std::string target){
	for(int i = 0; i < sprites.size(); i++){
		if(sprites.at(i)->getIndex() == target){
			return sprites.at(i);
		}
	}

	std::cout << "could not find sprite" << std::endl;
	return NULL;
}