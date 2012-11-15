#include "luaInterface.h"

LuaInterface::LuaInterface(const char * path){
	luaState = lua_open();
	luaL_openlibs(luaState);

	//register functions
	lua_register(luaState, "addPolySprite", addPolySprite);
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

int LuaInterface::addPolySprite(lua_State* l){
	//takes arguments int index, int x, int y, int width, int height, and optionaly int color

	int argCount = lua_gettop(l);

	
	if(argCount < 5){	//need at least 5 parameters (index, x, y, width, height)
		//error to few arguments
		printf("error to few arguments\n");
		return 0;
	}

	int index = -1, xpos = -1, ypos = -1, width = -1, height = -1, color = -1;

	index = lua_tonumber(l, 1);	//get index (1st param)
	xpos = lua_tonumber(l, 2);	//get x position (2nd param)
	ypos = lua_tonumber(l, 3);	//get y position (3rd param)
	width = lua_tonumber(l, 4);	//get width of shape 4th
	height = lua_tonumber(l, 5);	//get height of shape
	if(argCount >= 6){
		color = lua_tonumber(l, 6);
	}

	std::printf("\ninfo: %d %d %d %d %d %d", index, xpos, ypos, width, height, color);

	return 0;
}

int LuaInterface::addStringSprite(lua_State* l){
	return 0;
}

int LuaInterface::addSprite(lua_State* l){
	return 0;
}