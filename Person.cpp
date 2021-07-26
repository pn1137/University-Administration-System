/*
 *	Functions for Person.h
 *	Patrick Naugle : 17 November 2016
 */

#include <string>
#include "Person.h"

using std::string;

/*
 *	Constructor to create a person with an ID, name, date of birth, and gender
 */
Person::Person(string personName, string ID, string DOB, string personGender)
{
	universityID = ID;
	name = personName;
	dateOfBirth = stoi(DOB);						// Convert string to int
	gender = personGender.at(0);				// Convert string to char
}

/*
 *	Destructor to destroy a person with an ID, name, date of birth, and gender
 */
Person::~Person() {}

/*
 *	Returns universityID
 */
string Person::getID()
{
	return universityID;
}

/*
 *	Returns name
 */
string Person::getName()
{
	return name;
}

/*
 *	Returns dateOfBirth
 */
int Person::getDOB()
{
	return dateOfBirth;
}

/*
 *	Returns gender
 */
char Person::getGender()
{
	return gender;
}