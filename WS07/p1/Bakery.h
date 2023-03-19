#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
		size_t m_quantity{};
		double m_price{};
	};

	class Bakery
	{
		std::vector<BakedGood*> m_items{};
		size_t m_count{};
		std::string extractField(std::string& copy, int size);
	public:
		Bakery();
		Bakery(const char* filename);
		void showGoods(std::ostream& os) const;
		~Bakery();
	};
	std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif