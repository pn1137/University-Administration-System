/*
 *	Class of functions to create and initialize objects
 *	Patrick Naugle : 23 November 2016
 */

#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <vector>

// Forward declarations
class Department;
class Course;
class Student;
class Teacher;

class Initialize
{
	private:
		Initialize(){};																			// Not intended to be created														
		
	public:
		static std::vector<Department *> init_departments();// Initialize departments
		static std::vector<Course *> init_courses(
			std::vector<Department *> depts);									// Initialize courses
		static std::vector<Student *> init_students(
			std::vector<Department *> depts, 
			std::vector<Course *> courses);										// Initialize students
		static std::vector<Teacher *> init_teachers(
			std::vector<Department *> depts, 
			std::vector<Course *> courses);										// Initialize teachers
};

#endif