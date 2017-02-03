#include <iostream>
#include <string>
#include "friendBook.h"
#include "friendClass.h"

using namespace std;

int main()
{

	FriendBook book;
	book.addFriend("Anna", 22);
	book.addFriend("Bob", 33);

	book.showAll();

	system("pause");
	return 0;
	/*
	//Statisk array av pekare
	//Friend *friends[5] = {nullptr};

	//Dynamisk array av pekare
	Friend **friends = nullptr;

	int capacity = 10;
	friends = new Friend*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		friends[i] = nullptr;
	}

	//Allokera två vänner
	friends[0] = new Friend("Anna", 22);
	friends[1] = new Friend("Bob", 33);


	cout << friends[0]->toString() << endl;
	cout << friends[1]->toString() << endl;

	cout << endl;
	//Delete
	for (int i = 0; i < capacity; i++)
	{
		delete friends[i];
	}
	delete[] friends;

	system("pause");
	return 0;
	*/

}