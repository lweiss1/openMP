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

void PacketGenerator::test() {
	
	
	cout << F.get_rand_attribute(1)->m_address << "\n";
	std::cin.ignore();
}


