/*
 *	Functions for Teacher.h
 *	Patrick Naugle : 22 November 2016
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
#include "Teacher.h"
#include "Course.h"

using std::vector;
using std::string;
using std::find;
using std::cout;

/*
 *	Constructor to create a teacher
 */
Teacher::Teacher(string teachName, string ID, 
			string DOB, string teachGender, string dept, 
			string type) : Person(teachName, ID, DOB, teachGender)
{
	departmentName = dept;
	teacherType = type;
}

/*
 *	Destructor to destroy a teacher
 */
Teacher::~Teacher() {}
 
/*
 *	Assign a course from the list
 */
void Teacher::assign(Course *course)
{
	courseList.push_back(course);
}

/*
 *	Remove a course from the list
 */
void Teacher::remove(Course *course)
{
	int position;
	
	position = find(courseList.begin(), courseList.end(), course) - courseList.begin();
	
	if (position >= courseList.size())	// Course not found
	{
		cout << "ERROR, Cannot remove course: Course not found.\n";
	}
	else																// Course found
	{
		courseList.erase(courseList.begin() + position);			// Remove course
	}
}

/*
 *	Set the type of teacher
 */
void Teacher::setType(string type)
{
	teacherType = type;
}

/*
 *	Get the type of teacher
 */
string Teacher::getType()
{
	return teacherType;
}

/*
 *	Return the department name
 */
string Teacher::getDepartmentName()
{
	return departmentName;
}

/*
 *	Output the list of assigned courses
 */
void Teacher::printCourseList()
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
 *	Output the teacher's information
 */
void Teacher::printInfo()
{
	int year, day, month;
	
	// Decode date of birth
	day = getDOB() / 1000000;
	month = (getDOB() / 10000) % 100;
	year = getDOB() % 10000;
	
	cout << "Teacher's Information:\n";
	
	cout << "Name: " << getName() << "\nID: " << getID() 
		<< "\nDepartment: "<< getDepartmentName() << "\nTeacher Type: " << getType()
		<< "\nDate of Birth (d/m/y): " << day << "/" << month << "/" << year 
		<< "\nGender: " << getGender() << '\n';
		
	printCourseList();	
}