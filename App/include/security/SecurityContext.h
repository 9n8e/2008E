#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <format>

namespace RBX {
    namespace Security {
        enum Permissions {
            None = 0x0000,
            Administrator = 0x0001,
        };

        enum Identities {
            Anonymous = 0x0000,
            LocalGUI = 0x0001,
            GameScript = 0x0002,
            CmdLine = 0x0003,
            TrustedCOM = 0x0004,
            TrustedWebService = 0x0005,
            Replicator = 0x0006,
        };

        class Context {
            private:
                const Identities identity;
                Context(Identities);

                // static boost::thread_specific_ptr<Context>& ptr();
            public:
                void requirePermission(Permissions, const char*) const;
                bool hasPermission(Permissions);

                static Context& current();
                static bool isInRole(Identities, Permissions);
            };
    };
};



