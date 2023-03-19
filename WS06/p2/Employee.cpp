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
#include "Employee.h"

namespace sdds
{
	Employee::Employee()
	{
		m_name = {};
		m_age = {};
		m_id = {};
	}

	void Employee::removeSpaces(std::string& copy)
	{
		auto first = copy.find_first_not_of(' ');
		auto last = copy.find_last_not_of(' ');
		copy = copy.substr(first, (last - first) + 1);
	}

	Employee::Employee(std::istream& istr)
	{
		std::string temp{};
		// ignore characters till the delimiter ','
		istr.ignore(10, ',');

		// get token from stream till ','
		std::getline(istr, temp, ',');

		// Removes leading and trailing spaces
		removeSpaces(temp);
		// Set m_name to temp
		m_name = temp;

		// get token from stream till ',
		std::getline(istr, temp, ',');
		// Removes leading and trailing spaces
		removeSpaces(temp);

		// Checks if the first character in the token is not a number, if yes, throws an exception
		if (temp[0] < '0' || temp[0] > '9')
		{
			throw (m_name + "++Invalid record!");
		}

		m_age = stoi(temp);
		istr.ignore();

		// get token from stream till ',
		std::getline(istr, temp, ',');
		// Removes leading and trailing spaces
		removeSpaces(temp);

		if (temp[0] == 'E')
			m_id = temp;
		else
			throw (m_name + "++Invalid record!");
	}
	std::string Employee::status() const
	{
		return "Employee";
	}
	std::string Employee::name() const
	{
		return m_name;
	}
	std::string Employee::age() const
	{
		return std::to_string(m_age);
	}
	std::string Employee::id() const
	{
		return m_id;
	}
	void Employee::display(std::ostream& out) const
	{
		out.setf(std::ios::left);
		out << "| ";
		out.width(10);
		out << "Employee";
		out << "| ";
		out.width(10);
		out << m_id;
		out << "| ";
		out.width(20);
		out << m_name;
		out << " | ";
		out.width(3);
		out << m_age;
		out << " |";
		out.unsetf(std::ios::left);
	}
}