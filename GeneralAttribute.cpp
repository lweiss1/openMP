#include <iostream>
#include <string>
#include <random>
#include <stddef.h>
#include "GeneralAttribute.h"
#include "helper_functions.h"
#include "globals.h"
#include <stdio.h>
using namespace std;

GeneralAttribute::GeneralAttribute() {
	m_length = rand_num(ZA0, ZA1);
	m_word = "";
}

void GeneralAttribute::generateWord() {
	m_word = rand_string(m_length);
}

void GeneralAttribute::generatePosition() {
    m_position = rand_num(R0,R1);
}
