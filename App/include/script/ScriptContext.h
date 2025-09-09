#pragma once

#include <vector>
#include <set>

namespace RBX {
    class ScriptContext {
    private: 
        lua_State* globalState;
        RBX::Lua::ThreadRef commandLineSandbox;
        std::set<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *> > scripts;
        boost::posix_time::ptime nextPendingScripts;
        std::vector<boost::shared_ptr<RBX::Script>,std::allocator<boost::shared_ptr<RBX::Script> > > pendingScripts;
        // boost::shared_ptr<RBX::RunService> runService;
        // boost::scoped_ptr<RBX::Lua::YieldingThreads> yieldEvent;
        bool scriptsDisabled;
        // boost::shared_ptr<RBX::Stats::Item> statsItem;
        void onChangedScriptEnabled(const RBX::Reflection::PropertyDescriptor&);
        void disassociateState(RBX::Script*);
        void openState();
        void startScript(boost::shared_ptr<RBX::Script>);
        void startPendingScripts();
        void bindEnums(lua_State*);
        static void sandboxThread(lua_State*);
        static void setThreadIdentity(lua_State*, RBX::Security::Identities);
        static RBX::Security::Identities getThreadIdentity(lua_State*);
        static int print(lua_State*);
        static int tick(lua_State*);
        static int wait(lua_State*);
        static int delay(lua_State*);
        static int trustedThread(lua_State*);
        static int loadfile(lua_State*);
        static int dofile(lua_State*);
        static int settings(lua_State*);
        static int stats(lua_State*);
        static int statsitemvalue(lua_State*);
        static int onError(lua_State*);
        static void reportError(lua_State*);

    protected: 
        virtual void onServiceProvider(const RBX::ServiceProvider*, const RBX::ServiceProvider*);
        virtual void onEvent(const RBX::RunService*, RBX::Heartbeat);
        virtual void onEvent(const RBX::RunService*, RBX::RunTransition);

    public:
        // boost::scoped_ptr<LuaAllocator> allocator;
        static RBX::Reflection::BoundProp<bool,1> propScriptsDisabled;
        ScriptContext(const RBX::ScriptContext&);
        ScriptContext();
        virtual ~ScriptContext();
        std::auto_ptr<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > > call(const RBX::Lua::FunctionRef&, const std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> >&);
        void call(const RBX::Lua::FunctionRef&);
        void call(const RBX::Lua::FunctionRef&, boost::function1<unsigned int,lua_State *,std::allocator<boost::function_base> >, boost::function2<void,lua_State *,unsigned int,std::allocator<boost::function_base> >);
        std::auto_ptr<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > > executeInNewThread(RBX::Security::Identities, const char*, const char*, const std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> >&);
        void executeInNewThread(RBX::Security::Identities, const char*, const char*);
        void executeInNewThread(RBX::Security::Identities, const char*, const char*, boost::function1<unsigned int,lua_State *,std::allocator<boost::function_base> >, boost::function2<void,lua_State *,unsigned int,std::allocator<boost::function_base> >);
        RBX::ScriptContext::Result resume(lua_State*, int);
        void resume(lua_State*, boost::function1<unsigned int,lua_State *,std::allocator<boost::function_base> >, boost::function2<void,lua_State *,unsigned int,std::allocator<boost::function_base> >);
        void gc();
        int getThreadCount() const;
        bool hasState() const;
        lua_State* state();
        virtual XmlElement* write();
        void closeState();
        void addScript(RBX::Script*);
        void removeScript(RBX::Script*);
        RBX::ScriptContext& operator=(const RBX::ScriptContext&);
        static RBX::ScriptContext& getContext(lua_State*);
    };
}