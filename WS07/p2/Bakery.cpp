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
#include "Bakery.h"

namespace sdds
{
	std::string Bakery::extractField(std::string& copy, int size)
	{
		std::string temp{};

		// Copy the string with the particular size into temp
		temp = copy.substr(0, size);

		// Get rid of any trailing spaces
		auto last = temp.find_last_not_of(' ');
		temp = temp.substr(0, last + 1);

		// Erase the part extracted from the main string using erase() function
		copy.erase(0, size);

		// Return the temp string
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

		// If file does not open, throw an Error
		if (!file)
		{
			throw "ERROR: Cannot open file";
		}
		std::string data{};
		std::string temp{};

		// Iterate through the file till the file ends
		while (file)
		{
			// Get a line from file and store it in data for further extraction
			std::getline(file, data, '\n');

			// If the file stream is valid: 
			if (file)
			{
				// Create a temporary instance of Baked Good
				BakedGood item{};

				// Extract the Bake Type from the file which has a field size of 8
				temp = extractField(data, 8);

				// IF the bakedType is a Bread, set its enum value to Bread, Pastry otherwise
				if (temp == "Bread")
				{
					item.m_bakeType = BakedType::BREAD;
				}
				else
				{
					item.m_bakeType = BakedType::PASTERY;
				}

				// Extract the description from the file which has a field size of 20
				item.m_description = extractField(data, 20);

				// Extract the shelfLife from the file which has a field size of 14, using stoi to get the integral value
				item.m_shelfLife = stoi(extractField(data, 14));

				// Extract the stock from the file which has a field size of 8, using stoi to get the integral value
				item.m_quantity = stoi(extractField(data, 8));

				// Extract the price from the file which has a field size of 6, using stod to get the floating point value (double precision)
				item.m_price = stod(extractField(data, 6));

				// Push the item into the m_items vector
				m_items.push_back(item);
			}
		}
	}

	void Bakery::showGoods(std::ostream& os) const
	{
		// std::accumulate(): Uses an init value (to specify the type of the variable data is stored and from what value to start with) and stores the accumulated value in the param of the lambda, ultimately returned by the algorithm
		auto totalStock = std::accumulate(m_items.begin(), m_items.end(), 0,[](auto total, const BakedGood& obj) { return total + obj.m_quantity;});
		auto totalPrice = std::accumulate(m_items.begin(), m_items.end(), 0.0,[](auto total, const BakedGood& obj) { return total + obj.m_price;});

		// std::for_each(): Takes 2 iterators pointing to the beginning and end (1 element after) of the collection and performs the lambda for all the elements.
		std::for_each(m_items.begin(), m_items.end(), [&os](const BakedGood& src) {os << src << std::endl; });
		os << "Total Stock: " << totalStock << std::endl;
		os << "Total Price: " << totalPrice << std::endl;
	}

	void Bakery::sortBakery(std::string sorter)
	{
		//std::sort(): Sorts the collection based on the condition passed into the algorithm using the lambda expression
		if (sorter == "Description")
		{
			std::sort(m_items.begin(), m_items.end(), [](const BakedGood a, const BakedGood b) {return a.m_description < b.m_description; });
		}
		else if (sorter == "Shelf")
		{
			std::sort(m_items.begin(), m_items.end(), [](const BakedGood a, const BakedGood b) {return a.m_shelfLife < b.m_shelfLife; });
		}
		else if (sorter == "Stock")
		{
			std::sort(m_items.begin(), m_items.end(), [](const BakedGood a, const BakedGood b) {return a.m_quantity < b.m_quantity; });
		}
		else if (sorter == "Price")
		{
			std::sort(m_items.begin(), m_items.end(), [](const BakedGood a, const BakedGood b) {return a.m_price < b.m_price; });
		}
	}

	std::vector<BakedGood> Bakery::combine(Bakery& src)
	{
		// To combine bakeries, we need to sort them before combining, hence using the member function sortBakery
		sortBakery("Price");
		src.sortBakery("Price");

		// Declare a vector with the size totalling to the size of the current object collection and the collection in the parameter object
		std::vector<BakedGood> temp(m_items.size() + src.m_items.size());

		// std::merrge(): Merges two collections, adding them to a new container, sorting them based on the condition passed into the algorithm using the lambda expression
		std::merge(m_items.begin(), m_items.end(), src.m_items.begin(), src.m_items.end() ,temp.begin(), [](const BakedGood a, const BakedGood b) { return a.m_price < b.m_price; });

		// return the combined vector
		return temp;
	}

	bool Bakery::inStock(std::string description, BakedType type) const
	{
		//std::any_of(): Returns a boolean if any element in the collection fulfills the condition in the lambda, here checks if the element that matches the description and bakedType has stock level more than 0.
		return std::any_of(m_items.begin(), m_items.end(), [description, type](const BakedGood& src) {
			return src.m_bakeType == type && src.m_description == description && src.m_quantity > 0;
			});
	}

	std::list<BakedGood> Bakery::outOfStock(BakedType type) const
	{
		auto check = [type](BakedGood src) {
			return type == src.m_bakeType && src.m_quantity == 0;
		};
		// std::count_if(): returns the number of elements in the collection that satisfy the condition of the lambda expression.
		auto size = std::count_if(m_items.begin(), m_items.end(), check);

		// Create a temporary list, giving it the size returned by std::count_if
		std::list<BakedGood> temp(size);

		// std::copy_if(): Copies the elements from m_items into temp that satisfy the condition of the lambda expression
		std::copy_if(m_items.begin(), m_items.end(), temp.begin(), check);
		return temp;
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
		return out;
	}
}