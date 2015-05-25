#include <iostream>
#include <string>
#include <random>
#include <stddef.h>
#include "FixedAttribute.h"
#include "helper_functions.h"
#include "globals.h"
#include <stdio.h>
using namespace std;

FixedAttribute::FixedAttribute(int index) {
	m_index = index;
}

FixedAttribute::FixedAttribute() {
    m_index = 0;
}

void FixedAttribute::generateAddress() {
	char buf[5];
	sprintf(buf,"%04d",rand_num(Z0,Z1));
	m_address = buf;
}

string FixedAttribute::getAddress() {
    return m_address;
}
