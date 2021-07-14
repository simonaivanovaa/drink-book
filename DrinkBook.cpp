#pragma once
#include "Clubs.h"





int main()
{
	Clubs d;
	bool add33FolkClubFalse = d.addFolkClub("33", 10, 40, "Galena");
	cout << "add33FolkClubFalse " << add33FolkClubFalse << endl;

	bool add33FolkClubTrue = d.addFolkClub("33", 40, 40, "Galena");
	cout << "add33FolkClubTrue " << add33FolkClubTrue << endl;

	bool addHouseClub = d.addHouseClub("Yalta", 50, 50, 2);
	cout <<"addHouseClub "<< addHouseClub << endl;

	User* u = new User("Ivan", 18, 180, 2, 2, "House");
	bool userAdded = d.addToClub(u, "Yalta");
	cout << "userAdded "<< userAdded << endl;

	bool userAdded1 = d.addToClub(u, "33");
	cout << "userAdded1 " << userAdded1 << endl;
	
	bool userRemoved2 = d.removeFromClub("Poli", "33");
	cout << "userRemoved2 " << userRemoved2 << endl;

	bool userRemoved3 = d.removeFromClub("Ivan", "33");
	cout << "userRemoved3 " << userRemoved3 << endl;
}
