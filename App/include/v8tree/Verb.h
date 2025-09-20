#pragma once

#include "util/Debug.h"

#include <string>
#include <map>

namespace RBX {
    class VerbContainer {
    private: 
        std::map<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> > > verbs;
        RBX::VerbContainer* parent;
        void addVerb(RBX::Verb*);
        void removeVerb(RBX::Verb*);

    public: 
        VerbContainer(const RBX::VerbContainer&);
        VerbContainer(RBX::VerbContainer*);
        virtual ~VerbContainer();
        RBX::Verb* getVerb(std::basic_string<char,std::char_traits<char>,std::allocator<char> >);
        RBX::Verb* getVerb(const RBX::Name&);
        void setVerbParent(RBX::VerbContainer*);
        RBX::VerbContainer* getVerbParent() const;
        RBX::VerbContainer& operator=(const RBX::VerbContainer&);
    };

    class Verb : public Debugable {
    private: 
        const RBX::Name& name;
        RBX::VerbContainer* container;

    protected: 
        Verb(RBX::VerbContainer*, const RBX::Name&);
        Verb(RBX::VerbContainer*, std::string);

    public: 
        Verb(const RBX::Verb&);
        virtual ~Verb();
        virtual bool isEnabled() const;
        virtual bool isChecked() const;
        const RBX::Name& getName() const;
        virtual void doIt(RBX::IDataState*);
        RBX::VerbContainer* getContainer() const;
    };
};