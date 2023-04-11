/*
*****************************************************************************
							Milestone-3

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 20/03/2023

Authenticity Declaration:
I confirm that I am the only author of this file
and the content was created entirely by me.
*****************************************************************************
*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sdds
{
	class Station
	{
		size_t m_id{};
		std::string m_handledItem{};
		std::string m_description{};
		size_t m_nextSerial{};
		size_t m_quantity{};
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station();
		Station(const std::string str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
};


#endif