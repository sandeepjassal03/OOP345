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
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include <utility>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	using PtrToItem = Item*;

	class CustomerOrder
	{
		static size_t m_widthField;
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		PtrToItem* m_lstItem = nullptr;
		void resize(Item* item);
		void deallocate();
	public:
		CustomerOrder();
		CustomerOrder(const std::string str);
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif