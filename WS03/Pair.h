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
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_

#include <iostream>
#include <string>

namespace sdds
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};


		// New Member Function Prototypes
		Pair() 
		{
			m_key = {};
			m_value = {};
		}	
		std::ostream& display(std::ostream& ostr) const;
		bool operator==(const Pair& p2) const;
	};

	// Helper Operator
	std::ostream& operator<<(std::ostream& ostr,const Pair& src);
}


#endif
