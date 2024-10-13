#ifndef USER_H
#define USER_H

#include <string>
#include <cassert>
#include <iostream>
#include <set>

class User {
public:
    // default constructor
    // pre: none
    // post: fields are initialized to arbitrary values
    User();

    // constructor that takes 5 arguments
    // pre: none
    // post: fields are initialized to arguments that were passed in
    User(int id, std::string name, int year, int zip, std::set<int> friends);

    // pre: none
    // post: returns the user's name
    int getId();

    // pre: none
    // post: returns the user's ID
    std::string getName();

    // pre: none
    // post: returns the user's birth year
    int getYear();

    // pre: none
    // post: returns the user's zip code
    int getZip();

    // pre: none
    // post: returns the reference to user's set of friends
    std::set<int> & getFriends();

    // pre: none
    // post: friend is now in user's set of friends
    void addFriend(int id);

    // pre: none
    // post: deletes this friend ID from user's set of friends only if they are in the set
    void deleteFriend(int id);

private:
    int id_;
    std::string name_;
    int year_;
    int zip_;
    std::set<int> friends_;

    // INVARIANTS:
    //  id_ is the user's id
    //  name_ is the user's first and last name, separated by space
    //  year_ is the user's birth year
    //  zip_ is the user's zip code
    //  friends_ is the list of ids of the user's friends
};

#endif