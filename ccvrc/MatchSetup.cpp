#include "MatchSetup.h"
#include "StateHandler.h"

#define PANE_OFFSET 50

sf::Sprite * rightPane, * leftPane, * background;
sf::Text * homeTxt, * awayTxt;
bool transIn = false;

MatchSetup::MatchSetup(StateHandler* handler) : GameState("match_setup", handler){
	rightPane = new sf::Sprite();
	rightPane->setTexture(*stateHandler->getTexture(2));
	rightPane->setPosition((*stateHandler->getWindowWidth()) - rightPane->getTexture()->getSize().x, 0);
	mgList.push_back(rightPane);

	leftPane = new sf::Sprite();
	leftPane->setTexture(*stateHandler->getTexture(2));
	leftPane->setTextureRect(sf::IntRect(leftPane->getTexture()->getSize().x,	//mirror texture horizontaly
		0, -leftPane->getTexture()->getSize().x, leftPane->getTexture()->getSize().y));
	mgList.push_back(leftPane);

	background = new sf::Sprite();
	background->setTexture(*stateHandler->getTexture(0));
	bgList.push_back(background);

	homeTxt = new sf::Text("Home", stateHandler->getFont(), 128);
	awayTxt = new sf::Text("Away", stateHandler->getFont(), 128);

	homeTxt->setPosition(0, 0);
	homeTxt->setColor(sf::Color(255, 0, 255));
	

	//text.setPosition(text.getCharacterSize() + 5, 5 + (*height / 2));
	//text.setColor(sf::Color(0, 130, 205));

	//fgList.push_back(homeTxt);
	//fgList.push_back(awayTxt);
}

MatchSetup::~MatchSetup(void){

}

void MatchSetup::callState(void){
	transIn = true;
	rightPane->setPosition(*stateHandler->getWindowWidth(), PANE_OFFSET);
	leftPane->setPosition((int)-rightPane->getTexture()->getSize().x, PANE_OFFSET);
}

void MatchSetup::update(double delta){
	if(transIn){
		rightPane->move(-0.5f, 0);
		leftPane->move(0.5f, 0);
		if(rightPane->getPosition().x < (*stateHandler->getWindowWidth()) - rightPane->getTexture()->getSize().x + 100){
			transIn = false;
		}
	}
}