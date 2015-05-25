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
		GeneralAttributes();
		~GeneralAttributes() { delete m_pos_arr; }
		GeneralAttribute* get_rand_attribute();
		vector<GeneralAttribute>* get_general_attributes_vector(int num_of_att);
		int validate_intersection(GeneralAttribute* src_att, GeneralAttribute* ref_att);


	private:
		vector<GeneralAttribute> m_vec;
		int* m_pos_arr = new int [R1];

};

#endif

