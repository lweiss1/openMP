#include <iostream>
#include <string>
#include <string.h>
#include <random>
#include <stddef.h>
#include <vector>
#include "FixedAttribute.h"
#include "FixedAttributes.h"
#include "helper_functions.h"
#include "globals.h"
#include <stdio.h>

using namespace std;

FixedAttributes::FixedAttributes() {
    int i, rand_index;
    char str[5];

    // Initialize vectors
    m_att_vector.reserve(NUM_OF_INDEXES);
    m_vec_index_1.reserve(Z);
    m_vec_index_2.reserve(Z);
    m_vec_index_3.reserve(Z);
    m_vec_index_4.reserve(Z);
    m_att_vector.push_back(NULL);
    m_att_vector.push_back(&m_vec_index_1); // vector for Index '1'
    m_att_vector.push_back(&m_vec_index_2); // vector for Index '2'
    m_att_vector.push_back(&m_vec_index_3); // vector for Index '3'
    m_att_vector.push_back(&m_vec_index_4); // vector for Index '4'

    // Generating Fixed Attributes
    for (i=0; i<Z; i++) {
        rand_index = rand_att_idx();
        FixedAttribute temp;
        temp.generateAddress();
        temp.m_index = rand_index;
        m_att_vector[rand_index]->push_back(temp);
    }
}

FixedAttribute* FixedAttributes::get_rand_attribute(const int index) {
    int vec_size;
    int rand_att_idx;
	
	FixedAttribute* result;
    vec_size = m_att_vector[index]->size();

    if (vec_size == 0) return NULL;

    rand_att_idx = rand_num(0,vec_size-1);
    result = &(*m_att_vector[index])[rand_att_idx];
	return result;
}
