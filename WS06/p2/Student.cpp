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
#include "Student.h"

namespace sdds
{
	void Student::removeSpaces(std::string& copy)
	{
		auto first = copy.find_first_not_of(' ');
		auto last = copy.find_last_not_of(' ');
		copy = copy.substr(first, (last - first) + 1);
	}

	Student::Student(std::istream& istr)
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

		// get token from stream till ',
		std::getline(istr, temp, ',');
		// Removes leading and trailing spaces
		removeSpaces(temp);

		if (temp[0] == 'S')
			m_id = temp;
		else
			throw (m_name + "++Invalid record!");

		// Extracts m_count from stream and ignores the delimiter
		istr >> m_count;
		istr.ignore();

		m_courses = new std::string[m_count];
		for (auto i = 0u; i < m_count; ++i)
		{
			std::string course{};
			// If the course to be extracted is not the last, if holds true otherwise else holds true
			if (i < m_count - 1)
			{
				std::getline(istr, course, ',');
			}
			else
			{
				std::getline(istr, course, '\n');
			}

			// Removes leading and trailing spaces
			removeSpaces(course);
			m_courses[i] = course;
		}

	}
	Student::~Student()
	{
		delete[] m_courses;
		m_courses = nullptr;
	}
	std::string Student::status() const
	{
		return "Student";
	}
	std::string Student::name() const
	{
		return m_name;
	}
	std::string Student::age() const
	{
		return std::to_string(m_age);
	}
	std::string Student::id() const
	{
		return m_id;
	}

	void Student::display(std::ostream& out) const
	{
		out.setf(std::ios::left);
		out << "| ";
		out.width(10);
		out << "Student";
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
		for (auto i = 0u; i < m_count; ++i)
		{
			out << m_courses[i];
			if (i != m_count - 1)
			{
				out << ", ";
			}
		}
		out.unsetf(std::ios::left);
	}
}