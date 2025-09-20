#pragma once

#include <exception>

#include <boost/thread/mutex.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include "include/v8datamodel/Message.h"

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
        static boost::shared_ptr<RBX::StandardOut> singleton();
        static void print_exception(const boost::function<void,std::allocator<boost::function_base> >&, RBX::MessageType, bool);
    };
};