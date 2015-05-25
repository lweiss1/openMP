#include <iostream>
#include <string>
#include <random>
#include <stddef.h>
#include <cstdlib>
#include "globals.h"


using namespace std;

int rand_att_idx() {
	return rand()%4+1;
}

int rand_num(int lower_bound, int upper_bound) {
	int num,range;
	num = rand()%upper_bound+1;
	if (num<lower_bound) {
		range = upper_bound - lower_bound;
		num = lower_bound + num%range;
	}
	return num;
}

string rand_string(int _length) {
	int num,i;
	//char str;
	string result;
	char temp[2];
	//str = new char[length+1];
	for (i=0; i<_length; i++) {
		temp[0] = (char)rand_num(ASCII_A,ASCII_Z);
		temp[1] = '\0';
		//cout << "c:" << temp[0] << "\n";
		result.append(temp);
	}
	//result = "lior";
	//str[length] = "\0";
	//result = str;
	//delete(str);
	return result;
}
