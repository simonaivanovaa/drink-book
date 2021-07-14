#pragma once
#include <cstring>
class User
{
public:
	int age;
	double budget;
	int vodkaCount;
	int whiskeyCount;
	char* name;
	char* musicOfInterest;

	User(const char* name, int age, double budget, int vodkaCount, int whiskeyCount, const char* musicOfInterest);
	
	User(const User& other);	

	User& operator=(const User& other);
	
	~User();

};