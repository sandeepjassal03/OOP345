/*
*****************************************************************************
							Workshop-7

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 14/03/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

namespace sdds
{
	enum class BakedType 
	{
		BREAD, PASTERY
	};

	struct BakedGood
	{
		BakedType m_bakeType{};
		std::string m_description{};
		size_t m_shelfLife{};
		int m_quantity{};
		double m_price{};
	};

	class Bakery
	{
		std::vector<BakedGood> m_items{};
		size_t m_count{};
		std::string extractField(std::string& copy, int size);
	public:
		Bakery();
		Bakery(const char* filename);
		void showGoods(std::ostream& os) const;
		void sortBakery(std::string sorter);
		bool inStock(std::string description, BakedType type) const;
		std::list<BakedGood> outOfStock(BakedType type) const;
		std::vector<BakedGood> combine(Bakery& src);
	};
	std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif