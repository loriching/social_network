#include <iostream>
#include "user.h"
#include "network.h"

using namespace std;

int main(int argc, char * argv[]) {
	Network * network = new Network();
	network->readUsers(argv[1]);

	int option;
	bool running = true;
	
	while (running) {
		cout << "\nChoose 1: Add user, 2: Add friend connection, 3: Delete friend connection, 4: Write to file, Other: Quit: ";
		cin >> option;
		switch (option) {
		case 1:
			{
				int id = network->numUsers();
				string name;
				int birthyear, zipcode;
				cout << "\nEnter first and last name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter birth year: ";
				cin >> birthyear;
				cout << "Enter zip code: ";
				cin >> zipcode;
				User * user = new User(id, name, birthyear, zipcode, set<int>{});
				network->addUser(user);
			}
			break;
		case 2:
			{
				string name1, name2;
				cout << "\nEnter name of first user: ";
				cin.ignore(1, '\n');
				getline(cin, name1);
				cout << "Enter name of second user: ";
				getline(cin, name2);
				network->addConnection(name1, name2);
			}
			break;
		case 3: 
			{
				string name1, name2;
				cout << "\nEnter name of first user: ";
				cin.ignore(1, '\n');
				getline(cin, name1);
				cout << "Enter name of second user: ";
				getline(cin, name2);
				network->deleteConnection(name1, name2);
			}
			break;
		case 4: 
			{
				string filename;
				cout << "\nEnter file name to write to: ";
				cin >> filename;
				network->writeUsers(&filename[0]); // pointer to first character (turns string into char*)
			}
			break;
		default:
			{
				running = false;
			}
			break;
		}
	}
	delete network;
	return 0;
}