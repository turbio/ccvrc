#include "GuiTitleScreen.h"
#include "StateHandler.h"

GuiObject* titleScreenBg;
GuiObject* logo;

GuiTitleScreen::GuiTitleScreen(StateHandler* handler) : GameState("title_screen", handler){
	titleScreenBg = new GuiObject("title screen");
	titleScreenBg->setTexture(*stateHandler->getTexture(0));
	titleScreenBg->setPosition(0, 0);
	stateHandler->getGuiList()->push_back(titleScreenBg);

	logo = new GuiObject("logo");
	logo->setTexture(*stateHandler->getTexture(1));
	logo->setPosition((*stateHandler->getWindowWidth() / 2) - (logo->getTexture()->getSize().x / 2), 
		(*stateHandler->getWindowHeight() / 2) - (logo->getTexture()->getSize().y / 2));
	stateHandler->getGuiList()->push_back(logo);
}

GuiTitleScreen::~GuiTitleScreen(void){
	
}

void GuiTitleScreen::update(double delta){

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		stateHandler->setState("match_setup");
	}
}