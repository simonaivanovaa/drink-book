#include "User.h"
User ::User(const char* name, int age, double budget, int vodkaCount, int whiskeyCount, const char* musicOfInterest)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->budget = budget;
	this->vodkaCount = vodkaCount;
	this->whiskeyCount = whiskeyCount;
	this->musicOfInterest = new char[strlen(musicOfInterest) + 1];
	strcpy(this->musicOfInterest, musicOfInterest);
}
User::User(const User& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
	budget = other.budget;
	vodkaCount = other.vodkaCount;
	whiskeyCount = other.whiskeyCount;
	musicOfInterest = new char[strlen(other.musicOfInterest) + 1];
	strcpy(musicOfInterest, other.musicOfInterest);
}
User& User:: operator=(const User& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] musicOfInterest;

		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		musicOfInterest = new char[strlen(other.musicOfInterest) + 1];
		strcpy(musicOfInterest, other.musicOfInterest);
	}
	return *this;
}
User::~User()
{
	delete[] name;
	delete[] musicOfInterest;
}