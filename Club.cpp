#pragma once
#include "Club.h"
Club::Club()
{
	char name[] = "Basic";
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->capacity = 8;
	this->current = 0;
	this->vodkaPrice = 50;
	this->whiskeyPrice = 50;
	users = new User * [capacity];
}

Club ::Club(const char* name, int capacity, int vodkaPrice, int whiskeyPrice)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->capacity = capacity;
	this->current = current;
	this->vodkaPrice = vodkaPrice;
	this->whiskeyPrice = whiskeyPrice;
	users = new User*[capacity];

}


Club ::Club(const Club& other)
{
	this->vodkaPrice = other.vodkaPrice;
	this->whiskeyPrice = other.whiskeyPrice;
	this->capacity = other.capacity;
	this->current = other.current;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
Club& Club::operator=(const Club& other)
{
	if (this != &other)
	{
		delete[] name;
		this->vodkaPrice = other.vodkaPrice;
		this->whiskeyPrice = other.whiskeyPrice;
		this->capacity = other.capacity;
		this->current = other.current;
		name = new char[strlen(other.name) + 1];
		strcpy(name,other.name);
	}
	return *this;
}
Club::~Club()
{
	for (int i = 0; i < current; i++)
	{
		delete users[i];
	}
	delete[] users;
	delete[] name;
}
bool  Club::UserExists(User* user) {
	if (current > 0) {
		for (int i = 0; i < capacity; i++)
		{
			if (strcmp(users[i]->name, user->name) == 0) {
				return true;
				break;
			}
		}
	}
	
	return false;
}
bool Club::removeUser(const char* userName) {	
	int index = 0;
	if (current > 0) {
		bool userExists = 0;
		for (int i = 0; i < current; i++)
		{
			if (strcmp(users[i]->name, userName) == 0) {
				index = i;
				userExists = 1;
				break;
			}
		}
		if (userExists) {
			User** newUsers = new User * [capacity];
			
			int counter = 0;
			for (int i = 0; i < current; i++)
			{
				if (index != i) {
					newUsers[counter] = users[i];
					counter++;
				}
			}
			users = newUsers;
			
			delete[] newUsers;
			return true;
		}		
	}
	return false;
	
	
}
char* Club::getName() {
	return name;
}
/////////////////////////////////////
FolkClub::FolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singerName) :
	Club(name, 70, vodkaPrice, whiskeyPrice)
{
	this->singerName = new char[strlen(singerName) + 1];
	strcpy_s(this->singerName, strlen(singerName) + 1, singerName);
}
FolkClub:: FolkClub(const FolkClub& other)
{

	singerName = new char[strlen(other.singerName) + 1];
	strcpy_s(singerName, strlen(other.singerName) + 1, other.singerName);
}
FolkClub& FolkClub:: operator=(const FolkClub& other)
{
	if (this != &other)
	{
		delete[] singerName;

		singerName = new char[strlen(other.singerName) + 1];
		strcpy_s(singerName, strlen(other.singerName) + 1, other.singerName);
	}
	return *this;
}
FolkClub::~FolkClub()
{
	delete[] singerName;
}

bool FolkClub::clubCanBeAdded()
{
	if (this->vodkaPrice < 20 || this->whiskeyPrice < 35)
	{
		return false;
	}

	return true;
}

FolkClub* FolkClub::clone()
{
	return new FolkClub(*this);
}

