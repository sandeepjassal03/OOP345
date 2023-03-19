/*
*****************************************************************************
							Workshop-5

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 15/02/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string m_name{};
		T* m_collection = nullptr;
		size_t m_size{};
		void(*m_observer)(const Collection<T>&, const T&){};
	public:
		Collection(const std::string& name)
		{
			m_name = name;
			m_collection = nullptr;
			m_size = {};
		}
		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;

		Collection(const Collection&& src) = delete;
		Collection& operator=(const Collection&& src) = delete;

		~Collection()
		{
			delete[] m_collection;
		}
		const std::string& name() const
		{
			return m_name;
		}
		size_t size() const
		{
			return m_size;
		}
		void setObserver(void(*observer)(const Collection<T>&, const T&))
		{
			m_observer = observer;
		}
		Collection<T>& operator+=(const T& item)
		{
			bool found = false;
			for (auto i=0u;i<m_size;++i)
			{
				if (m_collection[i].title() == item.title())
				{
					found = true;
				}
			}
			
			if (!found)
			{
				T* temp{};
				temp = new T[m_size + 1];
				for (auto i = 0u; i < m_size; ++i)
				{
					temp[i] = m_collection[i];
				}
				temp[m_size] = item;
				if(m_collection)
					delete[] m_collection;

				m_size++;
				m_collection = temp;
				
				if (m_observer)
				{
					m_observer(*this, item);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const
		{
			if (idx >= m_size)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			else
			{
				return m_collection[idx];
			}
		}
		T* operator[](const std::string& title) const
		{
			T* address = nullptr;
			for (auto i = 0u; i < m_size; ++i)
			{
				if (m_collection[i].title() == title)
				{
					address = &m_collection[i];
				}
			}
			return address;
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& ostr, Collection<T>& src)
	{
		for (auto i = 0u; i < src.size(); ++i)
		{
			ostr << src[i];
		}
		return ostr;
	}
}

#endif
