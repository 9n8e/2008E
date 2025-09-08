#pragma once

#include <assert.h>
#include <ostream>

namespace RBX {
    class Debugable {
    public: 
        enum AssertAction {
            CrashOnAssert = 0x0000,
            IgnoreAssert = 0x0001,
        };

        static AssertAction assertAction;
        static bool validatingDebug;
        static bool doCrash;
        
        virtual void dump(std::basic_ostream<char,std::char_traits<char> >&);
        Debugable(const RBX::Debugable&);
        Debugable();
        RBX::Debugable& operator=(const RBX::Debugable&);
        
        static void forceBadTypeId();
        static void doCrash();
        static void dump(void*, std::basic_ostream<char,std::char_traits<char> >&);
    }
}

#define RBXASSERT(expr) assert(expr)
#define LOBYTE(x) ((x) & 0xFF)