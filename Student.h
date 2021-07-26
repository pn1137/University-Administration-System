/*
 *	C++ class that represents a student
 *	Inherits from Person
 *	Patrick Naugle : 22 November 2016
 */
 
#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "Person.h"

// Forward declarations
class Course;
class Assistant;

class Student : public Person
{
	private:
		std::string departmentName;									// Department of the student
		std::string level;													// Class level of the student
		std::string gradType;												// Optional type for graduate students
		Assistant *assistant;												// Optional teaching assistant pointer
		std::vector<Course *> courseList;						// List of enrolled courses
		
	public:
		Student(std::string studName, std::string ID, 
			std::string DOB, std::string studGender, 
			std::string dept, std::string lvl, 
			std::string type);												// Constructor to create a student
		Student(std::string studName, std::string ID, 
			std::string DOB, std::string studGender, 
			std::string dept, std::string lvl, 				// Constructor to create a teaching 
			std::string type, Assistant *asst);				//// assistant student
		virtual ~Student();													// Destructor to destroy a student
		void enroll(Course *course);								// Enroll in a course
		void drop(Course *course);									// Drop from a course
		void setLevel(std::string lvl);							// Set the student level
		void setType(std::string type);							// Set an optional graduate type
		void setAssistant(Assistant *asst);					// Set teaching assistant pointer
		Assistant *getAssistant();									// Return a pointer to teaching assistant
		std::string getLevel();											// Return the student level
		std::string getGradType();									// Return the optional graduate type
		std::string getDepartmentName();						// Returns department
		void printCourseList();											// Output the list of enrolled courses
		virtual void printInfo();										// Output the student's information
};

#endif