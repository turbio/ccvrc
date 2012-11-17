#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(const char * _path, StateHandler* _stateHandler){
	stateHandler = _stateHandler;
	luaInterface = new LuaInterface(_path, this);
}

GameState::~GameState(void){
	//getGuiList()->clear();
}

void GameState::update(double delta){

}

void GameState::callState(void){

}

void GameState::addPolySprite(int index, int x, int y, int w, int h, int color){

	//printf("\npoly added info: %d %d %d %d %d %d \n", index, x, y, w, h, color);
	sf::ConvexShape * poly = new sf::ConvexShape();

	poly->setPointCount(4);
	poly->setPoint(0, sf::Vector2f(x, y));
	poly->setPoint(1, sf::Vector2f(x + w, y));
	poly->setPoint(2, sf::Vector2f(x + w, y + h));
	poly->setPoint(3, sf::Vector2f(x, y + h));
	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	poly->setFillColor(sf::Color(r, g, b));

	fgList.push_back(poly);
}