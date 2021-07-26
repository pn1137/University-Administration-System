/*
 *	C++ class that represents a university course
 *	Patrick Naugle : 17 November 2016
 */
 
#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>

// Forward declarations
class Student;
class Person;

class Course
{
	private:
		std::string level;														// Level of the course
		std::string title;														// Title of the course
		std::string departmentName;										// Department of the course
		std::vector<Student *> studentList;						// List of students in the course
		std::vector<double> grades;										// Grades of the students
		std::vector<Person *> teacherList;						// List of the teachers for the course
		
	public:
		Course(std::string courseTitle, 
		std::string courseLevel, std::string dept);		// Constructor to create a course
		~Course();																		// Destructor to destroy a course
		void setGrade(std::string studentID, 
			double grade);															// Set the value of a grades element
		void addStudent(Student *student);						// Add a student to studentList
		void addTeacher(Person *teacher);							// Add a teacher to teacherList
		void removeStudent(Student *student);					// Remove a student from studentList
		void removeTeacher(Person *teacher);					// Remove a teacher from teacherList
		std::string getLevel();												// Return level
		std::string getTitle();												// Return course title
		std::string getDepartmentName();							// Return department name
		void printGrades();														// Output students and grades
		void printTeacherList();											// Output the list of teachers
};

#endif