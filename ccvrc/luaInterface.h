#pragma once

#include <iostream>
#include <stdio.h>

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

class GameState;
class LuaInterface{

public:
	LuaInterface(const char * path, GameState *);
	~LuaInterface(void);
	void luaInit(void);
	void luaEvent(std::string target, std::string type);
	void luaError(const char * type);
	virtual void addPolySprite(int intex, int x, int y, int w, int h, int color){
		printf("not so good...");
	}

private:
	lua_State* luaState;
};