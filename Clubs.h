#pragma once
#include "Club.h"
#include "User.h"
const int MAXSIZE = 10;
class Clubs
{
private:
	Club** clubs;
	int current;
	int capacity;	

	void resize();

	void addNewElement(Club*& newElement);	

	void Free();
	void CopyFrom(const Clubs& other);

public:
	Clubs();
	Clubs(const Clubs& other);
	Clubs& operator=(const Clubs& other);

	Club* getClubByName(const char* name);

	bool addFolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singerName);

	bool addHouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int numberOfDjs);

	bool addRockClub(const char* name, int vodkaPrice, int whiskeyPrice);

	bool removeFromClub(const char* userName, const char* clubName);

	bool addToClub(User* u, const char* name);
};