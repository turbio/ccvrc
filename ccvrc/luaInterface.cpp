#include "LuaInterface.h"
#include "GameState.h"

int luaAddPolySprite(lua_State*);
GameState * luaInterface; 

LuaInterface::LuaInterface(const char * path, GameState * _interface){
	luaInterface = _interface;
	luaState = lua_open();
	luaL_openlibs(luaState);

	//register functions
	lua_register(luaState, "addPolySprite", luaAddPolySprite);
	lua_register(luaState, "addStringSprite", addStringSprite);
	lua_register(luaState, "addSprite", addSprite);

	luaL_dofile(luaState, path);
}

LuaInterface::~LuaInterface(void){
	lua_close(luaState);
}

bool LuaInterface::luaInit(void){
	bool status;

	lua_getglobal(luaState, "init");

	lua_call(luaState, 0, 1);
	status = lua_toboolean(luaState, -1);
	lua_pop(luaState, 1);

	return status;
}

void LuaInterface::luaEvent(int target, const char * type){
	lua_getglobal(luaState, "event");

	lua_pushnumber(luaState, target);
	lua_pushstring(luaState, type);

	lua_call(luaState, 2, 0);
	lua_pop(luaState, 1);
}

void LuaInterface::luaError(const char * type){

	lua_getglobal(luaState, "error");

	lua_pushstring(luaState, type);

	lua_call(luaState, 1, 0);
	lua_pop(luaState, 1);
}

int luaAddPolySprite(lua_State* l){
	//takes arguments int index, int x, int y, int width, int height, and optionaly int color

	int index = 0, xpos = 0, ypos = 0, width = 0, height = 0, color = -1;
	int argCount = lua_gettop(l);

	if(argCount < 5){	//need at least 5 parameters (index, x, y, width, height)
		//error to few arguments
		printf("error: too few arguments\n");
		return 0;
	}else if(argCount > 6){
		//error to many arguments
		printf("caution: too many arguments\n");
	}

	index = lua_tonumber(l, 1);	//get index (1st param)
	xpos = lua_tonumber(l, 2);	//get x position (2nd param)
	ypos = lua_tonumber(l, 3);	//get y position (3rd param)
	width = lua_tonumber(l, 4);	//get width of shape 4th
	height = lua_tonumber(l, 5);	//get height of shape
	if(argCount >= 6){
		color = lua_tonumber(l, 6);
	}

	//std::printf("\ninfo: %d %d %d %d %d %d\n", index, xpos, ypos,
	//	width, height, color);

	luaInterface->addPolySprite(index, xpos, ypos, width, height, color);

	return 0;
}

int LuaInterface::addStringSprite(lua_State* l){
	//takes parameters int index, int x, int y, and optionaly string txt, int color

	std::string text = "NULL";
	int index, xpos, ypos, color = -1;
	int paramCount = lua_gettop(l);
	
	if(paramCount < 3){
		printf("error: too few arguments");
		return 0;
	}else if(paramCount > 5){
		printf("caution: too many arguments");
	}

	index = lua_tonumber(l, 1);
	xpos = lua_tonumber(l, 2);
	ypos = lua_tonumber(l, 3);
	text = lua_tostring(l, 4);
	if(paramCount > 4){
		color = lua_tonumber(l, 5);
	}


	printf("params: %d %d %d %s %d\n", index, xpos, ypos, text.c_str(), color);

	return 0;
}

int LuaInterface::addSprite(lua_State* l){
	return 0;
}