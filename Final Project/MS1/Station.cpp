/*
*****************************************************************************
							Milestone-1

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 15/03/2023

Authenticity Declaration:
I confirm that I am the only author of this file
and the content was created entirely by me.
*****************************************************************************
*/
#include "Station.h"

namespace sdds
{
	// Initialising the Class variables to their default values.
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;


	// DEFAULT CONSTRUCTOR
	Station::Station()
	{
		m_id = 0;
		m_handledItem = {};
		m_description = {};
		m_nextSerial = {};
		m_quantity = {};
	}
	Station::Station(const std::string str)
	{
		// Create a local instance of utilities
		Utilities util;
		bool more = true;
		size_t pos = 0u;

		// Uses the extractToken function from Utilities to extract the values from the parameter string str
		m_handledItem = util.extractToken(str, pos, more);
		m_nextSerial = stoi(util.extractToken(str, pos, more));
		m_quantity = stoi(util.extractToken(str, pos, more));

		// Set the class variable m_widthField to the maximum value of Station::m_widthField or m_widthField in Utilities
		if (Station::m_widthField < util.getFieldWidth())
			Station::m_widthField = util.getFieldWidth();
		m_description = util.extractToken(str, pos, more);

		// Set id equal to the class variable id_generator + 1
		m_id = ++id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return m_handledItem;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_nextSerial++;
	}
	size_t Station::getQuantity() const
	{
		return m_quantity;
	}
	void Station::updateQuantity()
	{
		if (m_quantity != 0)
		{
			--m_quantity;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		// If the boolean full is true, display all details, else do not display quantity and description
		if (full)
		{
			os.setf(std::ios::right);
			os.width(3);
			os.fill('0');
			os << m_id;
			os << " | ";
			os.unsetf(std::ios::right);

			os.setf(std::ios::left);
			os.width(m_widthField + 1);
			os.fill(' ');
			os << m_handledItem;
			os << " | ";
			os.unsetf(std::ios::left);

			os.setf(std::ios::right);
			os.width(6);
			os.fill('0');
			os << m_nextSerial;
			os << " | ";
			os.unsetf(std::ios::right);

			os.setf(std::ios::right);
			os.width(4);
			os.fill(' ');
			os << m_quantity;
			os << " | ";
			os.unsetf(std::ios::right);
		
			os << m_description;
			os.unsetf(std::ios::left);
		}
		else
		{
			os.setf(std::ios::right);
			os.width(3);
			os.fill('0');
			os << m_id;
			os << " | ";
			os.unsetf(std::ios::right);

			os.setf(std::ios::left);
			os.width(m_widthField + 1);
			os.fill(' ');
			os << m_handledItem;
			os << " | ";
			os.unsetf(std::ios::left);

			os.setf(std::ios::right);
			os.width(6);
			os.fill('0');
			os << m_nextSerial;
			os << " | ";
			os.unsetf(std::ios::right);
		}
		os << std::endl;
	}
}