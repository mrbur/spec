#pragma once
#include <iostream>
#include <string>
#include <set>
#include <tuple>
using namespace std;


struct Person
{
	string firstName;
	string secondName;
	string thirdName;

	Person(vector<string> name) {
		firstName = name[0];
		secondName = name[1];
		if(name.size() >= 3)
			thirdName = name[2];
	}

	Person(string secondName, string firstName, string thirdName) {
		this->firstName = firstName;
		this->secondName = secondName;
		this->thirdName = thirdName;
	}

	bool operator<(const Person& person) {
		return tie(firstName, secondName, thirdName) < tie(person.firstName, person.secondName, person.thirdName);
	}

	bool operator==(const Person& person) {
		return tie(firstName, secondName, thirdName) == tie(person.firstName, person.secondName, person.thirdName);
	}
};

ostream& operator<< (std::ostream& out, const Person& person) {
	out << person.firstName + " " << person.secondName + " " << person.thirdName;
	return out;
}