#include "StateHandler.h"

StateHandler::StateHandler(int *w, int *h, std::vector<sf::Texture*>* tl, std::vector<GuiObject*>* gl){
	width = w;
	height = h;
	textureList = tl;
	guiList = gl;
}


StateHandler::~StateHandler(void){

}

sf::Texture* StateHandler::getTexture(int i){
	return textureList->at(i);
}

std::vector<sf::Texture*>* StateHandler::getTextureList(void){
	return textureList;
}

void StateHandler::setState(int index){
	currentState = states.at(index);
}

GameState* StateHandler::getCurrentState(){
	return currentState;
}

void StateHandler::setupGui(void){
	GameState * titleScreen;
}

void StateHandler::loading(sf::RenderWindow *window, std::string message){
	gameLoaded = false;

	sf::Font loadfont;
	loadfont.loadFromFile("res/font.ttf");

	sf::Text text(message, loadfont, 128);
	
	window->clear(sf::Color(20, 180, 255));

	text.setPosition(text.getCharacterSize() + 5, 5 + (*height / 2));
	text.setColor(sf::Color(0, 130, 205));
	window->draw(text);

	text.setPosition(text.getCharacterSize(), *height / 2);
	text.setColor(sf::Color().Black);
	window->draw(text);

	window->display();
	
}

void StateHandler::loaded(){

}