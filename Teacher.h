/*
 *	C++ class that represents a teacher
 *	Inherits from Person
 *	Patrick Naugle : 22 November 2016
 */

#ifndef TEACHER_H
#define TEACHER_H

#include <vector>
#include <string>
#include "Person.h"

// Forward declarations
class Course;

class Teacher : public Person
{
	private:
		std::string teacherType;							// Teacher type
		std::string departmentName;						// Department of the teacher
		std::vector<Course *> courseList;			// List of assigned courses
		
	public:
		Teacher(std::string teachName, 
			std::string ID, std::string DOB, 
			std::string teachGender, 
			std::string dept, std::string type);// Constructor to create a teacher
		virtual ~Teacher();										// Destructor to destroy a teacher
		void assign(Course *course);					// Add a course to course list
		void remove(Course *course);					// Remove a course from course list
		void setType(std::string type);				// Set the teacher type
		std::string getType();								// Return the teacher type
		std::string getDepartmentName();			// Returns department
		void printCourseList();								// Output the course list
		virtual void printInfo();							// Output the teacher's information
};

#endif