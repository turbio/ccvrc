#include "MatchSetup.h"
#include "StateHandler.h"

MatchSetup::MatchSetup(StateHandler* handler) : GameState("match_setup", handler){
	
}

MatchSetup::~MatchSetup(void){

}

void MatchSetup::update(double delta){
	stateHandler->getGuiList()->clear();
}