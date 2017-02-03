#ifndef FRIEND_BOOK
#define FRIEND_BOOK
#include "friendClass.h"
#include <string>


class FriendBook
{
private:
	Friend** friends;
	int capacity;
	int nrOfFriends;
	string title;


	// member variables and helperfunctions
public:
	FriendBook();
	bool addFriend(string name, int yearsOld);
	void showAll() const;

	~FriendBook();
	void expand();

	bool removeFriend(string name, int yearsOld); // parameters name, birthdate, ...
	bool existFriend(string name, int yearsOld) const; // parameters name, birthdate, ...
	void getFriendsAsString(string arr[], int nrOf) const;
	//void getFriendsBornByYearAsString(string arr[], int nrOf, int year) const;
	//int getNrOfFriends() const;
	//string getTitle() const;
	//void setTitle(string title);
	//void clear();

	void saveOnFile(string filename) const; // filename name of owner followed by .txt
	void readFromFile(string filename); // filename name of owner followed by .txt
};

#endif