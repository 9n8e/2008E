#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <format>

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