#include "network.h"
#include <string>
#include <set>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <cassert>
#include <sstream>

Network::Network() {
	users_ = {};
}

User* Network::getUser(int id) {
	if (id >= users_.size()) {
		return nullptr;
	}
	return users_[id];
}

void Network::addUser(User*u) {
	users_.push_back(u);
}

int Network::addConnection(std::string s1, std::string s2) {
	User * a = nullptr;
	User * b = nullptr;
	for (int i=0; i<users_.size(); ++i) {
		if (users_[i]->getName() == s1) {
			a = users_[i];
		}
		if (users_[i]->getName() == s2) {
			b = users_[i];
		}
	}
	if (a == nullptr || b == nullptr) {
		std::cout << "Failed to add friend connection." << std::endl;
		return -1;
	}
	a->addFriend(b->getId());
	b->addFriend(a->getId());
	std::cout << "Successfully added friend connection." << std::endl;
	return 0;
}

int Network::deleteConnection(std::string s1, std::string s2) {
	User * a = nullptr;
	User * b = nullptr;
	for (int i=0; i<users_.size(); ++i) {
		if (users_[i]->getName() == s1) {
			a = users_[i];
		}
		if (users_[i]->getName() == s2) {
			b = users_[i];
		}
	}
	if (a == nullptr || b == nullptr) {
		std::cout << "Failed to delete friend connection." << std::endl;
		return -1;
	}
	a->deleteFriend(b->getId());
	b->deleteFriend(a->getId());
	std::cout << "Successfully deleted friend connection." << std::endl;
	return 0;
}

int Network::getId(std::string name) {
	for (int i=0; i<users_.size(); ++i) {
		if (users_[i]->getName() == name) {
			return users_[i]->getId();
		}
	}
	return -1;
}

int Network::numUsers() {
	return users_.size();
}

void Network::readUsers(char * fname) {
	std::ifstream myfile(fname);
	assert(myfile.is_open());

	std::string num_users;
	std::getline(myfile, num_users);

	int num = stoi(num_users);

	for (int i=0; i<num; ++i) {
		int id;
		std::string user_name;
		int birth_year;
		int zip_code;
		int friend_id;
		std::set<int> friends;

		std::string myline;

		std::getline(myfile, myline);
		id = stoi(myline);

		std::getline(myfile, user_name);
		user_name = user_name.substr(1);

		std::getline(myfile, myline);
		myline = myline.substr(1);
		birth_year = stoi(myline);

		std::getline(myfile, myline);
		myline = myline.substr(1);
		zip_code = stoi(myline);

		std::getline(myfile, myline);

		std::stringstream ss(myline);
		while (ss >> friend_id) {
			friends.insert(friend_id);
		}

		User * u = new User(id, user_name, birth_year, zip_code, friends);
		users_.push_back(u);
	}
	myfile.close();
}

void Network::writeUsers(char * fname) {
	std::ofstream fout(fname);
	if (!fout.is_open()) {
		std::cout << "Could not write to file." << std::endl;
		return;
	}
	fout << users_.size() << "\n";
	for (int i=0; i<users_.size(); ++i) {
		fout << users_[i]->getId() << "\n";
		fout << "\t" << users_[i]->getName() << "\n";
		fout << "\t" << users_[i]->getYear() << "\n";
		fout << "\t" << users_[i]->getZip() << "\n";
		fout << "\t";
		const auto & friends = users_[i]->getFriends();
		for (auto it=friends.begin(); it!=friends.end(); ++it) {
			int id = *it;
			fout << id << " ";
		}
		fout << "\n";
	}
	std::cout << "Successfully wrote " << users_.size() << " users to file." << std::endl;
	fout.close();

}
