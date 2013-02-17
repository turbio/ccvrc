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
}