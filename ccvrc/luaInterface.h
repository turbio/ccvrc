#pragma once

#include <iostream>
#include <stdio.h>

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

class luaInterface{

public:
	luaInterface(const char * path);
	~luaInterface(void);
	bool luaInit(void);
	void luaEvent(int target, const char * type);
	void luaError(const char * type);

protected:
	virtual void addSprite();

private:
	lua_State* luaState;
};