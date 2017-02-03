#include <iostream>
#include <fstream>
#include <string>

#include "friendClass.h"
#include "friendBook.h"

FriendBook::FriendBook() {
	this->capacity = 1;
	this->nrOfFriends = 0;
	this->title = "Missing title";

	friends = new Friend*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		friends[i] = nullptr;
	}
}

FriendBook::~FriendBook() {
	for (int i = 0; i < capacity; i++)
	{
		delete friends[i];
	}
	delete[] friends;
}

bool FriendBook::addFriend(string name, int yearsOld) {
	
	//friends[nrOfFriends++] = new Friend("Anna", 22);
	
	bool exists = false;

	if (this->nrOfFriends == capacity) {
		this->expand();
	}

	Friend temp(name, yearsOld);
	for (int i = 0; i < nrOfFriends && !exists; i++) {
		if (temp == *friends[i])
			exists = true;
	}
	if (!exists)
		friends[nrOfFriends++] = new Friend(name, yearsOld);

	return !exists;
}

void FriendBook::expand() {
	this->capacity *= 2;
	Friend** temp = new Friend*[this->capacity];

	for (int i = 0; i < nrOfFriends; i++) {
		temp[i] = friends[i];
	}
	delete[] friends;
	friends = temp;
	temp = nullptr;
}

void FriendBook::showAll() const {
	for (int i = 0; i < nrOfFriends; i++) {
		cout << friends[i]->toString() << endl;
	}
}

bool FriendBook::removeFriend(string name, int yearsOld) { // parameters name, birthdate, ...
	Friend temp(name, yearsOld); // ==
	bool removed = false;
	for (int i = 0; i < nrOfFriends && nrOfFriends != 1; i++) {
		if (temp == *friends[i]) {
			if (i == (nrOfFriends - 1))
				*friends[i] = Friend();
			else {
				friends[i] = friends[nrOfFriends - 1];
				*friends[nrOfFriends - 1] = Friend();
			}
			removed = true;
			nrOfFriends--;
		}
	}
	if (nrOfFriends == 1 && temp == *friends[0]) {
		*friends[0] = Friend();
		nrOfFriends--;
		removed = true;
	}
	return removed;
}

bool FriendBook::existFriend(string name, int yearsOld) const {
	bool exists = false;
	Friend temp(name, yearsOld);
	for (int i = 0; i < nrOfFriends && !exists; i++) {
		if (temp == *friends[i]) {
			exists = true;
		}
	}
	return exists;
}

void FriendBook::getFriendsAsString(string arr[], int nrOf) const {
	if (nrOfFriends < nrOf)
		nrOf = nrOfFriends;

	for (int i = 0; i < nrOf; i++) {
		arr[i] = friends[i]->toString();
	}
}

void FriendBook::saveOnFile(string filename) const {
	ofstream out;
	out.open(filename);

	out << nrOfFriends << endl;
	for (int i = 0; i < nrOfFriends; i++) {
		out << friends[i]->getName() << endl <<
			friends[i]->getYearsOld() << endl;
	}
	out.close();
}

void FriendBook::readFromFile(string filename) {
	ifstream in;
	in.open(filename);

	int nrOfFriends = 0;
	in >> nrOfFriends; in.ignore();

	for (int i = 0; i < nrOfFriends; i++) {
		string name = "";
		int age = 0;
		getline(in, name);
		in >> age; in.ignore();

		this->addFriend(name, age);
	}

	in.close();
}

//bool existFriend(...) const; // parameters name, birthdate, ...
//void getFriendsBornByYearAsString(string arr[], int nrOf, int year) const;
//int getNrOfFriends() const;
//string getTitle() const;
//void setTitle(string title);
//void clear();
//void getFriendsAsString(string arr[], int nrOf)const;
//void saveOnFile() const; // filename name of owner followed by .txt
//void readFromFile(); // filename name of owner followed by .txt