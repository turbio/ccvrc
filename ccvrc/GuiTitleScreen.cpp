#include "GuiTitleScreen.h"

GuiObject* titleScreenBg;

GuiTitleScreen::GuiTitleScreen(StateHandler* handler) : GameState("title_screen", handler){
	titleScreenBg = new GuiObject("title screen");
	//titleScreenBg->setTexture(*);
	//getTextureList();
	setState(0);
	//titleScreenBg->setPosition(0, 0);
	//getGuiList()->push_back(titleScreenBg);
}

GuiTitleScreen::~GuiTitleScreen(void){
	
}

void GuiTitleScreen::update(double delta){

}