#include <iostream>
#include <string>
#include <random>
#include <stddef.h>
#include "Patterns.h"
#include "helper_functions.h"
#include "globals.h"
#include <stdio.h>

using namespace std;

Patterns* Patterns::m_pInstance = NULL;

Patterns* Patterns::Instance() {
	if (!m_pInstance)
		m_pInstance = new Patterns;
	return m_pInstance;
}


Patterns::Patterns() {
	int i;

	m_vec.reserve(S);
	for (i=0; i < S; i++) {
		string str = rand_string(rand_num(ZA0,ZA1));
		m_vec.push_back(str);
		//cout << m_vec[i] << "\n";
	}

}

string Patterns::get_rand_pattern() {
	return m_vec[rand_num(0,S-1)];
}
