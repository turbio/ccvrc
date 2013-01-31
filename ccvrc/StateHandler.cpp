#include "StateHandler.h"
#include "LogicHandler.h"

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
}

void StateHandler::keyPressed(int key){
	if(key == sf::Keyboard::Tilde){
		std::cout << "reseting current state" << std::endl;
		resetCurrentSate();
	}else{
		currentState->keyDown(key);
	}
}

void StateHandler::mousePressed(int btn){
	currentState->mouseDown(btn);

	//TODO check for mouse touching sprite and send event to lua / gamestate
}

void StateHandler::setState(int index){
	currentState = states.at(index);
	currentState->callState();
}

void StateHandler::setState(std::string index){
	for(int i = 0; i < states.size(); i++){
		if(states.at(i)->getIndex() == index){
			//delete currentState;

		}
	}
}

GameState* StateHandler::getCurrentState(){
	return currentState;
}

void StateHandler::setupGui(void){

	GameState * titleScreen = new GuiTitleScreen(this);
	states.push_back(titleScreen);

	GameState * matchSetup = new MatchSetup(this);
	states.push_back(matchSetup);

	currentState = titleScreen;
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