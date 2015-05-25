#ifndef GENERALATTRIBUTE_H
#define GENERALATTRIBUTE_H

#include <iostream>
#include <string>
#include <random>


using namespace std;

class GeneralAttribute {
	public:
        GeneralAttribute();
		string m_word;
		int m_position;
		int m_length;
		
		void generateWord();
		void generatePosition();

	private:

};

#endif
