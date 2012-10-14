#include "GameState.h"

GameState::GameState(std::string _name, StateHandler* _stateHandler){
	name = _name;
	stateHandler = _stateHandler;
}

GameState::~GameState(void){

}

void GameState::update(void){

}

std::vector<GuiObject*>* GameState::getGuiList(void){
	return &objects;
}