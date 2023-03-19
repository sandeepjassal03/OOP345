/*
*****************************************************************************
							Workshop-1

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 20/01/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
// Header Safeguards
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

// Libraries
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

// Global Variables Declarations as externs
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
	class FoodOrder {

		// Member Variables
		char m_name[9 + 1]{};
		char* m_description{};
		double m_price{};
		bool daily_special{};

		// Private Member Function
		void setEmpty();
	public:
		// Public Member Functions
		
		// Default Constructor
		FoodOrder();

		// Copy Constructor
		FoodOrder(const FoodOrder& src);

		// Overloaded assignment operator
		FoodOrder& operator=(const FoodOrder& src);

		// Destructor
		~FoodOrder();

		// read(): Modifier Function
		std::istream& read(std::istream& istr = std::cin);

		// display(): Query
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}
#endif