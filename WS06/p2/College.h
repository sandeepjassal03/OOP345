/*
*****************************************************************************
							Workshop-6

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 08/03/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Person.h"

namespace sdds
{
	class College
	{
		std::vector<Person*> m_persons{};
	public:
		College();
		College(College& src) = delete;
		College& operator=(College& src) = delete;
		College& operator +=(Person* thePerson);
		void display(std::ostream& out) const;
		~College();

		template <typename T>
		void select(const T& test, std::list<const Person*>& persons)
		{
			for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
			{
				// Passes the iterator object to the test parameter, if test returns true, pushes the object into persons list
				if (test(*it))
				{
					persons.push_back(*it);
				}
			}
		}
	};
}

#endif