#ifndef PACKETGENERATOR_H
#define PACKETGENERATOR_H

#include <iostream>
#include <string>
#include <random>
//#include "Packets.h"
//#include "Rules.h"
#include "GeneralAttributes.h"
#include "GeneralAttribute.h"
#include "FixedAttributes.h"
#include "Patterns.h"
#include "Rule.h"
#include "Packet.h"

using namespace std;

class PacketGenerator {
	public:
		static PacketGenerator* Instance(); // Get single instance of this class
		void test();
		FixedAttributes* F;
		GeneralAttributes* G;
		Patterns* P;
		vector<Rule> R;
		vector<Packet> PA;
		void Destroy() {
            if (m_pInstance) {
                delete m_pInstance;
                m_pInstance = 0x0;
            }
        }
		//Packets P;
	private:
		PacketGenerator(); // Private constructor - this is a singleton class
		PacketGenerator(PacketGenerator const&){}; // Private copy constructor - this is a singleton class
		PacketGenerator& operator=(PacketGenerator const&){}; // Private assignment operator - this is a singleton class
		static PacketGenerator* m_pInstance; // instance name of singleton object

		//GeneralAttributes A;
		//Rules R;
		//Patterns S;

};

#endif
