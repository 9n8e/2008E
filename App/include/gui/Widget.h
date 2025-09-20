#pragma once

#include "gui/Gui.h"

#include "G3D/Color4.h"

namespace RBX {
    class Widget {
        public: 
        enum WidgetState {
            NOTHING = 0x0000,
            HOVER = 0x0001,
            DOWN_OVER = 0x0002,
            DOWN_AWAY = 0x0003,
        };
        Widget(const RBX::Widget&);
        Widget();
        virtual ~Widget();
        RBX::Widget& operator=(const RBX::Widget&);

    private: 
        RBX::GuiResponse processMouse(const RBX::GuiEvent&);
        RBX::GuiResponse processKey(const RBX::GuiEvent&);

    protected: 
        WidgetState widgetState;

        virtual RBX::GuiResponse process(const RBX::GuiEvent&);
        virtual void onLoseFocus();
        virtual void render2d(RBX::Adorn*);
        virtual void onClick(const RBX::GuiEvent&);
        virtual bool onDrag(const RBX::GuiEvent&);
        virtual void onDown(const RBX::UIEvent&);
        virtual void onUp(const RBX::UIEvent&);
        virtual int getFontSize() const;
        virtual G3D::Color4 getFontColor();
        virtual bool isEnabled();
    };
};