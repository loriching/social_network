#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <string>
#include "user.h"

class Network {
public:
	// default network
	// initializes empty network with no users
	Network();

	// pre: none
	// post: returns a pointer to corresponding User, or nullptr if there is no user with that id
	User* getUser(int id);

	// pre: none
	// post: adds a User to the Network database
	void addUser(User*u);

	// pre: none
	// post: adds a friend connection between two users; returns -1 if a user is invalid, or 0 otherwise
	int addConnection(std::string s1, std::string s2);

	// pre: none
	// post: deletes a friend connection between two users; returns -1 if a user is invalid, or 0 otherwise
	int deleteConnection(std::string s1, std::string s2);

	// pre: none
	// post: returns ID of the user, or -1 if that user does not exist
	int getId(std::string name);

	// pre: none
	// post: returns number of users in the network
	int numUsers();

	// pre: none
	// post: first reads the number of users in the file, then reads user information and adds each user to the network
	void readUsers(char * fname);

	// pre: none
	// post: writes network's information to a file
	void writeUsers(char * fname);

private:
	std::vector<User*> users_;

	// INVARIANTS:
    //  users_ is a vector of User pointers
    //	contains dynamically allocated User objects
    // 	users_[0] contains user with id 0
    //	users_[1] contains user with id 1
    //	users_[users.size()-1] contains user with id users.size()-1
};

#endif