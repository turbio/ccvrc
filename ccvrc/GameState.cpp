#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(std::string _name, StateHandler* _stateHandler){
	name = _name;
	stateHandler = _stateHandler;
}

GameState::~GameState(void){
	//getGuiList()->clear();
}

void GameState::update(double delta){

}