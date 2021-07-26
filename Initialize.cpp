/*
 *	Functions to create and initialize objects
 *	Patrick Naugle : 23 November 2016
 */

#include <sstream>
#include <vector>
#include <string>
#include "Initialize.h"
#include "FileReadIn.h"
#include "Department.h"
#include "Course.h"
#include "Student.h"
#include "Teacher.h"
#include "Assistant.h"

using std::vector;
using std::string;
using std::istringstream;


/*
 *	Function to create the departments
 */
vector<Department *> Initialize::init_departments()
{
	vector<string> temp;												// Vector to store strings from txt files
	vector<Department *> depts;									// Vector to store pointers to the departments
	
	temp = FileReadIn::departments();						// Department names
	
	// Populate Department pointer vector with new Department objects
	for (int i = 0; i < temp.size(); i++)
	{
		depts.push_back(new Department(temp[i]));
	}
	return depts;
}

/*
 *	Function to create the courses
 */
vector<Course *> Initialize::init_courses(vector<Department *> depts)
{
	vector<string> temp;												// Vector to store strings from txt files
	vector<Course *> courses;										// Vector to store pointers to the courses
	
	temp = FileReadIn::courses();								// Course information
	
	// Populate Course pointer vector with new Course objects
	for (int i = 0, j = 0; i < temp.size(); i+=3, j++)
	{
		courses.push_back(new Course(temp[i], temp[i+1], temp[i+2]));
		
		// Add course to department
		for (int k = 0; k < depts.size(); k++)
		{
			// Compare course's department to the department names
			if (courses[j]->getDepartmentName().compare(depts[k]->getDepartmentName()) == 0)
			{
				depts[k]->addCourse(courses[j]);
				break;
			}
		}
	}
	
	return courses;
}

/*
 *	Function to create the students
 */
vector<Student *> Initialize::init_students
	(vector<Department *> depts, vector<Course *> courses)
{
	vector<string> temp;												// Vector to store strings from txt files
	vector<Student *> students;									// Vector to store pointers to the students
	
	temp = FileReadIn::students();							// Student information
	
	// Populate Student pointer vector with new Student objects
	for (int i = 0, j = 0; i < temp.size(); i+=9, j++)
	{
		// Check for teaching assistant
		if (temp[i+6].compare("Teaching Assistant") == 0 && temp[i+5].compare("Graduate") == 0)
		{
			Assistant *asst = new Assistant(temp[i], temp[i+1], temp[i+2], temp[i+3], 
												temp[i+4], temp[i+5], temp[i+6]);
			students.push_back(asst);
			
			// Add assistant to department
			for (int k = 0; k < depts.size(); k++)
			{
				// Compare assistant's department to the department names
				if (asst->getDepartmentName().compare(depts[k]->getDepartmentName()) == 0)
				{
					depts[k]->addAssistant(asst);
					depts[k]->addStudent(asst);
					break;
				}
			}
			
			// Tokenize student's assigned course listings
			istringstream assignedCourseTokenStream(temp[i+8]);	// Stream to tokenize for courses
			string assignedCourseToken;													// String token for courses		
			
			// Add assistant to assigned courses and assigned courses to assistant
			while (getline(assignedCourseTokenStream, assignedCourseToken, '/'))
			{
				for (int k = 0; k < courses.size(); k++)
				{
					// Compare assistant's assigned courses to the course titles
					if (assignedCourseToken.compare(courses[k]->getTitle()) == 0)
					{
						courses[k]->addTeacher(asst);
						asst->assign(courses[k]);
						break;
					}
				}
			}
		}
		else	// Not teaching assistant
		{
			students.push_back(new Student(temp[i], temp[i+1], temp[i+2], temp[i+3], 
													temp[i+4], temp[i+5], temp[i+6]));	
													
			// Add student to department
			for (int k = 0; k < depts.size(); k++)
			{
				// Compare student's department to the department names
				if (students[j]->getDepartmentName().compare(depts[k]->getDepartmentName()) == 0)
				{
					depts[k]->addStudent(students[j]);
					break;
				}
			}
		}
		
		// Add student to courses and courses to student
		
		// Tokenize student's course listings
		istringstream courseTokenStream(temp[i+7]);					// Stream to tokenize for courses
		string courseToken;																	// String token for courses
		
		while (getline(courseTokenStream, courseToken, '/'))
		{
			for (int k = 0; k < courses.size(); k++)
			{
				// Compare student's courses to the course titles
				if (courseToken.compare(courses[k]->getTitle()) == 0)
				{
					courses[k]->addStudent(students[j]);
					students[j]->enroll(courses[k]);
					break;
				}
			}
		}
	}
	
	return students;
}
	
/*
 *	Function to create the teachers
 */
 vector<Teacher *> Initialize::init_teachers
	(vector<Department *> depts, vector<Course *> courses)
{
	vector<string> temp;												// Vector to store strings from txt files
	vector<Teacher *> teachers;									// Vector to store pointers to the teachers	
	
	temp = FileReadIn::teachers();							// Teacher information
	
	// Populate Teacher pointer vector with new Teacher objects
	for (int i = 0, j = 0; i < temp.size(); i+=7, j++)
	{
		teachers.push_back(new Teacher(temp[i], temp[i+1], temp[i+2], temp[i+3], 
												temp[i+4], temp[i+5]));
		
		// Add teacher to department
		for (int k = 0; k < depts.size(); k++)
		{
			// Compare teacher's department to the department names
			if (teachers[j]->getDepartmentName().compare(depts[k]->getDepartmentName()) == 0)
			{
				depts[k]->addTeacher(teachers[j]);
				break;
			}
		}
		
		// Add teacher to courses and courses to teacher
		
		// Tokenize teacher's course listings
		istringstream courseTokenStream(temp[i+6]);					// Stream to tokenize for courses
		string courseToken;																	// String token for courses
		
		while (getline(courseTokenStream, courseToken, '/'))
		{
			for (int k = 0; k < courses.size(); k++)
			{
				// Compare teacher's courses to the course titles
				if (courseToken.compare(courses[k]->getTitle()) == 0)
				{
					courses[k]->addTeacher(teachers[j]);
					teachers[j]->assign(courses[k]);
					break;
				}
			}
		}
	}
	
	return teachers;
}

