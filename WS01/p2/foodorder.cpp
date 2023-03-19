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
#define _CRT_SECURE_NO_WARNINGS

#include "foodorder.h"

// Global variables declarations and initialisation to 0.
double g_taxrate = 0;
double g_dailydiscount = 0;

namespace sdds
{
	//setEmpty(): Sets the member variables of the FoodOrder class to safe empty state.
	void FoodOrder::setEmpty()
	{
		m_name[0] = '\0';
		delete[] m_description;
		m_description = nullptr;
		m_price = 0;
		daily_special = false;
	}

	// DEFAULT CONSTRUCTOR: Sets the newly created object to safe empty state
	FoodOrder::FoodOrder()
	{
		m_name[0] = '\0';
		m_description = nullptr;
		m_price = 0;
		daily_special = false;
	}

	// COPY CONSTRUCTOR: Sets the current object to the object passed as parameter.
	// Also, does inline initialisation by using the Default Constructor
	FoodOrder::FoodOrder(const FoodOrder& src)
	{
		// Uses the overloaded assignment operator to copy the resources from src to current object
		*this = src;
	}

	// OVERLOADED ASSIGNMENT OPERATOR
	FoodOrder& FoodOrder::operator=(const FoodOrder& src)
	{
		// Checks for self-assignment
		if (this != &src)
		{
			// Removes existing DMA if any
			delete[] m_description;

			// Shallow copying non-resource variables
			if (src.m_name[0] != '\0')
			{
				strcpy(m_name, src.m_name);
				m_price = src.m_price;
				daily_special = src.daily_special;

				// Allocates new memory for m_description based on the src object and copies contents.
				m_description = new char[strlen(src.m_description) + 1];
				strcpy(m_description, src.m_description);
			}

		}

		// Returns the reference of the current object
		return *this;
	}

	// DESTRUCTOR: Deletes any DMA before the object goes out of scope
	FoodOrder::~FoodOrder()
	{
		delete[] m_description;
	}

	// read(): Modifier: receives a reference to istream and returns it at the end
	std::istream& FoodOrder::read(std::istream& istr)
	{

		// temporary instance of std::string for storing data taken from file for further use
		std::string temp;

		// Reads name of the customer from the file until the delimiter or the maximum size passed is reached
		istr.getline(m_name, 9, ',');

		// std::getline() : Takes the reference of istream and reads the data read from the file into temp.
		std::getline(istr, temp, ',');

		// Reads m_price from file and ignores the comma
		istr >> m_price;
		istr.ignore();

		// Assigns value to daily_special as true or false based on the character read from the file
		istr.get() == 'Y' ? daily_special = true : daily_special = false;

		// Ignores the newline character
		istr.ignore();

		// If istr failed at any point, set the current object to safe empty state
		if (istr.fail())
		{
			setEmpty();
		}
		// otherwise, allocate memory to m_description
		else
		{
			// clean-up previous memory if any
			delete[] m_description;
			// std::string::length: returns the length of the object of std::string (temp)
			// std::string::c_str: returns a pointer to a null-terminated character array having data as in the string
			m_description = new char[temp.length() + 1];
			strcpy(m_description, temp.c_str());
		}
		// Returns the reference of the istream
		return istr;
	}

	// display(): A query that displays the contents of the current object using ostream and returns the reference of the ostream received as a parameter at the end.
	std::ostream& FoodOrder::display(std::ostream& ostr) const
	{
		// static int: Used as a counter so that it stays till the program exits and doesnot go out of scope at the end of the function.
		static int counter = 1;

		ostr.setf(std::ios::left);
		ostr.width(2);
		ostr << counter << ". ";

		if (m_name[0] != '\0')
		{
			ostr.setf(std::ios::left);
			ostr.width(10);
			ostr << m_name;
			ostr << "|";

			ostr.setf(std::ios::left);
			ostr.width(25);
			ostr << m_description;
			ostr << "|";

			ostr.setf(std::ios::left);
			ostr.width(12);

			//std::fixed, std::setprecision(): Displays the calculated price with 2 decimal point precision
			ostr << std::fixed << std::setprecision(2) << m_price + m_price * g_taxrate;
			ostr << "|";
			ostr.unsetf(std::ios::left);

			if (daily_special)
			{
				ostr.setf(std::ios::right);
				ostr.width(13);
				ostr << std::fixed << std::setprecision(2) << (m_price + m_price * g_taxrate - g_dailydiscount);
				ostr.unsetf(std::ios::right);
			}
		}
		else
		{
			ostr << "No Order";
		}
		counter++;
		ostr << std::endl;

		// Returns the reference of the ostream
		return ostr;
	}
}