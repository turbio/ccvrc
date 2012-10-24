#include "StateHandler.h"
#include "LogicHandler.h"

StateHandler::StateHandler(int* w, int* h, LogicHandler* _handler){
	width = w;
	height = h;
	logicHandler = _handler;
}


StateHandler::~StateHandler(void){

}

void StateHandler::setState(int index){
	currentState = states.at(index);
}

GameState* StateHandler::getCurrentState(){
	return currentState;
}

void StateHandler::setupGui(void){
	GameState * titleScreen = new GuiTitleScreen(this);
	//states.push_back(titleScreen);
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

//get functions for states:
sf::Texture* StateHandler::getTexture(int index){
	return logicHandler->getTexture(index);
}

std::vector<GuiObject*>* StateHandler::getGuiList(void){
	return logicHandler->getGuiList();
}