/*
*****************************************************************************
							Milestone-3

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 30/03/2023

Authenticity Declaration:
I confirm that I am the only author of this file
and the content was created entirely by me.
*****************************************************************************
*/
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation:public Station
	{
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{};
	public:
		Workstation(const std::string& str);
		Workstation(const Workstation& src) = delete;
		Workstation(Workstation&& src) = delete;
		Workstation& operator=(const Workstation& src) = delete;
		Workstation& operator=(Workstation&& src) = delete;
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif
