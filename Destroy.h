/*
 *	Class of functions to destroy objects
 *	Patrick Naugle : 23 November 2016
 */	
	
	#ifndef DESTROY_H
	#define DESTROY_H
	
	#include <vector>
	
	// Forward declarations
	class Department;
	class Course;
	class Student;
	class Teacher;
	
	class Destroy
	{
		private:
			Destroy(){};																					// Not intended to be created
			
		public:
			static void deallocate_all(
				std::vector<Department *> depts, 
				std::vector<Course *> courses,	
				std::vector<Student *> students, 
				std::vector<Teacher *> teachers);										// Destroy all objects
	};
	
	#endif