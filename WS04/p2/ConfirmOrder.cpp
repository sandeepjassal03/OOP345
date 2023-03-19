/*
*****************************************************************************
							Workshop-4

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 11/02/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "ConfirmOrder.h"

namespace sdds
{
	ConfirmOrder::ConfirmOrder()
	{
		m_toyList = {};
		m_size = {};
	}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& src)
	{
		*this = src;
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src)
	{
		if (this != &src)
		{
			// Cleanup
			delete[] m_toyList;

			// Shallow copy
			m_size = src.m_size;
			// Allocates new memory for m_toyList based on the src object and copies contents.
			m_toyList = new PtrToToy[m_size];
			for (auto i = 0u; i < m_size; ++i)
			{
				m_toyList[i] = src.m_toyList[i];
			}
		}

		// Returns the reference of the current object
		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& src)
	{
		*this = std::move(src);
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src)
	{
		if (this != &src)
		{
			// Removes existing DMA if any
			delete[] m_toyList;

			// Shallow copying
			m_size = src.m_size;
			m_toyList = src.m_toyList;

			// Setting members of src to empty state
			src.m_size = 0;
			src.m_toyList = nullptr;

		}
		return *this;
	}

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] m_toyList;
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool found = false;

		// Iterating through the array to find out if the toy exists in the array or not
		for (auto i = 0u; i < m_size; i++)
		{
			if (m_toyList[i] == &toy)
			{
				found = true;
			}
		}

		// If yes, do these steps to re-size the array for the new object
		if (!found)
		{
			/*** 1. Allocate new temporary array with size = size + 1 ***/
			PtrToToy* temp = new PtrToToy[m_size + 1];

			/*** 2. Copy all the existing data into the temp array ***/
			for (auto i = 0u; i < m_size; ++i)
			{
				temp[i] = m_toyList[i];
			}

			/*** 3. Add the address of the toy in the parameter to the temporary array ***/
			temp[m_size] = &toy;

			
			/*** 4. Deletes the existing DMA at m_toyList ***/
			if (m_toyList)
			{
				delete[] m_toyList;
			}

			/*** 5.Set the m_toyList to point to the temporary array
			 Set temp to nullptr ***/
			m_toyList = temp;
			temp = nullptr;

			/*** 6. Increment m_size by 1 ***/
			++m_size;
		}

		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool found = false;
		size_t index{};

		// Iterating through the array to find out if the toy exists in the array or not
		for (auto i = 0u; i < m_size && !found; i++)
		{
			if (m_toyList[i] == &toy)
			{
				found = true;
				index = i;
			}
		}

		// If yes, do these steps to re-size the array for the new object
		if (found)
		{
			/*** 1. Delete the existing DMA at m_toylList[index] ***/
			m_toyList[index] = nullptr;

			/*** 2. Create a temp array with size = size - 1 ***/
			PtrToToy* temp = new PtrToToy[m_size - 1];

			/*** 3. Iterate through the array such that we skip the null element ***/
			index = 0;
			for (auto i = 0u; i < m_size; ++i)
			{
				if (m_toyList[i] != nullptr)
				{
					temp[index] = m_toyList[i];
					index++;
				}

			}

			/*** 4. Delete the existing DMA pointed by m_toyList ***/
			if (m_toyList)
			{
				delete[] m_toyList;
			}

			/*** 5. Decrement m_size by 1***/
			--m_size;

			/*** 6. Set the m_toyList to point to the temporary array
			 Set temp to nullptr***/
			m_toyList = temp;
			temp = nullptr;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& src)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (!src.m_size)
		{
			ostr << "There are no confirmations to send!" << std::endl;
		}
		else
		{
			for (auto i = 0u; i < src.m_size; ++i)
				src.m_toyList[i]->display();
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}
}