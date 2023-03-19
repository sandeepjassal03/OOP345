/*
*****************************************************************************
							Workshop-3

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 02/02/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"

namespace sdds
{
	std::ostream& Pair::display(std::ostream& ostr) const
	{
		ostr.width(20);
		ostr << m_key;
		ostr << ": ";
		ostr << m_value;
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Pair& src)
	{
		// Inserts the content into the stream using the display function
		src.display(ostr);
		return ostr;
	}
	bool Pair::operator==(const Pair& p2) const
	{
		// Two objects of Pair are same if their keys match: and so the statement below:
		return (this->m_key == p2.m_key);
	}
}
