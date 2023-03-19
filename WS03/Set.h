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
#ifndef SDDS_SET_H_
#define SDDS_SET_H_

#include <iostream>
#include "Collection.h"

namespace sdds
{
	template <typename T>
	class Set :public Collection <T,100u>
	{
	public:
		virtual bool add(const T& item)
		{
			bool found = false;
			bool returnVal = false;

			// Loop to check if any element matches the parameter item
			for (auto i = 0u; i < this->size() && !found; i++)
			{
				if (item == (*this)[i])
				{
					found = true;
				}
			}
			if (!found)
			{
				// Calling the add Function of the Collection template with parameters T and 100.
				returnVal = Collection<T,100u>::add(item);
			}
			return returnVal;
		}
	};

	template<>
	bool Set<double>::add(const double& item)
	{
		bool found = false;
		bool returnVal = false;

		// Loop to check if any element matches the parameter item
		for (auto i = 0u; i < this->size() && !found; i++)
		{
			if (std::abs(item - (*this)[i]) <= 0.01)
			{
				found = true;
			}
		}
		if (!found)
		{
			// Calling the add Function of the Collection template with parameters as double and 100.
			returnVal = Collection<double, 100u>::add(item);
		}
		return returnVal;
	}
}
#endif