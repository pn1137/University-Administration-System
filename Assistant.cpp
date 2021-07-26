/*
 *	Functions for Assistant.h
 *	Patrick Naugle : 23 November 2016
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Assistant.h"
#include "Course.h"

using std::vector;
using std::string;
using std::find;
using std::cout;

/*
 *	Constructor to create an assistant
 */
Assistant::Assistant(string studName, string ID, 
		string DOB, string studGender, string dept, 
		string lvl, string type) : Student(studName, ID, DOB, studGender, dept, lvl, type, this)
{}

/*
 *	Destructor to destroy an assistant
 */
Assistant::~Assistant(){}
 
/*
 *	Assign a course from the list
 */
void Assistant::assign(Course *course)
{
	assignedCourseList.push_back(course);
}

/*
 *	Remove a course from the list
 */
void Assistant::remove(Course *course)
{
	int position;
	
	position = find(assignedCourseList.begin(), assignedCourseList.end(), course) - 
							assignedCourseList.begin();
	
	if (position >= assignedCourseList.size())	// Course not found
	{
		cout << "ERROR, Cannot remove course: Course not found.\n";
	}
	else																// Course found
	{
		assignedCourseList.erase(assignedCourseList.begin() + position);			// Remove course
	}
}

/*
 *	Output the list of assigned courses
 */
void Assistant::printAssignedCourseList()
{
	int size = assignedCourseList.size();
	
	cout << this->getName() << "'s Assigned Courses are:\n";
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << '\t' << assignedCourseList[i]->getTitle() << '\n';
		}
	}
	
	cout << '\n';
}

void Assistant::printInfo()
{
	Student::printInfo();
	
	printAssignedCourseList();
}