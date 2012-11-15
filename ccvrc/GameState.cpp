#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(const char * _path, StateHandler* _stateHandler){
	stateHandler = _stateHandler;
	luaInterface = new LuaInterface(_path);
}

GameState::~GameState(void){
	//getGuiList()->clear();
}

void GameState::update(double delta){

}

void GameState::callState(void){

}