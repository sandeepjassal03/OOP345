/*
*****************************************************************************
							Milestone-2

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
#include "CustomerOrder.h"

namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;

	void CustomerOrder::resize(Item* item)
	{
		// Create a temp array of size m_cntItem + 1
		PtrToItem* temp = new PtrToItem[m_cntItem + 1];

		/*** 2. Copy all the existing data into the temp array ***/
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			temp[i] = m_lstItem[i];
		}

		/*** 3. Add the address of the item in the parameter to the temporary array ***/
		temp[m_cntItem] = item;


		/*** 4. Deletes the existing DMA at m_lstItem ***/
		delete[] m_lstItem;

		/*** 5.Set the m_lstItem to point to the temporary array
		 Set temp to nullptr ***/
		m_lstItem = temp;
		temp = nullptr;

		/*** 6. Increment m_cntItem by 1 ***/
		++m_cntItem;
	}
	void CustomerOrder::deallocate()
	{
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
	CustomerOrder::CustomerOrder()
	{
		m_name = {};
		m_product = {};
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	CustomerOrder::CustomerOrder(std::string str)
	{
		// Create a local instance of utilities
		Utilities util;
		bool more = true;
		size_t pos = 0u;

		// Uses the extractToken function from Utilities to extract the values from the parameter string str
		m_name = util.extractToken(str, pos, more);
		m_product = util.extractToken(str, pos, more);

		for (auto i = 0u; more; ++i)
		{
			std::string temp;
			temp = util.extractToken(str, pos, more);
			Item* item = new Item(temp);
			resize(item);
		}

		// Set the class variable m_widthField to the maximum value of CustomerOrder::m_widthField or m_widthField in Utilities
		if (CustomerOrder::m_widthField < util.getFieldWidth())
			CustomerOrder::m_widthField = util.getFieldWidth();
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		// throws exception if copy construction is attempted
		throw "Copy Construction is not allowed!";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		// 1. Check for self-assignment 
		if (this != &src)
		{
			// 2. Delete existing DMA
			deallocate();

			// 3. Shallow copy all non-resource variables
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;

			// 4. Set the m_lstItem double pointer to the one in the src parameter
			m_lstItem = src.m_lstItem;

			// 5. Set the member variables of the src parameter to empty state
			src.m_lstItem = nullptr;
			src.m_cntItem = 0;
			src.m_product = {};
			src.m_name = {};
		}

		// Returns the reference of the current object
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		deallocate();
	}
	bool CustomerOrder::isOrderFilled() const
	{
		bool isFilled = true;

		// Iterate through the complete list to find if any item is not filled yet
		for (auto i = 0u; i < m_cntItem && isFilled; ++i)
		{
			// If even one item is not filled, set isFilled to false and exit loop
			if (m_lstItem[i]->m_isFilled == false)
			{
				isFilled = false;
			}
		}

		// Returns isFilled
		return isFilled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = true;

		// Iterates through the loop to find if all items by the name itemName are filled, even if one is not filled, this function returns false
		for (auto i = 0u; i < m_cntItem && filled; ++i)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (m_lstItem[i]->m_isFilled == true)
				{
					filled = true;
				}
				else
				{
					filled = false;
				}
			}
		}
		return filled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool found = false;
		size_t index = 0;

		// Loop to find out the position of the item handled by the station in the list
		for (auto i = 0u; i < m_cntItem && !found; ++i)
		{
			if (station.getItemName() == m_lstItem[i]->m_itemName)
			{
				// If the item is found, set the index to i and exit the loop
				index = i;
				found = true;
			}
		}

		// If the item was found, fill it, othwerwise, do nothing
		if (found)
		{
			// If the station has enough inventory, fill the item, othwerwise, print a message saying unable to fill
			if (station.getQuantity() > 0)
			{
				// Update the station's inventory
				station.updateQuantity();

				// Set the m_isFilled for the item to true and the m_serialNumber to the value returned by the Station::getNextSerialNumber()
				m_lstItem[index]->m_isFilled = true;
				m_lstItem[index]->m_serialNumber = station.getNextSerialNumber();
				os << "    Filled " << m_name << ", " << m_product
					<< "[" << m_lstItem[index]->m_itemName << "]" << std::endl;
			}
			else
			{
				os << "    Unable to fill " << m_name << ", " << m_product
					<< "[" << m_lstItem[index]->m_itemName << "]" << std::endl;
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			os << "[";
			os << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os << std::left << std::setw(m_widthField + 2) << std::setfill(' ') << m_lstItem[i]->m_itemName;
			os << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" : os << "TO BE FILLED";
			os << std::endl;
		}

	}
}