/*
 *	Class of functions to read in information from txt files
 *	Patrick Naugle : 23 November 2016
 */

#ifndef FILEREADIN_H
#define FILEREADIN_H

#include <vector>
#include <string>
 
class FileReadIn
{
	private:
		FileReadIn(){};																	// Not intended to be created
		
	public:
		static std::vector<std::string> departments();	// Read in departments
		static std::vector<std::string> courses();			// Read in courses
		static std::vector<std::string> students();			// Read in students
		static std::vector<std::string> teachers();			// Read in teachers
};

#endif