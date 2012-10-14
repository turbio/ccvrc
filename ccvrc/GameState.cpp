#include "GameState.h"

GameState::GameState(std::string _name){
	name = _name;
}

GameState::~GameState(void){

}

void GameState::update(void){

}

std::vector<GuiObject*>* GameState::getGuiList(void){
	return &objects;
}