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
#include "Child.h"

namespace sdds
{
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		m_name = name;
		m_age = age;
		m_size = count;

		m_toyList = new PtrToToy[m_size];
		
		for (auto i = 0u; i < m_size; ++i)
		{
			m_toyList[i] = new Toy(*toys[i]);
		}
	}
	Child::Child(const Child& src)
	{
		*this = src;
	}

	Child& Child::operator=(const Child& src)
	{
		if (this != &src)
		{
			// Removes existing DMA if any
			deallocate();

			// Shallow copying non-resource variables
			m_name = src.m_name;
			m_age = src.m_age;
			m_size = src.m_size;

			if (src.m_toyList)
			{
				// Allocates new memory for m_toyList based on the src object and makes copies of the toy object.
				m_toyList = new PtrToToy[m_size];
				for (auto i = 0u; i < m_size; ++i)
				{
					m_toyList[i] = new Toy(*src.m_toyList[i]);
				}
			}
		}

		// Returns the reference of the current object
		return *this;
	}
	Child::Child(Child&& src)
	{
		*this = std::move(src);
	}
	Child& Child::operator=(Child&& src)
	{
		if (this != &src)
		{
			// Removes existing DMA if any
			deallocate();

			// Shallow copying all member variables
			m_name = src.m_name;
			m_age = src.m_age;
			m_size = src.m_size;
			m_toyList = src.m_toyList;

			// Setting the src object to a safe empty state
			src.m_name = {};
			src.m_toyList = nullptr;
			src.m_size = 0;
			src.m_age = 0;

		}
		// Returns the reference of the current object
		return *this;
	}


	size_t Child::size() const
	{
		return m_size;
	}
	Child::~Child()
	{
		deallocate();
	}

	void Child::deallocate()
	{
		if (m_toyList)
		{
			for (auto i = 0u; i < m_size; ++i)
			{
				delete m_toyList[i];
			}
			delete[] m_toyList;
		}
	}

	std::ostream& operator<<(std::ostream& ostr, const Child& src)
	{
		static int counter = 1;
		ostr << "--------------------------" << std::endl;
		ostr << "Child " << counter << ": " << src.m_name << " " << src.m_age << " years old:" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (!src.size())
		{
			ostr << "This child has no toys!" << std::endl;
		}
		else
		{
			for (auto i = 0u; i < src.size(); ++i)
				src.m_toyList[i]->display();
		}
		ostr << "--------------------------" << std::endl;
		++counter;
		return ostr;
	}
}