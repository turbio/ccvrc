#include "MatchSetup.h"
#include "StateHandler.h"

#define PANE_OFFSET 50
#define CHARACTER_ICON_SIZE 64.0
#define CENTA_POSITION_OFFSET 10, 20

MatchSetup::MatchSetup(StateHandler* handler, sf::RenderWindow * window) : GameState("match_setup", "lua/match_setup.lua", handler, window){

}

MatchSetup::~MatchSetup(void){

}

void MatchSetup::update(double delta){
	GameState::update(delta);
}