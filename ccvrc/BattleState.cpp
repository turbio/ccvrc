#include "BattleState.h"
#include "StateHandler.h"

BattleState::BattleState(StateHandler* handler, sf::RenderWindow * window) : GameState("battle", "lua/battle.lua", handler, window){

}

BattleState::~BattleState(void){
	
}

void BattleState::update(double delta){
	GameState::update(delta);
}