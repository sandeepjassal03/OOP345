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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
		std::string removeSpaces(std::string& copy, const char delim);
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		std::ostream& display(std::ostream& ostr = std::cout) const;

		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& ostr, const Movie& src);
	};
}

#endif