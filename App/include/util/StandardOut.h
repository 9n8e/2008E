#pragma once

#include <exception>

#include <boost/thread/mutex.hpp>

namespace RBX {
    class StandardOut {
    public: 
        boost::mutex sync;

        void print(RBX::MessageType, const std::exception&);
        void print(RBX::MessageType, const char*, ...);
        StandardOut(const RBX::StandardOut&);
        StandardOut();
        virtual ~StandardOut();
        RBX::StandardOut& operator=(const RBX::StandardOut&);
        void __local_vftable_ctor_closure();
        virtual void* __vecDelDtor(int);

        static boost::shared_ptr<RBX::StandardOut> singleton();
        static void print_exception(const boost::function0<void,std::allocator<boost::function_base> >&, RBX::MessageType, bool);
    };
};