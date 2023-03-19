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
#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>
#include <string>

namespace sdds
{
	class Toy
	{
		/*******************************
			  PRIVATE DATA MEMBERS
		*******************************/
		unsigned int m_orderID{};
		std::string m_name{};
		int m_quantity{};
		double m_price{};
		const double HST{ 0.13 };
	public:

		/*******************************
				 CONSTRUCTORS
		*******************************/
		Toy();
		Toy(const std::string& toy);

		/*******************************
			PUBLIC MEMBER FUNCTIONS
		*******************************/
		void update(int numItems);
		std::ostream& display(std::ostream& ostr=std::cout) const;
		friend std::ostream& operator<<(std::ostream& ostr, const Toy& src);
	};

}

#endif