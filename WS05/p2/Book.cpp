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
#include "Book.h"

namespace sdds
{
	Book::Book()
	{
		m_author = {};
		m_title = {};
		m_countryOfPublish = {};
		m_yearOfPublish = {};
		m_price= {};
		m_description = {};
	}

	std::string Book::removeSpaces(std::string& copy, const char delim)
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
	Book::Book(const std::string& strBook)
	{
		std::string copy{ strBook };

		// Using removeSpaces function to get all attributes without any leading or trailing spaces
		m_author = removeSpaces(copy, ',');
		m_title = removeSpaces(copy, ',');
		m_countryOfPublish = removeSpaces(copy, ',');
		m_price = std::stod(removeSpaces(copy,','));
		m_yearOfPublish = std::stoi(removeSpaces(copy,','));
		m_description = removeSpaces(copy,'\n');

	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_countryOfPublish;
	}
	const size_t& Book::year() const
	{
		return m_yearOfPublish;
	}

	double& Book::price()
	{
		return m_price;
	}
	std::ostream& Book::display(std::ostream& ostr) const
	{
		ostr.width(20);
		ostr << std::right << m_author;
		ostr << " | ";

		ostr.width(22);
		ostr << std::right << m_title;
		ostr << " | ";

		ostr.width(5);
		ostr << std::right << m_countryOfPublish;
		ostr << " | ";

		ostr.width(4);
		ostr  << m_yearOfPublish;
		ostr << " | ";

		ostr.width(6);
		ostr.precision(2);
		ostr << std::fixed << m_price;
		ostr << " | ";

		ostr << m_description;
		ostr << std::endl;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& src)
	{
		src.display(ostr);
		return ostr;
	}
}