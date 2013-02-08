#include "LuaInterface.h"
#include "GameState.h"

int luaGetProp(lua_State*);
int luaAddPolySprite(lua_State*);
int luaAddStringSprite(lua_State*);
int luaAddSprite(lua_State*);
int luaSetProp(lua_State*);
int luaLinearInterpolate(lua_State*);
int luaCallState(lua_State*);

GameState * luaInterface; 

LuaInterface::LuaInterface(const char * path, GameState * _interface){
	luaInterface = _interface;
	luaState = lua_open();
	luaL_openlibs(luaState);

	//register functions
	lua_register(luaState, "addPolySprite", luaAddPolySprite);
	lua_register(luaState, "addStringSprite", luaAddStringSprite);
	lua_register(luaState, "addSprite", luaAddSprite);
	lua_register(luaState, "getProp", luaGetProp);
	lua_register(luaState, "linearInterpolate", luaLinearInterpolate);
	lua_register(luaState, "setProp", luaSetProp);
	lua_register(luaState, "callState", luaCallState);

	luaL_dofile(luaState, path);
}

LuaInterface::~LuaInterface(void){
	lua_close(luaState);
	delete luaState;
}

void LuaInterface::luaInit(void){

	lua_getglobal(luaState, "init");

	lua_call(luaState, 0, 0);
	lua_pop(luaState, 1);
}

void LuaInterface::luaEvent(std::string target, std::string type){
	lua_getglobal(luaState, "event");

	lua_pushstring(luaState, target.c_str());
	lua_pushstring(luaState, type.c_str());

	lua_pcall(luaState, 2, 0, 0);
}

void LuaInterface::luaError(const char * type){

	lua_getglobal(luaState, "error");

	lua_pushstring(luaState, type);

	lua_call(luaState, 1, 0);
	lua_pop(luaState, 1);
}

int luaAddPolySprite(lua_State* l){
	//takes arguments int index, int x, int y, int width, int height, and optionaly int color

	int color = 0xff0000;
	int xpos = 0, ypos = 0;
	int argCount = lua_gettop(l);
	std::string index = "null";

	index = lua_tostring(l, 1);	//get index (1st param)
	xpos = lua_tonumber(l, 2);
	ypos = lua_tonumber(l, 3);
	color = lua_tonumber(l, 4);

	int * vertexData = new int[argCount - 4];

	for(int i = 0; i < argCount - 4; i++){
		vertexData[i] = 0;
		vertexData[i] = lua_tonumber(l, i + 5);
	}

	luaInterface->addPolySprite(index, xpos, ypos, color, argCount - 2, vertexData);

	return 0;
}

int luaAddStringSprite(lua_State* l){
	//takes parameters int index, int x, int y, and optionaly string txt, int color

	std::string text = "NULL";
	int xpos, ypos, color = 0xff00ff, size = 128;
	int paramCount = lua_gettop(l);
	std::string index = "null";
	
	if(paramCount < 4){
		printf("error: too few arguments");
		return 0;
	}else if(paramCount > 6){
		printf("caution: too many arguments");
	}

	index = lua_tostring(l, 1);
	xpos = lua_tonumber(l, 2);
	ypos = lua_tonumber(l, 3);
	size = lua_tonumber(l, 4);
	text = lua_tostring(l, 5);
	if(paramCount > 5){
		color = lua_tonumber(l, 6);
	}

	luaInterface->addStringSprite(index, xpos, ypos, size, text, color);

	return 0;
}


int luaGetProp(lua_State* l){
	std::string type, prop, target;

	target = lua_tostring(l, 1);
	type = lua_tostring(l, 2);

	prop = luaInterface->getProp(target, type);

	lua_pushstring(l, prop.c_str());

	return 1;
}

int luaAddSprite(lua_State* l){
	int xPos = 0, yPos = 0, width = 1, height = 1;
	std::string index = "null";
	std::string texture = "null";

	switch (lua_gettop(l)){
	case 6:{
		height = lua_tonumber(l, 6);
			}
	case 5:{
		width = lua_tonumber(l, 5);
			}
	case 4:{
		texture = lua_tostring(l, 4);
			}
	case 3:{
		yPos = lua_tonumber(l, 3);
		   }
	case 2:{
		xPos = lua_tonumber(l, 2);
		   }
	case 1:{
		index = lua_tostring(l, 1);
		   }
	}

	luaInterface->addSprite(index, xPos, yPos, texture, width, height);
	return 0;
}

int luaLinearInterpolate(lua_State* l){
	std::string target = "null";
	int destX = 0, destY = 0;
	float speed = 1.0f;

	switch (lua_gettop(l)){
	case 4:{
		speed = lua_tonumber(l, 4);
		   }
	case 3:{
		destY = lua_tonumber(l, 3);
		   }
	case 2:{
		destX = lua_tonumber(l, 2);
		   }
	case 1:{
		target = lua_tostring(l, 1);
		   }
	}

	luaInterface->interpolateSprite(target, destX, destY, speed);
	return 0;
}

int luaCallState(lua_State* l){
	std::string state = "null";

	state = lua_tostring(l, 1);

	luaInterface->setState(state);

	return 0;
}

int luaSetProp(lua_State* l){
	return 0;
}