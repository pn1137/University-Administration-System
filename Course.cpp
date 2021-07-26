/*
 *	Functions for Course.h
 *	Patrick Naugle : 18 November 2016
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Course.h"
#include "Student.h"
#include "Teacher.h"

using std::vector;
using std::string;
using std::cout;
using std::find;

/*
 *	Constructor to create a course
 */
Course::Course(string courseTitle, string courseLevel, string dept)
	{
		title = courseTitle;
		level = courseLevel;
		departmentName = dept;
	}

/*
 *	Destructor to destroy a course
 */
Course::~Course() {}

/*
 *	Set a grade for a student
 */
void Course::setGrade(string studentID, double grade)
{
	int position;												// Index of the vector
	
	// Find the index of the student in the vector by ID
	for (position = 0; position < studentList.size(); position++)
	{
		if (studentID.compare(studentList[position]->getID()) == 0)
		{
			break;													// ID matches
		}
	}
	
	if (position >= studentList.size())	// Student not found
	{
		cout << "ERROR, Cannot set grade: Student not found.\n";
	}
	else																// Student found
	{
		grades[position] = grade;					// Set the grade
	}
}

/*
 *	Add a student to the student list
 */
void Course::addStudent(Student *student)
{
	studentList.push_back(student);				// Append studentList with new student name
	grades.push_back(0);									// Append grades with initial grade for new student
}

/*
 *	Add a teacher to the teacher list
 */
void Course::addTeacher(Person *teacher)
{
	teacherList.push_back(teacher);				// Append teacherList with new teacher
}

/*
 *	Remove a student from the student list
 */
void Course::removeStudent(Student *student)
{
	int position;												// Index of the vector
	
	// Find the index of the student in the vector
	position = find(studentList.begin(), studentList.end(), student) - studentList.begin();
	
	if (position >= studentList.size())	// Student not found
	{
		cout << "ERROR, Cannot remove student: Student not found.\n";
	}
	else																// Student found
	{
		studentList.erase(studentList.begin() + position);			// Remove student
		grades.erase(grades.begin() + position);								// Remove grade
	}
}

/*
 *	Remove a teacher from the teacher list
 */
void Course::removeTeacher(Person *teacher)
{
	int position;												// Index of the vector
	
	// Find the index of the teacher in the vector
	position = find(teacherList.begin(), teacherList.end(), teacher) - teacherList.begin();
	
	if (position >= teacherList.size())	// Teacher not found
	{
		cout << "ERROR, Cannot remove teacher: Teacher not found.\n";
	}
	else																// Teacher found
	{
		teacherList.erase(teacherList.begin() + position);			// Remove teacher
	}
}

/*
 *	Return the course level
 */
string Course::getLevel()
{
	return level;
}

/*
 *	Return the course title
 */
string Course::getTitle()
{
	return title;
}

/*
 *	Return the department name
 */
string Course::getDepartmentName()
{
	return departmentName;
}

/*
 *	Output the list of students and their grades
 */
void Course::printGrades()
{
	int size = studentList.size();
	
	cout << this->getTitle() << "'s Grade List:\n\n";
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Student name: " << studentList[i]->getName() 
				<< "\n\tID: " << studentList[i]->getID() << "\n\tGrade: " << grades[i] << "\n";
		}
	}
	
	cout << '\n';
}

/*
 *	Output the list of teachers
 */
void Course::printTeacherList()
{
	int size = teacherList.size();
	
	cout << this->getTitle() <<  "'s Teachers are:\n\n";
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Teacher name: " << teacherList[i]->getName() 
				<< "\n\tID: " << teacherList[i]->getID() << '\n';
		}
	}
	
	cout << '\n';
}