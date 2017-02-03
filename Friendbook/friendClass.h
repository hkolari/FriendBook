#ifndef FRIEND_CLASS
#define FRIEND_CLASS

#include <string>

using namespace std;

class Friend {
private:
	string name;
	int yearsOld;


public:
	Friend();
	Friend(string name, int yearsOld);

	~Friend();

	Friend& operator=(const Friend& rhs);
	bool operator==(const Friend& rhs);
	bool operator<(const Friend& rhs);


	string getName();
	int getYearsOld();

	void setName(string name);
	void setYearsOld(int yearsOld);

	string toString();
};


#endif