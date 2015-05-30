#include <iostream>
#include <string>
#include <random>
#include <stddef.h>
#include "PacketGenerator.h"
#include "globals.h"

using namespace std;

PacketGenerator* PacketGenerator::m_pInstance = NULL;

PacketGenerator* PacketGenerator::Instance() {
	if (!m_pInstance)
		m_pInstance = new PacketGenerator;
	return m_pInstance;
}

PacketGenerator::PacketGenerator() {
	int i;
	G = G->Instance();
	F = F->Instance();
	P = P->Instance();
	R.reserve(N);

	for (i=0; i<N; i++) {
		Rule temp;
		R.push_back(temp);
	}

	for (i=0; i<M; i++) {
		Packet packet;
		PA.push_back(packet);
	}


}

void PacketGenerator::test() {
	//G = G->Instance();
	//F = F->Instance();
	//vector<GeneralAttribute> m = G->get_general_attributes_vector(10);
	//vector<FixedAttribute> t = F->get_fixed_att_vec(4);
	//cout << F.get_rand_attribute(1)->m_address << "\n";
	std::cin.ignore();
}


