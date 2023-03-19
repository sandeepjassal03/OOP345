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
#include "Professor.h"

namespace sdds
{
	// Makes an inline constructor call to the Employee Constructor to extract data
	Professor::Professor(std::istream& in):Employee(in)
	{
		std::string temp{};

		// Gets the token from the stream till \n
		std::getline(in, temp, '\n');
		
		// Removes leading and trailing spaces from temp
		auto first = temp.find_first_not_of(' ');
		auto last = temp.find_last_not_of(' ');
		m_department = temp.substr(first, (last - first) + 1);
	}
	void Professor::display(std::ostream& out) const
	{
		// Calls display of Employee to display content and then prints department
		Employee::display(out);
		out << m_department << "| Professor";
	}
	std::string Professor::status() const
	{
		return "Professor";
	}
	std::string Professor::department() const
	{
		return m_department;
	}
}