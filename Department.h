/*
 *	C++ class that represents a university department
 *	Patrick Naugle : 22 November 2016
 */
 
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <string>

// Forward declarations
class Student;
class Assistant;
class Teacher;
class Course;

class Department
{
	private:
		std::string departmentName;										// Name of the department
		std::vector<Student *> studentList;						// List of students in the department
		std::vector<Assistant *> assistantList;				// List of assistants in the department
		std::vector<Teacher *> teacherList;						// List of teachers in the department
		std::vector<Course *> courseList;							// List of courses in the department
	
	public:
		Department(std::string departmentTitle);			// Constructor to create a department
		~Department();																// Destructor to destroy a department
		void addStudent(Student *student);						// Add a student to the department
		void addAssistant(Assistant *assistant);			// Add an assistant to the department
		void addTeacher(Teacher *teacher);						// Add a teacher to the department
		void addCourse(Course *course);								// Add a course to the department
		std::string getDepartmentName();							// Returns the department name
		void removeStudent(Student *student);					// Remove a student from the department
		void removeAssistant(Assistant *assistant);		// Remove an assistant from the department
		void removeTeacher(Teacher *teacher);					// Remove a teacher from the department
		void removeCourse(Course *course);						// Remove a course from the department
		void printStudentList();											// Output the students in the department
		void printTeacherList();											// Output the teachers and assistants 
																									// in the department
		void printCourseList();												// Output the courses in the department
};

#endif