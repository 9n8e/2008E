namespace RBX {
    class GuiEvent {
    public: 
        RBX::IDataState* iDataState;
        GuiEvent(const RBX::UIEvent&, RBX::IDataState*);
    };
};