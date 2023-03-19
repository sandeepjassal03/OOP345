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
#include "College.h"

namespace sdds
{
	College::College()
	{
		m_persons = {};
	}
	College& College::operator +=(Person* thePerson)
	{
		// Adds the thePerson pointer into the m_persons array
		m_persons.push_back(thePerson);
		return *this;
	}
	void College::display(std::ostream& out) const
	{
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		out << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;	

		// Using std::iterators to print data to the screen
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			(*it)->display(out);
			out << std::endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		out << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			out.setf(std::ios::left);
			out << "| ";
			out.width(10);
			out << (*it)->status();
			out << "| ";
			out.width(10);
			out << (*it)->id();
			out << "| ";
			out.width(20);
			out << (*it)->name();
			out << " | ";
			out.width(3);
			out << (*it)->age();
			out << " |";
			out.unsetf(std::ios::left);
			out << std::endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}

	College:: ~College()
	{
		// Deletes the object pointed to by every element of the m_persons array
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			delete *it;
		}
	}
}