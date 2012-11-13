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

bool luaInterface::luaInit(){
	return true;
}

void luaInterface::luaEvent(int target, const char * type){

}

void luaInterface::luaError(const char * type){

}