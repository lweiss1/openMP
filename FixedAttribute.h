#ifndef FIXEDATTRIBUTE_H
#define FIXEDATTRIBUTE_H

#include <iostream>
#include <string>
#include <random>


using namespace std;

class FixedAttribute {
	public:
        FixedAttribute();
		FixedAttribute(int index);
		string m_address;
		short m_index;
		void generateAddress();
		string getAddress();

	private:

};

#endif
