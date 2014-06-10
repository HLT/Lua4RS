#ifndef LUACORE_H
#define LUACORE_H

#include <iostream>
#include <string.h>
#include <map>

#include <retroshare/rsplugin.h>

#include "LuaList.h"
#include "../Lua4RSNotify.h"
#include "../Lua4RSTickThread.h"

class lua_State;

typedef std::map<std::string, std::string>  parameterMap;

class Lua4RSWidget;

class LuaCore
{
public:
    LuaCore();
    ~LuaCore();

    static LuaCore* getInstance();
    static void shutDown();

    // invoke lua
    void runLuaByString(const std::string& code);
    void runLuaByName(const std::string& name);
    void runLuaByNameWithParams(const std::string& name, parameterMap paramMap);

    // getter & setter
    Lua4RSWidget* getUI();
    void setUi(Lua4RSWidget* ui);
    RsPeers *peers() const;
    void setPeers(RsPeers *peers);
    Lua4RSNotify *notify() const;
    LuaList* codeList() const;

private:
    void reportLuaErrors(lua_State *L, int status);

    static LuaCore* _instance;

    const std::string _folderName;
    std::string _path;

    lua_State* L;

    Lua4RSWidget* _ui;
    Lua4RSNotify* _notify;
    Lua4RSTickThread* _thread;
    LuaList* _luaList;

    RsPeers* _peers;
};

#endif // LUACORE_H
