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

#include "foodorder.h"

// Declaring global variables
double g_taxrate = 0;
double g_dailydiscount = 0;
namespace sdds
{
	void FoodOrder::setEmpty()
	{
		m_name[0] = '\0';
		m_description[0] = '\0';
		m_price = 0;
		daily_special = 0;
	}

	FoodOrder::FoodOrder()
	{
		m_name[0] = '\0';
		m_description[0] = '\0';
		m_price = 0;
		daily_special = 0;
	}
	void FoodOrder::display() const
	{
		static int counter = 1;

		std::cout.setf(std::ios::left);
		std::cout.width(2);
		std::cout << counter << ". ";
		std::cout.unsetf(std::ios::left);

		if (m_name[0]!='\0')
		{
			std::cout.setf(std::ios::left);
			std::cout.width(10);
			std::cout << m_name;
			std::cout << "|";
			std::cout.unsetf(std::ios::left);

			std::cout.setf(std::ios::left);
			std::cout.width(25);
			std::cout << m_description;
			std::cout << "|";
			std::cout.unsetf(std::ios::left);

			std::cout.setf(std::ios::left);
			std::cout.width(12);
			std::cout << std::fixed << std::setprecision(2) << m_price + m_price * g_taxrate;
			std::cout << "|";
			std::cout.unsetf(std::ios::left);

			if (daily_special)
			{
				std::cout.setf(std::ios::right);
				std::cout.width(13);
				std::cout << std::fixed << std::setprecision(2) << (m_price + m_price * g_taxrate - g_dailydiscount);
				std::cout.unsetf(std::ios::right);
			}
		}
		else
		{
			std::cout << "No Order";
		}
		counter++;
		std::cout << std::endl;
	}
	std::istream& FoodOrder::read(std::istream& istr)
	{
		istr.getline(m_name, 9, ',');
		istr.getline(m_description, 24, ',');
		istr >> m_price;
		istr.ignore();
		istr.get() == 'Y' ? daily_special = true : daily_special = false;
		istr.ignore();

		if (istr.fail())
		{
			setEmpty();
		}
		return istr;
	}

}