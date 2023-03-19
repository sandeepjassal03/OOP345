/*
*****************************************************************************
							Workshop-2

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 25/01/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H

#include <iostream>
#include <string>
#include <fstream>
namespace sdds
{
	class ProteinDatabase
	{
		// MEMBER VARIABLES
		size_t m_size;
		std::string* m_database;

	public:
		/*************************************
				*** CONSTRUCTORS ***
		**************************************/

		// Default Constructor
		ProteinDatabase();

		// 1-arg Constructor
		ProteinDatabase(const char* filename);

		// Copy Constructor
		ProteinDatabase(const ProteinDatabase& src);

		// Move Constructor
		ProteinDatabase(ProteinDatabase&& src);

		/*************************************
			  *** MEMBER OPERATORS ***
		**************************************/
		ProteinDatabase& operator=(const ProteinDatabase& src);
		ProteinDatabase& operator=(ProteinDatabase&& src);
		std::string operator[](size_t index) const;

		// Destructor
		~ProteinDatabase();

		// Member Function
		size_t size() const;
	};
}

#endif