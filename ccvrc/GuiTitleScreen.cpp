#include "GuiTitleScreen.h"
#include "StateHandler.h"

GuiObject* titleScreenBg;
GuiObject* logo;
sf::Text * test;

bool transition = false;
float speed = 0.0f;

GuiTitleScreen::GuiTitleScreen(StateHandler* handler, sf::RenderWindow * window) : GameState("title_screen", "lua/main_menu.lua", handler, window){

}

GuiTitleScreen::~GuiTitleScreen(void){
	
}

void GuiTitleScreen::update(double delta){
	GameState::update(delta);
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		//transition = true;
	}else if(transition){
		speed += 0.0005f;
		logo->move(0, speed);

		if(logo->getPosition().y > *stateHandler->getWindowHeight()){
			stateHandler->setState(1);
		}
	}
}