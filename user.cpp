#include "user.h"
#include <string>
#include <set>
#include <iostream>
#include <cassert>

User::User() {
	id_ = 429;
	name_ = "Professor Rowan";
	year_ = 2007;
	zip_ = 10000;
	friends_ = std::set<int>();
}

User::User(int id, std::string name, int year, int zip, std::set<int> friends) {
	id_ = id;
	name_ = name;
	year_ = year;
	zip_ = zip;
	friends_ = friends;
}

int User::getId() {
	return id_;
}

std::string User::getName() {
	return name_;
}

int User::getYear() {
	return year_;
}

int User::getZip() {
	return zip_;
}

std::set<int> & User::getFriends() {
	return friends_;
}

void User::addFriend(int id) {
	friends_.insert(id);
}

void User::deleteFriend(int id) {
	friends_.erase(id);
}