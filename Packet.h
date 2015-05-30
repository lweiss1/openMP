#ifndef PACKET_H
#define PACKET_H

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


using namespace std;

class Packet {
	public:
		Packet();
		vector<FixedAttribute> fix;
		vector<GeneralAttribute> general;
		string type;
		string payload;
		string packet;
	private:
		FixedAttributes* F;
		GeneralAttributes* G;
		Patterns* P;
		void set_payload();
		void set_packet();

};

#endif
