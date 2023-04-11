/*
*****************************************************************************
							Milestone-3

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 15/03/2023

Authenticity Declaration:
I confirm that I am the only author of this file
and the content was created entirely by me.
*****************************************************************************
*/
#include "Utilities.h"

namespace sdds
{
	// Initialising the Class variable
	char Utilities::m_delimiter = {};


	// DEFAULT CONSTRUCTOR
	Utilities::Utilities()
	{
		m_widthField = 1;
	}

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string temp{};

		// Find the position of the delimieter stored in m_delimiter starting from next_pos
		auto delim = str.find(m_delimiter, next_pos);

		// If the delimiter is found at the next_pos, throw an error and set more to false since there is nothing more to read
		if (delim == next_pos)
		{
			more = false;
			throw ("Delimiter found at: " + next_pos);
		}

		// Otherwise, copy the substring into temp starting from position delim with the particular size
		temp = str.substr(next_pos, (delim - next_pos));

		// Increment next_pos by size of temp + 1 ( +1 to get rid of the delimiter along)
		next_pos += temp.size() + 1;

		// Remove the leading and trailing spaces from the temp string
		removeSpaces(temp);

		// If delim is still less than the original string size, set more to true, false otherwise.
		delim < str.size() ? more = true : more = false;

		// If the m_widthField is less than temp size, set it equal to temp size.
		if (m_widthField < temp.size())
			m_widthField = temp.size();

		// Return the string temp
		return temp;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

	void Utilities::removeSpaces(std::string& copy)
	{
		// Find the first and last position in the string which is not a space
		auto first = copy.find_first_not_of(' ');
		auto last = copy.find_last_not_of(' ');
		// Set copy to the substring resulting from the line below, removing all the spaces.
		copy = copy.substr(first, (last - first) + 1);
	}
}