/*
 *	Functions for Course.h
 *	Patrick Naugle : 22 November 2016
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Department.h"
#include "Student.h"
#include "Assistant.h"
#include "Teacher.h"
#include "Course.h"

using std::vector;
using std::string;
using std::cout;
using std::find;
 
/*
 *	Constructor to create a department
 */
Department::Department(string departmentTitle)
{
	departmentName = departmentTitle;
}

/*
 *	Destructor to destroy a department
 */
Department::~Department() {}

/*
 *	Add a student to the department
 */
void Department::addStudent(Student *student)
{
	studentList.push_back(student);				// Append studentList with student
}

/*
 *	Add an assistant to the department
 */
void Department::addAssistant(Assistant *assistant)
{
	assistantList.push_back(assistant);		// Append assistantList with assistant
}

/*
 *	Add a teacher to the department
 */
void Department::addTeacher(Teacher *teacher)
{
	teacherList.push_back(teacher);				// Append teacherList with teacher
}

/*
 *	Add a course to the department
 */
void Department::addCourse(Course *course)
{
	courseList.push_back(course);					// Append courseList with course
}

/*
 *	Return the department name
 */
string Department::getDepartmentName()	
{
	return departmentName;
}

/*
 *	Remove a student from the student list
 */
void Department::removeStudent(Student *student)
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
	}
}

/*
 *	Remove an assistant from the assistant list
 */
void Department::removeAssistant(Assistant *assistant)
{
	int position;												// Index of the vector
	
	// Find the index of the assistant in the vector
	position = find(assistantList.begin(), assistantList.end(), assistant) - assistantList.begin();
	
	if (position >= assistantList.size())	// Assistant not found
	{
		cout << "ERROR, Cannot remove assistant: Assistant not found.\n";
	}
	else																// Assistant found
	{
		assistantList.erase(assistantList.begin() + position);			// Remove assistant
	}
}

/*
 *	Remove a teacher from the teacher list
 */
void Department::removeTeacher(Teacher *teacher)
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
 *	Remove a course from the course list
 */
void Department::removeCourse(Course *course)
{
	int position;												// Index of the vector
	
	// Find the index of the course in the vector
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
 *	Output the students in the department
 */
void Department::printStudentList()
{
	int size = studentList.size();
	
	cout << "The " << this->getDepartmentName() << " Department's Students are:\n";
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << studentList[i]->getName();
			cout << ", " << studentList[i]->getID() << '\n';
		}
	}
	
	cout << '\n';
}

/*
 *	Output the teachers and assistants in the department
 */
void Department::printTeacherList()
{
	int size = teacherList.size();
	
	cout << "The " << this->getDepartmentName() << " Department's Teachers are:\n";
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << teacherList[i]->getName();
			cout << ", " << teacherList[i]->getID() << '\n';
		}
	}
	
	cout << '\n';
	
	size = assistantList.size();
	
	if (size > 0)
	{
		cout << "The " << this->getDepartmentName() << " Department's Student Assistants are:\n";
	
		for(int i = 0; i < size; i++)
		{
			cout << assistantList[i]->getName();
			cout << ", " << assistantList[i]->getID() << '\n';
		}
		
		cout << '\n';
	}	
}

/*
 *	Output the courses in the department
 */
void Department::printCourseList()
{
	int size = courseList.size();
	
	cout << "The " << this->getDepartmentName() << " Department's Courses are:\n";
	
	
	if (size == 0)
	{
		cout << "No Entries\n";
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << courseList[i]->getTitle() << '\n';
		}
	}
	
	cout << '\n';
}