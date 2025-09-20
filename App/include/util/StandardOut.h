#pragma once

#include <exception>
#include <string>

#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include "v8tree/Service.h"

namespace RBX {
    enum MessageType {
        MESSAGE_OUTPUT = 0x0000,
        MESSAGE_INFO = 0x0001,
        MESSAGE_WARNING = 0x0002,
        MESSAGE_ERROR = 0x0003,
    };

    struct StandardOutMessage {
    public: 
        const RBX::MessageType type;
        const std::string message;
        int time;

        StandardOutMessage(const RBX::StandardOutMessage&);
        StandardOutMessage(RBX::MessageType, const char*);
        ~StandardOutMessage();
    };

    class StandardOut: public boost::enable_shared_from_this<RBX::StandardOut>, public RBX::Notifier<RBX::StandardOut,RBX::StandardOutMessage> {
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