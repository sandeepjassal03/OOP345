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
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include "Toy.h"

namespace sdds
{
	// Alias for a const Toy*
	using PtrToToy = const Toy*;
	class Child 
	{
		/*******************************
			  PRIVATE DATA MEMBERS
		*******************************/
		std::string m_name{};
		unsigned int m_age{};
		PtrToToy* m_toyList{};
		size_t m_size{};

		void deallocate();
	public:
		/*******************************
				 CONSTRUCTORS
		*******************************/
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& src);
		Child(Child&& src);

		/*******************************
				MEMBER OPERATORS
		*******************************/
		Child& operator=(const Child& src);
		Child& operator=(Child&& src);

		// *** DESTRUCTOR ***
		~Child();

		// *** MEMBER FUNCTION ***
		size_t size() const;
		
		// Friend Operator
		friend std::ostream& operator<<(std::ostream& ostr, const Child& src);
	};


}

#endif