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
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H

#include "Child.h"

namespace sdds
{
	class ConfirmOrder
	{
		/*******************************
			  PRIVATE DATA MEMBERS
		*******************************/
		PtrToToy* m_toyList{};
		size_t m_size{};

	public:
		/*******************************
			     CONSTRUCTORS
		*******************************/
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& src);
		ConfirmOrder(ConfirmOrder&& src);

		/*******************************
				MEMBER OPERATORS
		*******************************/
		ConfirmOrder& operator=(const ConfirmOrder& src);
		ConfirmOrder& operator=(ConfirmOrder&& src);
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);

		// *** DESTRUCTOR ***
		~ConfirmOrder();

		// Friend Operator
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& src);
	};
}

#endif