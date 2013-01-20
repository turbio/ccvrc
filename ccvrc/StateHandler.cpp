#include "StateHandler.h"
#include "LogicHandler.h"

bool autoReset;

StateHandler::StateHandler(int * w, int * h, LogicHandler * _handler){
	width = *w;
	height = *h;

	logicHandler = _handler;

	loadfont = new sf::Font();
	loadfont->loadFromFile("res/font.ttf");
}


StateHandler::~StateHandler(void){

}

void StateHandler::update(double delta){
	if(currentState != NULL){
		currentState->update(delta);
	}

	if(autoReset){
		resetCurrentSate();
	}
}

void StateHandler::keyPressed(int key){
	if(key == sf::Keyboard::R){
		std::cout << "reseting current state" << std::endl;
		resetCurrentSate();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
			std::cout << "auto reset toggled" << std::endl;
			if(autoReset)
				autoReset = false;
			else
				autoReset = true;
		}
	}
}

void StateHandler::setState(int index){
	currentState = states.at(index);
	currentState->callState();
}

GameState* StateHandler::getCurrentState(){
	return currentState;
}

void StateHandler::setupGui(void){

	GameState * titleScreen = new GuiTitleScreen(this);
	currentState = titleScreen;

	GameState * matchSetup = new MatchSetup(this);

	states.push_back(titleScreen);
	states.push_back(matchSetup);
}

void StateHandler::loading(sf::RenderWindow *window, std::string message){
	gameLoaded = false;

	sf::Text text(message, *loadfont, 128);
	
	window->clear(sf::Color(20, 180, 255));

	text.setPosition(text.getCharacterSize() + 5, 5 + (height / 2));
	text.setColor(sf::Color(0, 130, 205));
	window->draw(text);

	text.setPosition(text.getCharacterSize(), height / 2);
	text.setColor(sf::Color().Black);
	window->draw(text);

	window->display();
	
}

sf::Font* StateHandler::getFont(void){
	return loadfont;
}

void StateHandler::loaded(){
	
}

//get functions for states:
sf::Texture* StateHandler::getTexture(std::string src){
	return logicHandler->getTexture(src);
}