#ifndef PATTERNS_H
#define PATTERNS_H

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "globals.h"

using namespace std;

class Patterns {
	public:
		static Patterns* Instance();
		string get_rand_pattern();
        void Destroy() {
            if (m_pInstance) {
                delete m_pInstance;
                m_pInstance = 0x0;
            }
        }
	private:
		Patterns(); // Private constructor - this is a singleton class
		Patterns(Patterns const&){}; // Private copy constructor - this is a singleton class
		Patterns& operator=(Patterns const&){}; // Private assignment operator - this is a singleton class
		static Patterns* m_pInstance;

		vector<string>  m_vec;

};

#endif
