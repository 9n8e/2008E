#pragma once
#include <set>

namespace RBX {
    class IMovingManager {
    private: 
        std::set<RBX::IMoving *,std::less<RBX::IMoving *>,std::allocator<RBX::IMoving *> > moving;
        std::_Tree<std::_Tset_traits<RBX::IMoving *,std::less<RBX::IMoving *>,std::allocator<RBX::IMoving *>,0> >::iterator current;

    protected: 
        void remove(RBX::IMoving*);
        void moved(RBX::IMoving*);
        public: 
        IMovingManager(const RBX::IMovingManager&);
        IMovingManager();
        virtual ~IMovingManager();
        void onMovingHeartbeat();
        RBX::IMovingManager& operator=(const RBX::IMovingManager&);
    };
    
    class IMoving {
    private: 
        RBX::IMovingManager* iMovingManager;
        int stepsToSleep;
        void makeMoving();

    protected: 
        virtual void onCanAggregateChanged(bool);
        void setMovingManager(RBX::IMovingManager*);
        bool checkSleep();

    public: 
        IMoving(const RBX::IMoving&);
        IMoving();
        ~IMoving();
        void notifyMoved();
        virtual bool reportTouches() const;
        bool getCanAggregate() const;
        RBX::IMoving& operator=(const RBX::IMoving&);
    };
}