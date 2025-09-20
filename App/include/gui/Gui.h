#pragma once

#include "gui/GuiEvent.h"

namespace RBX {
    class GuiTarget {
    public:
        virtual RBX::GuiResponse process(const RBX::GuiEvent&);
        GuiTarget(const RBX::GuiTarget&);
        GuiTarget();
        RBX::GuiTarget& operator=(const RBX::GuiTarget&);
    };

    class GuiResponse {
    public: 
        bool wasUsed();
        bool wasNotUsed();
        bool wasFinished();
        RBX::GuiTarget* getTarget();

        static RBX::GuiResponse notUsed();
        static RBX::GuiResponse used(RBX::GuiTarget*);
        static RBX::GuiResponse used();
        static RBX::GuiResponse finished();

        enum ResponseType {
            NOT_USED = 0x0000,
            USED = 0x0001,
            USED_AND_FINISHED = 0x0002,
        };

    private: 
        RBX::GuiResponse::ResponseType response;
        RBX::GuiTarget* target;
        GuiResponse(RBX::GuiResponse::ResponseType, RBX::GuiTarget*);
        GuiResponse(RBX::GuiResponse::ResponseType);
    
    };
};