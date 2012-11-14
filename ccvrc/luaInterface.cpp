#include "luaInterface.h"

luaInterface::luaInterface(const char * path){
	luaState = lua_open();
	luaL_openlibs(luaState);

	//register functions

	luaL_dofile(luaState, path);
}

luaInterface::~luaInterface(void){
	lua_close(luaState);
}

bool luaInterface::luaInit(void){
	bool status;

	lua_getglobal(luaState, "init");

	lua_call(luaState, 0, 1);
	status = lua_toboolean(luaState, -1);
	lua_pop(luaState, 1);

	return status;
}

void luaInterface::luaEvent(int target, const char * type){
	lua_getglobal(luaState, "event");

	lua_pushnumber(luaState, target);
	lua_pushstring(luaState, type);

	lua_call(luaState, 2, 0);
	lua_pop(luaState, 1);
}

void luaInterface::luaError(const char * type){
	lua_getglobal(luaState, "error");

	lua_pushstring(luaState, type);

	lua_call(luaState, 1, 0);
	lua_pop(luaState, 1);
}

int luaInterface::addSprite(lua_State* ls){
	return 0;
}