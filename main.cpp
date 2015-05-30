#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include "PacketGenerator.h"
#include "globals.h"
#include <ctime>

int main() {
    FixedAttributes* F;
    GeneralAttributes* G;
    Patterns* P;

    srand(time(NULL));
	PacketGenerator* pg;
	G = G->Instance();
	F = F->Instance();
	P = P->Instance();
	pg = pg->Instance();
	//pg->test();


	return 0;
}
