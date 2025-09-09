#pragma once

namespace RBX {
	boost::once_flag nullNameFlag = BOOST_ONCE_INIT;
	boost::once_flag mooFlag = BOOST_ONCE_INIT;

	void declareNullName();
	void initMoo();
	boost::mutex moo2();

	class Name
	{
	public:
		Name(void);
		~Name(void);
		
		// to my knowledge, these calls an instance's sName member
		template <typename T>
		static void callDoDeclare(); // might not be void, this just calls declare
		template <typename T>
		static Name *doDeclare();

		static Name *declare(const char *name, int dictionaryIndex); // Name * __cdecl RBX::Name::declare(char *param_1,int param_2), param_2 might be length due to param_2 != -1
		static Name *getNullName() { boost::call_once(declareNullName, &nullNameFlag); return *nullName; };

		static int compare(Name *nameA, Name *nameB);
		static Name::NamMap *dictionary();
		static Name *lookup(std::string str);
		static Name *lookup(char *str);
		static NamMap *namMap();
		bool empty();

		// might be private, might be public, who knows
		std::string name;
		int dictionaryIndex;
	};
	class Name::NamMap : std::map<int, Name *, std::less<int>, std::allocator<std::pair<int const, Name *>>> {
	public:
		~NamMap();
	} // found this in dictionary, fucking mess man

	Name *nullName;
};
