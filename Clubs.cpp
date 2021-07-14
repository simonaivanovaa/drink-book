#pragma once
#include "Clubs.h"
void Clubs::resize()
{
	Club** helper = new Club * [capacity *= 2];
	for (int i = 0; i < current; i++)
	{
		helper[i] = clubs[i];
	}

	delete[]clubs;

	clubs = helper;
}
void Clubs:: addNewElement(Club*& newElement)
{
	if (newElement->clubCanBeAdded())
	{
		if (current == capacity)
			resize();

		clubs[current] = newElement;
		current++;
	}
}
void Clubs::Free()
{
	for (int i = 0; i < capacity; i++)
		delete clubs[i];

	delete[] clubs;
}
void Clubs:: CopyFrom(const Clubs& other)
{
	clubs = new Club * [other.capacity];
	capacity = other.capacity;
	current = other.current;
	for (int i = 0; i < capacity; i++)
		clubs[i] = other.clubs[i]->clone();//tuk pointara veche e specialno kakavto trqbwa ot opredeln tip
}
Clubs:: Clubs()
{
	current = 0;
	capacity = 10;
	clubs = new Club * [capacity];
}
Clubs:: Clubs(const Clubs& other)
{
	CopyFrom(other);
}
Clubs& Clubs:: operator=(const Clubs& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
bool Clubs:: addFolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singerName)
{
	Club* c = new FolkClub(name, vodkaPrice, whiskeyPrice, singerName);
	addNewElement(c);

	bool clubCanBeAdded = c->clubCanBeAdded();
	return clubCanBeAdded;
}
bool Clubs:: addHouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int numberOfDjs)
{
	Club* c = new HouseClub(name, vodkaPrice, whiskeyPrice, numberOfDjs);
	addNewElement(c);

	bool clubCanBeAdded = c->clubCanBeAdded();
	return clubCanBeAdded;
}
bool Clubs:: addRockClub(const char* name, int vodkaPrice, int whiskeyPrice)
{
	Club* c = new RockClub(name, vodkaPrice, whiskeyPrice);
	addNewElement(c);

	bool clubCanBeAdded = c->clubCanBeAdded();
	return clubCanBeAdded;
}

bool Clubs:: removeFromClub(const char* userName, const char* clubName)
{
	return getClubByName(clubName)->removeUser(userName);
}
Club* Clubs::getClubByName(const char* name) {
	for (int i = 0; i < capacity; i++)
	{
		if (strcmp(clubs[i]->getName(), name) == 0) {
			return clubs[i];
		}
	}
}
bool Clubs::addToClub(User* u, const char* name) {
	return getClubByName(name)->addUser(u);
}