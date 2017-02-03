#include "friendClass.h"
#include <string>
#include <iostream>

using namespace std;

Friend::Friend() {
	name = "EMPTY";
	yearsOld = -1;
}

Friend::Friend(string name, int yearsOld) {
	this->name = name;
	this->yearsOld = yearsOld;
}

Friend::~Friend() {
}


Friend& Friend::operator=(const Friend& rhs) {
	this->name = rhs.name;
	this->yearsOld = rhs.yearsOld;
	return *this;
}

bool Friend::operator==(const Friend& rhs) {
	return (this->name == rhs.name) && (this->yearsOld == rhs.yearsOld);
}

bool Friend::operator<(const Friend& rhs) {
	return (this->yearsOld < rhs.yearsOld);
}

string Friend::getName() {
	return name;
}

int Friend::getYearsOld() {
	return yearsOld;
}

void Friend::setName(string name) {
	this->name = name;
}

void Friend::setYearsOld(int yearsOld) {
	this->yearsOld = yearsOld;
}

string Friend::toString() {
	return name + " " + to_string(yearsOld);
}