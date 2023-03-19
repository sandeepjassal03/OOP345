/*
*****************************************************************************
						Workshop-1 PART-1

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 16/01/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>
#include <iomanip>

// Using extern keyword for declaration only
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
	class FoodOrder {
		// MEMBER VARIABLES
		char m_name[9 + 1]{};
		char m_description[24 + 1]{};
		double m_price;
		bool daily_special;

		// PRIVATE MEMBER FUNCTION
		void setEmpty();

		// PUBLIC MEMBER FUNCTIONS
	public:
		//DEFAULT CONSTRUCTOR
		FoodOrder();
		std::istream& read(std::istream& istr);
		void display() const;
	};
}

#endif