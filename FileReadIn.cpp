/*
 *	Functions to read in information from txt files
 *	Patrick Naugle : 23 November 2016
 */
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "FileReadIn.h"
#include "Department.h"
#include "Course.h"
#include "Student.h"
#include "Teacher.h"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;
using std::istringstream;

/*
 *	Read in departments
 */
vector<string> FileReadIn::departments()
{
	vector<string> vect;
	
	string departments = "Departments.txt";
	
	ifstream file;
	file.open(departments);
	
	if (file.is_open())
	{
		string line;															// Line from file
		
		while (getline(file, line))								// Get line
		{
			if (!(line.at(0) == '/'))								// Ignore comments
			{
				vect.push_back(line);									// Store line
			}
		}
	}
	else
	{
		cout << "ERROR opening file: " << departments << " could not be opened.\n";
		exit(-1);
	}
	
	return vect;
}

/*
 *	Read in courses
 */
vector<string> FileReadIn::courses()
{
	vector<string> vect;												// Vector to hold token strings
	
	string courses = "Courses.txt";
	
	ifstream file;
	file.open(courses);													// Open file
	
	if (file.is_open())
	{
		string line;															// Line from file
		string tok;																// Token
		
		
		while (getline(file, line))
		{
			if (!(line.at(0) == '/'))								// Ignore comments
			{
				istringstream temp(line);							// Temp stream of line
				
				while (getline(temp, tok, ','))				// Get token
				{
					if (tok.at(0) == ' ')								// Remove leading whitespace
					{
						tok.erase(0,1);
					}
					vect.push_back(tok);								// Store token
				}
			}
		}
	}
	else
	{
		cout << "ERROR opening file: " << courses << " could not be opened.\n";
		exit(-1);
	}
	
	return vect;
}

/*
 *	Read in students
 */
vector<string> FileReadIn::students()
{
	vector<string> vect;												// Vector to hold token strings
	
	string students = "Students.txt";
	
	ifstream file;
	file.open(students);												// Open file
	
	if (file.is_open())
	{
		string line;															// Line from file
		string tok;																// Token
		
		
		while (getline(file, line))
		{
			if (!(line.at(0) == '/'))								// Ignore comments
			{
				istringstream temp(line);							// Temp stream of line
				
				while (getline(temp, tok, ','))				// Get token
				{
					if (tok.at(0) == ' ')								// Remove leading whitespace
					{
						tok.erase(0,1);
					}
					vect.push_back(tok);								// Store token
				}
			}
		}
	}
	else
	{
		cout << "ERROR opening file: " << students << " could not be opened.\n";
		exit(-1);
	}
	
	return vect;
}

/*
 *	Read in teachers
 */
vector<string> FileReadIn::teachers()
{
	vector<string> vect;												// Vector to hold token strings
	
	string teachers = "Teachers.txt";
	
	ifstream file;
	file.open(teachers);												// Open file
	
	if (file.is_open())
	{
		string line;															// Line from file
		string tok;																// Token
		
		
		while (getline(file, line))
		{
			if (!(line.at(0) == '/'))								// Ignore comments
			{
				istringstream temp(line);							// Temp stream of line
				
				while (getline(temp, tok, ','))				// Get token
				{
					if (tok.at(0) == ' ')								// Remove leading whitespace
					{
						tok.erase(0,1);
					}
					vect.push_back(tok);								// Store token
				}
			}
		}
	}
	else
	{
		cout << "ERROR opening file: " << teachers << " could not be opened.\n";
		exit(-1);
	}
	
	return vect;
}