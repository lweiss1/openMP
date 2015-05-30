#ifndef FIXEDATTRIBUTES_H
#define FIXEDATTRIBUTES_H

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "FixedAttribute.h"
#include "globals.h"

using namespace std;

class FixedAttributes {
	public:
		static FixedAttributes* Instance();
		~FixedAttributes() { delete(index_arr); }
		FixedAttribute* get_rand_attribute(const int index);
		void Destroy() {
            if (m_pInstance) {
                delete m_pInstance;
                m_pInstance = 0x0;
            }
        }
		vector<FixedAttribute> get_fixed_att_vec(int length);

	private:
		FixedAttributes(); // Private constructor - this is a singleton class
		FixedAttributes(FixedAttributes const&){}; // Private copy constructor - this is a singleton class
		FixedAttributes& operator=(FixedAttributes const&){}; // Private assignment operator - this is a singleton class
		static FixedAttributes* m_pInstance;

		vector<vector<FixedAttribute>*> m_att_vector;
		vector<FixedAttribute>  m_vec_index_1;
		vector<FixedAttribute>  m_vec_index_2;
		vector<FixedAttribute>  m_vec_index_3;
		vector<FixedAttribute>  m_vec_index_4;
		int* index_arr;

};

#endif

