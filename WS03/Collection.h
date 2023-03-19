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
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

#include <iostream>
#include "Pair.h"

namespace sdds
{
	template<typename T, unsigned int CAPACITY>
	class Collection
	{
		static unsigned int m_totalCollections;
		T m_collections[CAPACITY]{};
		static T dummyObject;
	public:
		unsigned int size() const
		{
			return m_totalCollections;
		}
		std::ostream& display(std::ostream& ostr = std::cout) const
		{
			ostr << "----------------------" << std::endl;
			ostr << "| Collection Content |" << std::endl;
			ostr << "----------------------" << std::endl;
			for (auto i = 0u; i < m_totalCollections; ++i)
			{
				ostr << m_collections[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
			return ostr;
		}

		virtual bool add(const T& item)
		{
			bool returnVal = false;
			if (m_totalCollections != CAPACITY)
			{
				m_collections[m_totalCollections] = item;
				++m_totalCollections;
				returnVal = true;
			}
			return returnVal;
		}

		T operator[](unsigned int index) const
		{
			T returnVal{};
			if (index > m_totalCollections - 1)
			{
				returnVal = dummyObject;
			}
			else
			{
				returnVal = m_collections[index];
			}
			return returnVal;
		}
		~Collection() { };
	};
	
	// Initialising the static members of the Collection class Template
	template<typename T, unsigned int CAPACITY>
	unsigned int Collection<T, CAPACITY>::m_totalCollections = 0u;

	template<typename T, unsigned int CAPACITY>
	T Collection<T, CAPACITY>::dummyObject{};

	// Specialization for the Collection Class to initialise the dummy object as below when T is Pair and CAPACITY is 100.
	template<>
	Pair Collection<Pair, 100>::dummyObject = Pair("No Key", "No Value");
}
#endif
