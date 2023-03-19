/*
*****************************************************************************
							Workshop-4

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 11/02/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Toy.h"

namespace sdds
{
	/*******************************
			 CONSTRUCTORS
	*******************************/
	Toy::Toy()
	{
		m_orderID = 0;
		m_name = {};
		m_quantity = 0;
		m_price = 0;
	}

	Toy::Toy(const std::string& toy)
	{
		std::string copy{ toy };
		std::string temp{};

		/****************************************/
		// Find the index of the first colon
		auto index = copy.find(':');

		// Set the temp string to a string starting from 0 to the index using substr
		temp = copy.substr(0, index);

		// Extract the integer value from the string temp using stoi
		m_orderID = std::stoi(temp);

		// Erase the contents of the copy string from 0th index till the index of the colon + 1
		copy.erase(0, index + 1);
		/****************************************/

		// Re-find the index of the first colon
		index = copy.find(':');

		// Set the temp string to a string starting from 0 to the index using substr
		temp = copy.substr(0, index);

		// find_first_not_of(): Using this function, find the index in the string starting from the beginning where the character is not a space
		auto first = temp.find_first_not_of(' ');

		// find_last_not_of(): Using this function, find the index in the string starting from the end where the character is not a space
		auto last = temp.find_last_not_of(' ');

		// Set the temp string to a string starting from first of size (last - first) + 1
		m_name = temp.substr(first, (last - first) + 1);
		
		// Erase the contents of the copy string from 0th index till the index of the colon + 1
		copy.erase(0, index + 1);
		/********************************************/

		index = copy.find(':');

		// Set the temp string to a string starting from 0 to the index using substr
		temp = copy.substr(0, index);

		// Extract the integer value from the string temp using stoi
		m_quantity = std::stoi(temp);

		// Erase the contents of the copy string from 0th index till the index of the colon + 1
		copy.erase(0, index + 1);
		/********************************************/
		
		// Re-find the index of the first colon
		index = copy.find(':');

		// Set the temp string to a string starting from 0 to the index using substr
		temp = copy.substr(0, index);
		
		// Extract the double value from the string temp using stod
		m_price = std::stod(temp);

		// Erase the contents of the copy string from 0th index till the index of the colon + 1
		copy.erase(0, index + 1);
		/********************************************/
	}

	/*******************************
		PUBLIC MEMBER FUNCTIONS
	*******************************/
	void Toy::update(int numItems)
	{
		m_quantity = numItems;
	}
	std::ostream& Toy::display(std::ostream& ostr) const
	{
		auto subtotal = m_quantity * m_price;
		auto tax = m_quantity * m_price * HST;

		ostr << "Toy";
		ostr.width(8);
		ostr << m_orderID << ":";

		ostr.width(18);
		ostr.setf(std::ios::right);
		ostr << m_name;
		ostr.unsetf(std::ios::right);

		ostr.width(3);
		ostr << m_quantity << " items";

		ostr.width(8);
		ostr << m_price << "/item  subtotal:";

		ostr.width(7);
		ostr << subtotal << " tax:";

		ostr.width(6);
		ostr.precision(2);
		ostr << std::fixed << tax << " total:";

		ostr.width(7);
		ostr.precision(2);
		ostr << std::fixed << subtotal + tax << std::endl;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Toy& src)
	{
		src.display();
		return ostr;
	}
}