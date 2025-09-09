namespace RBX {
    namespace Lua {
        class ScopedPopper {
        private:
            int popCount;
            lua_State* thread;

        public:
            ScopedPopper(lua_State*, int);
            ScopedPopper& operator+=(int);
            ScopedPopper& operator-=(int);
            ~ScopedPopper();
        };
    }
}