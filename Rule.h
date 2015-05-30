#ifndef RULE_H
#define RULE_H

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

class Rule {
	public:
		Rule();
		vector<FixedAttribute> fix;
		vector<GeneralAttribute> general;
		string type;
		string pattern;
	private:
		FixedAttributes* F;
		GeneralAttributes* G;
		Patterns* P;

};

#endif
