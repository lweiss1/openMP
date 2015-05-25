#ifndef FIXEDATTRIBUTES_H
#define FIXEDATTRIBUTES_H

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "FixedAttribute.h"

#define NUM_OF_INDEXES 5

using namespace std;

class FixedAttributes {
	public:
		FixedAttributes();
		FixedAttribute* get_rand_attribute(const int index);

	private:
		vector<vector<FixedAttribute>*> m_att_vector;
		vector<FixedAttribute>  m_vec_index_1;
		vector<FixedAttribute>  m_vec_index_2;
		vector<FixedAttribute>  m_vec_index_3;
		vector<FixedAttribute>  m_vec_index_4;

};

#endif

