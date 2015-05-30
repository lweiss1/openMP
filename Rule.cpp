#include "Rule.h"
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

Rule::Rule() {
	F = F->Instance();
	G = G->Instance();
	P = P->Instance();
	fix = F->get_fixed_att_vec(rand_att_idx());
	general = G->get_general_attributes_vector(rand_num(L0, L1));
	type = rand_type(0);
	pattern = P->get_rand_pattern();
}
