#include "MatchSetup.h"
#include "StateHandler.h"

sf::Sprite* rightPane;
sf::Sprite* background;

MatchSetup::MatchSetup(StateHandler* handler) : GameState("match_setup", handler){
	rightPane = new sf::Sprite();
	rightPane->setTexture(*stateHandler->getTexture(2));
	fgList.push_back(rightPane);

	background = new sf::Sprite();
	background->setTexture(*stateHandler->getTexture(0));
	bgList.push_back(background);
}

MatchSetup::~MatchSetup(void){

}

void MatchSetup::callState(void){
	
}

void MatchSetup::update(double delta){
	
}