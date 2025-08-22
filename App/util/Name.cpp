#include "Name.h"

namespace RBX {
	void declareNullName() {
		nullName = Name::declare("", 0);
	}

	bool Name::empty() {
		return getNullName() == this;
	}

	int Name::compare(Name *nameA, Name *nameB) {
		// this might not be 100%, guess we might have to nest this ALOT
		// future me 5 minutes later, this is more pain than it's worth
		//if (nameA == NULL)
			//return 0;
		//if (nameA == nullName)
			//return nameA != nullName; // wtf?? this is the only one that those this. we should also replace this with a number it actually returns
		//if (nameB == NULL)
			//return 0;
		//if (nameB == nullName)
			//return 0;

		//if (nameA == nameB)
			//return 0;
		
		// TODO: fix this fuckass, god awful, nesting
		Name *nullName = getNullName();
		if (nameA != NULL) {
			if (nameA != nullName) {
				if (nameB != NULL) {
					if (nameB != nullName) {
						if (nameA == nameB)
							return 0;

						return nameA->name == nameB->name;
					}
				}
			}
			return nameA != nullName;
		}

		if (nameB != NULL)
			if (nameB != nullName)
				return -1;

		return 0;
	}

	Name *Name::declare(const char *name, int dictionaryIndex) {
		if (name == NULL) {
			boost::call_once(declareNullName, &nullNameFlag);
			return nullName;
		}
		
		boost::call_once(initMoo, &mooFlag); // fuck you roblox
		boost::mutex *mutexThis = moo2();
		scoped_lock lock(mutexThis); // roblox has it's own scoped lock method. this explains m_locked and m_mutex. for now we'll use robloxsrc.zip as our guide
		mutexThis.lock();

		std::string nameStr(name);
		NamMap *nameMap = namMap();
		if (lock.m_mutex == NULL || (NamMap *)lock.m_mutex == nameMap)
			return NULL; //_invalid_parameter_noinfo();

		if (lock.m_locked != nameMap) { // this isn't a public api, but we should check this again. lock._4_4 != nameMap
			if (dictionaryIndex != -1) {
				if (lock.mutex() == NULL)
					return NULL; //_invalid_parameter_noinfo();
				if (lock.m_locked == lock.m_mutex->m_critical_section)
					return NULL; //_invalid_parameter_noinfo();
				if (lock.m_locked == lock.m_mutex->m_critical_section) // duplicates here??
					return NULL; //_invalid_parameter_noinfo();

				Number *convertedIndex = new Number(dictionaryIndex); // have no idea where this comes from or how it constructs
				NamMap nameDict = dictionary();
				int index = nameDict[convertedIndex]; // ??? what is this used for???
				// *piVar5 = *(int *)(lock._4_4_ + 0x28);
			}
			
			// what the FUCK is this. i need someone to help me out
			// Name *newName = *(Name **)(lock._4_4_ + 0x28);
			mutexThis.unlock();
			return NULL; //return newName;
		}

		Name *newName = new Name();
		if (newName == NULL)
			newName = NULL;
		else {
			newName->dictionaryIndex = dictionaryIndex;
			newName->name = nameStr;
		}
		
		// this is junk, there's no point
		//std::string strIndex(dictionaryIndex);
		//int nameMapResult = nameMap[strIndex];

		mutexThis.unlock();
		return newName;
	}
}
