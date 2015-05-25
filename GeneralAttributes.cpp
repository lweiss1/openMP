#include <iostream>
#include <string>
#include <string.h>
#include <random>
#include <stddef.h>
#include <vector>
#include "GeneralAttribute.h"
#include "GeneralAttributes.h"
#include "helper_functions.h"
#include "globals.h"
#include <stdio.h>
#include <algorithm>

using namespace std;

GeneralAttributes::GeneralAttributes() {
	int i;

	m_vec.reserve(K);

	for (i=0; i<K; i++) {
		GeneralAttribute temp;
        temp.generateWord();
        temp.generatePosition();
        m_vec.push_back(temp);
    }
}

GeneralAttribute* GeneralAttributes::get_rand_attribute() {
	int rand_index = rand_num(0,K-1);
	return &m_vec[rand_index];
}

vector<GeneralAttribute> GeneralAttributes::get_general_attributes_vector(int num_of_att) {
	vector<GeneralAttribute> new_vec;
	int i, j, begin_idx, end_idx, vec_size, overlap_flag = 0;
	new_vec.reserve(num_of_att);
	fill_n(m_pos_arr, R1, 0);

	for (i=0; i < num_of_att; i++) {
		GeneralAttribute* temp = get_rand_attribute();
        if (m_pos_arr[temp->m_position] == 1) {
            i--;
            continue;
        } else {
            begin_idx = temp->m_position;
            end_idx = begin_idx + temp->m_length;
            vec_size = new_vec.size();
            for (j=0; j<vec_size; j++) {
                if (validate_intersection(temp, &(new_vec[2]))) {
                    overlap_flag = 1;
                    break;
                }
            }
            if (overlap_flag) {
                i--;
                continue;
            }
            new_vec.push_back(*temp);
            m_pos_arr[temp->m_position] = 1;
        }

	}

    sort(new_vec.begin(), new_vec.end());
    for (i=0; i<new_vec.size(); i++) {
        cout << new_vec[i].m_position << "\n";
    }
    return new_vec;
}

int GeneralAttributes::validate_intersection(GeneralAttribute* src_att, GeneralAttribute* ref_att) {
    // 4 overlapping options:
    // 1) A ---------------
    //    B      ------------------
    // 2) A     -------------------
    //    B ---------------
    // 3) A ---------------
    //    B    --------
    // 4) A    --------
    //    B ---------------
    int src_begin, src_end, ref_begin, ref_end, substr_len;
    string src_str, ref_str;
    src_begin = src_att->m_position;
    src_end = src_att->m_position + src_att->m_length;
    ref_begin = ref_att->m_position;
    ref_end = ref_att->m_position + ref_att->m_length;

    if (src_begin < ref_begin && src_end > ref_begin && src_end < ref_end) { // option 1
        substr_len = src_end - ref_begin;
        src_str = src_att->m_word.substr(ref_begin-src_begin,substr_len);
        ref_str = ref_att->m_word.substr(0, substr_len);
    } else if (src_begin > ref_begin && src_begin < ref_end && src_end > ref_end) { // option 2
        substr_len = ref_end - src_begin;
        src_str = src_att->m_word.substr(0,substr_len);
        ref_str = ref_att->m_word.substr(src_begin - ref_begin, substr_len);
    } else if (src_begin < ref_begin && src_end > ref_end) { // option 3
        substr_len = ref_att->m_length;
        src_str = src_att->m_word.substr(ref_begin-src_begin,substr_len);
        ref_str = ref_att->m_word;
    } else if (src_begin > ref_begin && src_end < ref_end) { // option 4
        src_str = src_att->m_word;
        ref_str = ref_str = ref_att->m_word.substr(src_begin - ref_begin, substr_len);
    } else {
        return 0;
    }

    if (src_str == ref_str) {
            return 0;
    }
    return 1;
}




