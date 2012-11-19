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
	bool luaInit(void);
	void luaEvent(int target, const char * type);
	void luaError(const char * type);
	virtual void addPolySprite(int intex, int x, int y, int w, int h, int color){
		printf("not so good...");
	}

private:
	static int addSprite(lua_State*);
	/*virtual int getPropties(lua_State*);
	virtual int setPropties(lua_State*);
	virtual int interpolate(lua_State*);
	virtual int callState(lua_State*);*/

	lua_State* luaState;
};