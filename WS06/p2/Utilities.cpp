/*
*****************************************************************************
							Workshop-6

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 08/03/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Utilities.h"

namespace sdds
{
	Person* buildInstance(std::istream& in)
	{
		Person* returnVal = nullptr;
		char input{};
		std::string temp{};
		std::stringstream stream;

		// Gets first character (TAG) from the in
		in >> input;
		// Extracts the remaining line till '\n' from in
		std::getline(in, temp, '\n');

		// Writes the extracted line to the stringstream stream
		stream << temp;

		// If the character is a letter e or E: Creates instance of Employee
		if (input == 'e' || input == 'E')
		{
			returnVal = new Employee(stream);
		}
		// If the character is a letter p or P: Creates instance of Professor
		else if (input == 'p' || input == 'P')
		{
			returnVal = new Professor(stream);
		}
		// If the character is a letter s or S: Creates instance of Student
		else if (input == 's' || input == 'S')
		{
			returnVal = new Student(stream);
		}

		// returns the returnVal pointer
		return returnVal;
	}
}
