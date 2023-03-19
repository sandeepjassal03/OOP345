#include "Bakery.h"

namespace sdds
{
	std::string Bakery::extractField(std::string& copy, int size)
	{
		std::string temp{};
		temp = copy.substr(0, size);

		auto last = temp.find_last_not_of(' ');
		temp = temp.substr(0, last + 1);

		copy.erase(0, size);
		return temp;
	}
	Bakery::Bakery()
	{
		m_items = {};
		m_count = 0;
	}
	Bakery::Bakery(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "ERROR: Cannot open file";
		}
		while (file)
		{

			std::string data{};
			std::string temp{};
			std::getline(file, data, '\n');
			if (file)
			{
				BakedGood* item = new BakedGood;
				temp = extractField(data, 8);
				if (temp == "Bread")
				{
					item->m_bakeType = BakedType::BREAD;
				}
				else
				{
					item->m_bakeType = BakedType::PASTERY;
				}
				item->m_description = extractField(data, 20);
				item->m_shelfLife = stoi(extractField(data, 14));
				item->m_quantity = stoi(extractField(data, 8));
				item->m_price = stod(extractField(data, 6));
				m_items.push_back(item);
			}
		}
	}
	void Bakery::showGoods(std::ostream& os) const
	{
		std::for_each(m_items.begin(), m_items.end(), [&os](const BakedGood* src) {os << *src; });
	}
	Bakery::~Bakery()
	{
		for (auto it = m_items.begin(); it != m_items.end(); ++it)
		{
			delete *it;
		}
	}
	std::ostream& operator<<(std::ostream& out, const BakedGood& b)
	{
		out << "* ";
		out.width(10);
		if (b.m_bakeType == BakedType::BREAD)
			out << std::left << "Bread";
		else
			out << std::left << "Pastry";

		out << " * ";
		out.width(20);
		out << std::left << b.m_description;

		out << " * ";
		out.width(5);
		out << std::left << b.m_shelfLife;

		out << " * ";
		out.width(5);
		out << std::left << b.m_quantity;

		out << " * ";
		out.width(8);
		out.precision(2);
		out << std::right <<std::fixed << b.m_price;

		out << " * ";

		out << std::endl;

		return out;
	}
}