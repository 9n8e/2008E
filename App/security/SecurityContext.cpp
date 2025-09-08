#pragma once

#include "security/SecurityContext.h"

void RBX::Security::Context::requirePermission(RBX::Security::Permissions permission, const char* operation) const {
    if (!RBX::Security::Context::isInRole(identity, permission)) {
        if (operation) {
            std::string formatted = "The current security context cannot ";
            std::stringstream formatStream;
            formatStream << operation;
            formatted = formatStream.str();

            std::runtime_error pExceptionObject = std::runtime_error::runtime_error(formatted);
            throw pExceptionObject;
        }

        std::string formatted = "The current security context cannot perform the requested operation";
        std::runtime_error pExceptionObject = std::runtime_error::runtime_error(formatted);
        throw pExceptionObject;
    }
}

bool RBX::Security::Context::isInRole(RBX::Security::Identities identity, RBX::Security::Permissions permission) {
    switch (identity) {
        case Anonymous:
        case GameScript:
            return permission == None;

        case LocalGUI:
        case CmdLine:
        case TrustedCOM:
        case TrustedWebService:
        case Replicator:
            return true;

        default:
            return false;
    }
}

/* ! NOT INCLUDED BECAUSE OF INTELLISENSE ERRORS !

boost::thread_specific_ptr<Context>& RBX::Security::Context::ptr() {
    // ripped from robloxsrc
    static boost::thread_specific_ptr<Context> value(tssCleanup);
    return value;
}

RBX::Security::Context& RBX::Security::Context::current() {
    // ripped from robloxsrc
    Context* t = ptr().get();
    if (!t)
    {
        static Context anonymous(Anonymous);
        t = &anonymous;
        ptr().reset(t);
    }
    return *t;
}
*/