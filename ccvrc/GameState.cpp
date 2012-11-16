#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(const char * _path, StateHandler* _stateHandler) : LuaInterface(_path){
	stateHandler = _stateHandler;
}

GameState::~GameState(void){
	//getGuiList()->clear();
}

void GameState::update(double delta){

}

void GameState::callState(void){

}

void GameState::addPolySprite(int intex, int x, int y, int w, int h, int color){
	sf::ConvexShape * poly;

	poly->setPointCount(4);
	poly->setPoint(0, sf::Vector2f(x, y));
	poly->setPoint(1, sf::Vector2f(x + w, y));
	poly->setPoint(2, sf::Vector2f(x + w, y + h));
	poly->setPoint(3, sf::Vector2f(x, y + h));
	poly->setFillColor(sf::Color(color % 256, (color / 256) % 256, ((color / 256) / 256) % 256));

	fgList.push_back(poly);
}