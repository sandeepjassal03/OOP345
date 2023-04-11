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
#include "Workstation.h"

namespace sdds
{
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	// Calls the Station class constructor to construct Workstation
	Workstation::Workstation(const std::string& str) :Station(str)
	{

	}
	void Workstation::fill(std::ostream& os)
	{
		// If the m_orders is not empty, fill 1 item for the customer on the front of the deque
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool returnVal = false;

		if (!m_orders.empty())
		{
			// If the item has been filled or cannot be filled, move the item to the next station
			// or move it to the complete or incomplete deque if there is no next station
			if (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() == 0)
			{
				if (m_pNextStation)
				{
					// Using += operator to add the new order to the back of the deque
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					returnVal = true;
				}
				else
				{
					// If the order was filled, move it to the g_completed deque otherwise to the g_incomplete deque
					// In any case, pop the order from the m_orders deque
					if (m_orders.front().isOrderFilled())
					{
						g_completed.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
						returnVal = true;
					}
					else if (m_orders.front().isOrderFilled() == false)
					{
						g_incomplete.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
						returnVal = true;
					}
				}
			}
		}

		return returnVal;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
		{
			os << Station::getItemName() << " --> " << m_pNextStation->getItemName();
		}
		else
		{
			os << Station::getItemName() << " --> " << "End of Line";
		}
		os << std::endl;
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}