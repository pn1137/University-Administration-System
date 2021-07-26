/*
 *	Functions to destroy objects
 *	Patrick Naugle : 23 November 2016
 */

#include <iostream>
#include <vector>
#include "Destroy.h"
#include "Department.h"
#include "Course.h"
#include "Student.h"
#include "Teacher.h"
#include "Assistant.h"

using std::vector;

/*
 *	Function to destroy created objects
 */
void Destroy::deallocate_all
	(vector<Department *> depts,	vector<Course *> courses,	
	vector<Student *> students,	vector<Teacher *> teachers)
{
	for (int i = 0; i < teachers.size(); i++)
	{
		delete teachers[i];
	}
	
	for (int i = 0; i < students.size(); i++)
	{
		delete students[i];
	}
	
	for (int i = 0; i < courses.size(); i++)
	{
		delete courses[i];
	}
	
	for (int i = 0; i < depts.size(); i++)
	{
		delete depts[i];
	}
}