const char* FolkClub::getClubType()
{
	return "Folk";
}
bool FolkClub::addUser(User* user) {
	if (current == capacity) {
		return false;
	}
	if (!UserExists(user)) {
		double vodkaPrice = user->vodkaCount * this->vodkaPrice; //цена за водките
		double whiskeyPrice = user->whiskeyCount * this->whiskeyPrice; //цена на уискитата
		double totalPrice = vodkaPrice + whiskeyPrice; //обща цена

		if (user->age >= 18)
		{
			bool canDrink = user->budget >= totalPrice; //човека има достатъчно бюджет
			bool clubHaveCapacity = capacity > 0; //има достатъчно място в клуба
			bool interestedInMusic = !(strcmp(user->musicOfInterest, "Rock") == 0); //ако стила на музика съвпада

			if (canDrink && clubHaveCapacity && interestedInMusic)
			{
				users[current] = user;
				current++;//сваляме капацитета на клуба 
				return true;
			}
		}
		else
		{
			user->budget = user->budget - 20; //20 лв за охрана
			bool canDrink = user->budget > totalPrice; //човека има достатъчно бюджет
			bool clubHaveCapacity = capacity > 0; //има достатъчно място в клуба
			bool interestedInMusic = !(strcmp(user->musicOfInterest, "Rock") == 0); //човека или слуша всичко или НЕ слуша рок

			if (canDrink && clubHaveCapacity && interestedInMusic)
			{
				users[current] = user;
				current++; //сваляме капацитета на клуб
				return true;

			}
		}
		return false;
	}
}
/////////////////////////////////////
HouseClub::HouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int numberOfDjs) :
	Club(name, 1000, vodkaPrice, whiskeyPrice)
{
	this->numberOfDjs = numberOfDjs;
}

bool HouseClub::clubCanBeAdded()
{
	if (this->vodkaPrice < 30 || this->whiskeyPrice < 40)
	{
		return false;
	}

	return true;
}

HouseClub* HouseClub::clone()
{
	return new HouseClub(*this);
}

const char* HouseClub:: getClubType()
{
	return "House";
}

bool HouseClub::addUser(User* user) {
	if (current == capacity) {
		return false;
	}
	if (!UserExists(user)) {
		double vodkaPrice = user->vodkaCount * this->vodkaPrice; //цена за водките
		double whiskeyPrice = user->whiskeyCount * this->whiskeyPrice; //цена на уискитата
		double totalPrice = vodkaPrice + whiskeyPrice; //обща цена

		if (user->age >= 18)
		{
			bool canDrink = user->budget >= totalPrice; //човека има достатъчно бюджет
			bool clubHaveCapacity = capacity > 0; //има достатъчно място в клуба
			bool interestedInMusic = !(strcmp(user->musicOfInterest, "Folk") == 0);
			if (canDrink && clubHaveCapacity && interestedInMusic)
			{
				users[current] = user;
				current++; //сваляме капацитета на клуба
				return true;
			}
		}
		return false;
	}
}
/////////////////////////////////////
RockClub::RockClub(const char* name, int vodkaPrice, int whiskeyPrice) :
	Club(name, 30, vodkaPrice, whiskeyPrice)
{
}

bool RockClub:: clubCanBeAdded()
{
	if (this->vodkaPrice < 40 || this->whiskeyPrice < 30) {
		return false;
	}

	return true;
}

RockClub* RockClub::clone()
{
	return new RockClub(*this);
}

const char* RockClub::getClubType()
{
	return "Rock";
}
bool RockClub:: addUser(User* user) {
	if (current == capacity) {
		return false;
	}
	if (!UserExists(user)) {
		double vodkaPrice = user->vodkaCount * this->vodkaPrice; //цена за водките
		double whiskeyPrice = user->whiskeyCount * this->whiskeyPrice; //цена на уискитата
		double totalPrice = vodkaPrice + whiskeyPrice; //обща цена

		if (user->age >= 18)
		{
			bool canDrink = user->budget >= totalPrice; //човека има достатъчно бюджет
			bool clubHaveCapacity = capacity > 0; //има достатъчно място в клуба
			bool interestedInMusic = !(strcmp(user->musicOfInterest, "House") == 0);

			if (canDrink && clubHaveCapacity && interestedInMusic)
			{
				users[current] = user;
				current++; //сваляме капацитета на клуба
				return true;
			}
		}
		return false;
	}
}