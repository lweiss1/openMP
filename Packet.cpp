#include "Packet.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "GeneralAttributes.h"
#include "GeneralAttribute.h"
#include "FixedAttributes.h"
#include "FixedAttribute.h"
#include "Patterns.h"
#include "globals.h"
#include "helper_functions.h"

Packet::Packet() {
	int i;
	F = F->Instance();
	G = G->Instance();
	P = P->Instance();

	fix = F->get_fixed_att_vec(rand_att_idx());
	general = G->get_general_attributes_vector(rand_num(P0, P1));
	type = rand_type(1);
	set_payload();
	set_packet();

}

void Packet::set_payload() {
	int payload_length = rand_num(A2, L2);
	int num_of_patterns = rand_num(A3, L3);
	int i, pos, str_len;
	string str;

	// Initialize payload
	payload = rand_string(payload_length);
	for (i=0; i<num_of_patterns; i++) {
		pos = rand_num(0,L2-1);
		str = P->get_rand_pattern();
		str_len = str.length();
		while ((pos+str_len-1)>L2-1) {
			pos = rand_num(0, L2-1);
		}
		payload.replace(pos, str_len, str);
	}

}

void Packet::set_packet() {
	int packet_len = 1 + 16 + (ZA1-ZA0) + payload.length();
	string str (packet_len, ' '), word;
	int i, index, len, pos;

	str.replace(20,packet_len-20,rand_string(packet_len-20));
	str.replace(0,1,type);
	// Insert Fixed attributes
	index = 1;

	for (i=0; i<fix.size(); i++) {
		str.replace(index, 4, fix[i].m_address);
		index += 4;
	}

	// Insert General attributes
	for (i=0; i<general.size(); i++) {
		len = general[i].m_length;
		pos = general[i].m_position;
		word = general[i].m_word;
//		cout << len << " " << pos << " " << word << "\n";
		str.replace(pos, len, word);
	}
	str.append(payload);
	packet = str;
	cout << "Packet: " << packet << "\n";

}
