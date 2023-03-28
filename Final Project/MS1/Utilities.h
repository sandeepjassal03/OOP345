/*
*****************************************************************************
							Milestone-1

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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <string>

namespace sdds
{
	class Utilities
	{
		size_t m_widthField = 1;
		static char m_delimiter;
		void removeSpaces(std::string& copy);
	public:
		Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
};


#endif