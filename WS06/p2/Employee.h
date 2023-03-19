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
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

namespace sdds
{
	class Employee : public Person
	{
		std::string m_name{};
		unsigned int m_age{};
		std::string m_id{};
		void removeSpaces(std::string& copy);
	public:
		Employee();
		Employee(std::istream& istr);
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream& out) const;
	};
}

#endif