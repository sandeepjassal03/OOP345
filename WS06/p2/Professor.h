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
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include <iostream>
#include <string>
#include "Employee.h"

namespace sdds
{
	class Professor : public Employee
	{
		std::string m_department{};
	public:
		Professor(std::istream& in);
		void display(std::ostream& out) const;
		std::string status() const;
		std::string department() const;
	};
}

#endif
