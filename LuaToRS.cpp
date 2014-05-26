#include "LuaCore.h"
#include "Lua4RSMainWidget.h"

extern "C" {
    // helper
    int inline getArgCount(lua_State* L)
    {
        return lua_gettop(L);
    }

    void report_errors(lua_State *L, int status)
    {
        if ( status!=0 ) {
            std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1); // remove error message
        }
    }

    // functions

    int rs_print(lua_State* L)
    {
        int argc = getArgCount(L);

        if(argc > 0)
            for ( int n=1; n<=argc; ++n )
            {
                const std::string s(lua_tostring(L, n));
                LuaCore::getInstance()->getUI()->appendOutput(s);
            }

        return 0;
    }

    int rs_clear(lua_State* /*L*/)
    {
        LuaCore::getInstance()->getUI()->clearOutput();
        return 0;
    }
}
