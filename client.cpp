/*
 *	Client driver for the administration system project
 *	Patrick Naugle : 22 November 2016
 */

#include <iostream>
#include <vector>
#include "Initialize.h"
#include "Destroy.h"
#include "Department.h"
#include "Course.h"
#include "Student.h"
#include "Assistant.h"
#include "Teacher.h"

using std::vector;
using std::cout;

int main(void)
{
	vector<Department *> depts;									// Vector to hold department pointers
	vector<Course *> courses;										// Vector to hold course pointers
	vector<Student *> students;									// Vector to hold student pointers
	vector<Teacher *> teachers;									// Vector to hold teacher pointers
	
	/*
	 *	Create and initialize all objects
	 */
	depts = Initialize::init_departments();
	courses = Initialize::init_courses(depts);
	students = Initialize::init_students(depts, courses);
	teachers = Initialize::init_teachers(depts, courses);
	
	/*
	 *	Display all students's information
	 */
	cout << "1 and 6: Print student information\n\n";
	
	for (int i = 0; i < students.size(); i++)
	{
		students[i]->printInfo();
	}
	
	/*
	 *	Display all teachers's information
	 */
	cout << "2 and 8: Print teacher information\n\n";
	
	for (int i = 0; i < teachers.size(); i++)
	{
		teachers[i]->printInfo();
	}
	
	/*
	 *	Display a person's derived information
	 */
	cout << "3 and 4: Test printInfo from a person pointer:\n\n";
	
	Person *person;
	
	person = students[0];
	person->printInfo();											// Print student information
	
	person = teachers[0];
	person->printInfo();											// Print teacher information
	
	/*
	 *	Display all students in a course
	 */
	cout << "5: Print students in a course\n\n";
	
	for (int i = 0; i < courses.size(); i++)
	{
		courses[i]->printGrades();
	}
	
	/*
	 *	Display all teachers in a course
	 */
	cout << "7: Print teachers in a course\n\n";
	
	for (int i = 0; i < courses.size(); i++)
	{
		courses[i]->printTeacherList();
	}
	
	/*
	 *	Display all departments' students, teachers and courses
	 */
	cout << "9: Print students, teachers and courses in a department\n\n";
	
	for (int i = 0; i < depts.size(); i++)
	{
		depts[i]->printStudentList();
		depts[i]->printTeacherList();
		depts[i]->printCourseList();
	}
	
	/*
	 *	Destroy all objects
	 */
	Destroy::deallocate_all(depts, courses, students, teachers);
	
	return 0;
}