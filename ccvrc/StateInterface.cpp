#include "StateInterface.h"

StateInterface::StateInterface(LogicHandler* handler){
	logicHandler = handler;
}

StateInterface::~StateInterface(void){

}

sf::Texture* getTexture(int index_of_texture){
	//return logicHandler.
}

std::vector<GuiObject*>* getGuiList(void){

}

std::vector<sf::Sprite*>* getFgList(void){

}

std::vector<sf::Sprite*>* getMgList(void){

}

std::vector<sf::Sprite*>* getBgList(void){

}
