/*
*****************************************************************************
							Workshop-5

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 15/02/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Movie.h"

namespace sdds
{
	Movie::Movie()
	{
		m_title = {};
		m_year = {};
		m_description = {};
	}
	Movie::Movie(const std::string& strMovie)
	{
		std::string copy{ strMovie };

		// Using removeSpaces function to get all attributes without any leading or trailing spaces
		m_title = removeSpaces(copy, ',');
		m_year = stoi(removeSpaces(copy, ','));
		m_description = removeSpaces(copy, '\n');
	}

	std::string Movie::removeSpaces(std::string& copy, const char delim)
	{
		std::string temp{};
		std::string str{};

		// Find the index where the delim character is found
		auto index = copy.find(delim);

		// Copy the string till that index into a temp string
		temp = copy.substr(0, index);

		// Get rid of all the spaces
		auto first = temp.find_first_not_of(' ');
		auto last = temp.find_last_not_of(' ');

		str = temp.substr(first, (last - first) + 1);

		// Erase the used string from the reference string
		copy.erase(0, index + 1);

		return str;
	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	std::ostream& Movie::display(std::ostream& ostr) const
	{
		ostr.width(40);
		ostr << std::right << m_title;
		ostr << " | ";

		ostr.width(4);
		ostr << m_year;
		ostr << " | ";

		ostr << m_description << std::endl;
		return ostr;
	}


	std::ostream& operator<<(std::ostream& ostr, const Movie& src)
	{
		src.display(ostr);
		return ostr;
	}
}