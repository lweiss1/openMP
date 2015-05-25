#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include "PacketGenerator.h"
#include "globals.h"
#include <ctime>

int main() {

	PacketGenerator* pg;
	pg = pg->Instance();
	srand(time(NULL));
	pg->test();

	return 0;
}
