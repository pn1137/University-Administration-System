/*
 *	C++ class that represents a teaching assistant
 *	Inherits from Student, which inherits from Person
 *	Patrick Naugle : 23 November 2016
 */
 
#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <vector>
#include "Student.h"

// Forward declarations
class Course;

class Assistant : public Student
{
	private:
		std::vector<Course *> assignedCourseList;		// List of assigned courses
		
	public:
		Assistant(std::string studName, 
			std::string ID, std::string DOB, 
			std::string studGender, std::string dept, 
			std::string lvl, std::string type);					// Constructor to create an assistant
		virtual ~Assistant();													// Destructor to destroy an assistant
		void assign(Course *course);									// Add a course to course list
		void remove(Course *course);									// Remove a course from course list
		void printAssignedCourseList();								// Output list of assigned courses
		virtual void printInfo();											// Output the assistant's information
};

#endif