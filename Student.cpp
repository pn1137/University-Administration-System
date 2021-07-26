/*
 *	Functions for Student.h
 *	Patrick Naugle : 22 November 2016
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
#include "Student.h"
#include "Course.h"
#include "Assistant.h"

using std::vector;
using std::string;
using std::find;
using std::cout;

/*
 *	Constructor to create a student
 */
Student::Student(string studName, string ID, 
		string DOB, string studGender, string dept, 
		string lvl, string type) : Person(studName, ID, DOB, studGender)
{
	departmentName = dept;
	level = lvl;
	gradType = type;
	assistant = nullptr;
}

/*
 *	Constructor to create a teaching assistant student
 */
Student::Student(string studName, string ID, 
		string DOB, string studGender, string dept, 
		string lvl, string type, Assistant *asst) : Person(studName, ID, DOB, studGender)
{
	departmentName = dept;
	level = lvl;
	gradType = type;
	assistant = asst;
}

/*
 *	Destructor to destroy a student
 */
Student::~Student() {}

/*
 *	Enroll in a course
 */
void Student::enroll(Course *course)
{
	courseList.push_back(course);
}

/*
 *	Drop from a course
 */
void Student::drop(Course *course)
{
	int position;
	
	position = find(courseList.begin(), courseList.end(), course) - courseList.begin();
	
	if (position >= courseList.size())	// Course not found
	{
		cout << "ERROR, Cannot drop course: Course not found.\n";
	}
	else																// Course found
	{
		courseList.erase(courseList.begin() + position);			// Drop Course
	}
}

/*
 *	Set the student level
 */
void Student::setLevel(string lvl)
{
	level = lvl;
}

/*
 *	Set the optional student graduate type
 */
void Student::setType(string type)
{
	gradType = type;
}


/*
 *	Set the optional teaching assistant pointer
 */
void Student::setAssistant(Assistant *asst)
{
	assistant = asst;
}

/*
 *	Return a pointer to teaching assistant
 */
Assistant *Student::getAssistant()
{
	return assistant;
}

/*
 *	Return the department name
 */
string Student::getDepartmentName()
{
	return departmentName;
}

/*
 *	Return the student level
 */
string Student::getLevel()
{
	return level;
}

/*
 *	Return the optional graduate type
 */
string Student::getGradType()
{
	return gradType;
}

/*
 *	Output the list of enrolled courses
 */
void Student::printCourseList()
{
	int size = courseList.size();
	
	cout << this->getName() << "'s Courses are:\n";
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << '\t' << courseList[i]->getTitle() << '\n';
		}
	}
	
	cout << '\n';
}

/*
 *	Output the student's information
 */
void Student::printInfo()
{
	int year, day, month;
	
	// Decode date of birth
	day = getDOB() / 1000000;
	month = (getDOB() / 10000) % 100;
	year = getDOB() % 10000;
	
	cout << "Student's Information:\n";
	
	cout << "Name: " << getName() << "\nID: " << getID() 
		<< "\nDepartment: "<< getDepartmentName() << "\nStudent Level: " << getLevel();
	if (getLevel().compare("Graduate") == 0)
	{
		cout << "\nGraduate Type: " << getGradType();
	}
	cout << "\nDate of Birth (d/m/y): " << day << "/" << month << "/" << year 
		<< "\nGender: " << getGender() << '\n';
		
	printCourseList();	
}