#ifndef GENERALATTRIBUTES_H
#define GENERALATTRIBUTES_H

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "GeneralAttribute.h"
#include "globals.h"


using namespace std;

class GeneralAttributes {
	public:
		static GeneralAttributes* Instance();
		~GeneralAttributes() { delete m_pos_arr; }
		GeneralAttribute* get_rand_attribute();
		vector<GeneralAttribute> get_general_attributes_vector(int num_of_att);
		int validate_intersection(GeneralAttribute* src_att, GeneralAttribute* ref_att);
		void Destroy() {
            if (m_pInstance) {
                delete m_pInstance;
                m_pInstance = 0x0;
            }
        }


	private:
		GeneralAttributes(); // Private constructor - this is a singleton class
		GeneralAttributes(GeneralAttributes const&){}; // Private copy constructor - this is a singleton class
		GeneralAttributes& operator=(GeneralAttributes const&){}; // Private assignment operator - this is a singleton class
		static GeneralAttributes* m_pInstance;

		vector<GeneralAttribute> m_vec;
		int* m_pos_arr;

};

#endif

