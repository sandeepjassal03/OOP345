#include "Child.h"

namespace sdds
{
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		m_name = name;
		m_age = age;
		m_toyList = toys;
	}
	Child::Child(const Child& src)
	{
		*this = src;
	}

	void Child::deallocate()
	{
		for (auto i = 0u; i < m_size; ++i)
		{
			delete m_toyList[i];
		}
		delete[] m_toyList;
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

				// Allocates new memory for m_description based on the src object and copies contents.
				m_toyList = new PtrToToy[m_size];
				for (auto i = 0u; i < m_size; ++i)
				{
					m_toyList[i] = src.m_toyList[i];
				}
		}

		// Returns the reference of the current object
		return *this;
	}
	Child::Child(const Child&& src)
	{
		*this = std::move(src);
	}
	Child& Child::operator=(const Child&& src)
	{
		if (this != &src)
		{
			// Removes existing DMA if any
			deallocate();

			// Shallow copying non-resource variables
			m_name = src.m_name;
			m_age = src.m_age;
			m_size = src.m_size;
			m_toyList = src.m_toyList;
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

	std::ostream& operator<<(std::ostream& ostr, const Child& src)
	{
		if (!src.size())
		{
			ostr << "This child has no toys!";
		}
		else
		{
			for (auto i = 0u; i < src.size(); ++i)
				src.m_toyList[i]->display();
		}
		return ostr;
	}
}