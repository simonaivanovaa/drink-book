#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;

class Club
{
public:
	char* name;
	double vodkaPrice;
	double whiskeyPrice;
	int capacity;
	int current;
	User** users;
public:
	Club();	

	Club(const char* name, int capacity, int vodkaPrice, int whiskeyPrice);

	Club(const Club& other);
	
	Club& operator=(const Club& other);

	bool UserExists(User* user);

	char* getName();
	bool removeUser(const char* userName);

	virtual bool addUser(User* user)=0;

	virtual ~Club();

	virtual bool clubCanBeAdded() = 0;

	virtual Club* clone() = 0;

	virtual const char* getClubType() = 0;
};

class FolkClub :
	public Club
{
private:
	char* singerName;

public:
	FolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singerName);
	FolkClub(const FolkClub& other);
	FolkClub& operator=(const FolkClub& other);
	~FolkClub();

	bool clubCanBeAdded();

	FolkClub* clone();

	const char* getClubType();

	bool addUser(User* user);
	
};

class HouseClub :
	public Club
{
private:
	int numberOfDjs;

public:
	HouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int numberOfDjs);

	bool clubCanBeAdded();

	HouseClub* clone();

	const char* getClubType();
	
	bool addUser(User* user);
};

class RockClub :
	public Club
{
public:
	RockClub(const char* name, int vodkaPrice, int whiskeyPrice);

	bool clubCanBeAdded();

	RockClub* clone();

	const char* getClubType();

	bool addUser(User* user);
};