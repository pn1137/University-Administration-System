/*
 *	C++ abstract class that represents a person
 *	Patrick Naugle : 17 November 2016
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
	
class Person 
{
	protected:
		std::string name;																			// Name of the person
		std::string universityID;															// University ID number
		int dateOfBirth;																			// Birthdate of the person (d/m/y)
		char gender;																					// Gender of the person
	
	public:
	Person(std::string name, std::string ID, 
		std::string DOB, std::string gender);									// Constructor to create a person
	virtual ~Person();																			// Destructor to destroy a person
	std::string getID();																		// Returns universityID
	std::string getName();																	// Returns name
	int getDOB();																						// Returns dateOfBirth
	char getGender();																				// Returns gender
	virtual void printInfo() = 0;														// Outputs a person's information
};

#endif