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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds
{
	class Book
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_countryOfPublish{};
		size_t m_yearOfPublish{};
		double m_price{};
		std::string m_description{};
		std::string removeSpaces(std::string& temp, const char delim);
	public:
		Book();
		Book(const std::string& strBook);
		double& price();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		std::ostream& display(std::ostream& ostr = std::cout) const;
		friend std::ostream& operator<<(std::ostream& ostr, const Book& src);

		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
		}
	};
}

#endif