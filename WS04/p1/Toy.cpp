#include "Toy.h"

namespace sdds
{
	/*******************************
			 CONSTRUCTORS
	*******************************/
	Toy::Toy()
	{
		m_orderID = 0;
		m_name = {};
		m_quantity = 0;
		m_price = 0;
	}
	Toy::Toy(const std::string& toy)
	{
		std::string temp{};
		std::string number{};
		temp = toy;

		m_orderID = std::stoi(temp);

		auto start = temp.find(':');
		auto end = temp.find(':', start + 1);

		m_name = temp.substr(start + 1, end - start - 1);

		auto first = m_name.find_first_not_of(' ');
		auto last = m_name.find_last_not_of(' ');

		m_name = m_name.substr(first, (last - first) + 1);

		//while(!m_name.find(' '))
		//	m_name.erase(std::find(m_name.begin(), m_name.end(), ' '));
		////m_name.erase(m_name.find(' '));

		//while (m_name.find_last_of(' '))
		//	m_name.erase(std::find(m_name.end(), m_name.begin(), ' '));

		start = end;
		end = temp.find(':', start + 1);
		number = temp.substr(start + 1, end - start - 1);
		m_quantity = std::stoi(number);

		start = end;
		number = temp.substr(start + 1);
		m_price = std::stod(number);
	}

	/*******************************
		PUBLIC MEMBER FUNCTIONS
	*******************************/
	void Toy::update(int numItems)
	{
		m_quantity = numItems;
	}
	std::ostream& Toy::display(std::ostream& ostr) const
	{
		auto subtotal = m_quantity * m_price;
		auto tax = m_quantity * m_price * HST;

		ostr << "Toy";
		ostr.width(8);
		ostr << m_orderID << ":";

		ostr.width(18);
		ostr.setf(std::ios::right);
		ostr << m_name;
		ostr.unsetf(std::ios::right);

		ostr.width(3);
		ostr << m_quantity << " items";

		ostr.width(8);
		ostr << m_price << "/item  subtotal:";

		ostr.width(7);
		ostr << subtotal << " tax:";

		ostr.width(6);
		ostr.precision(2);
		ostr << std::fixed << tax << " total:";

		ostr.width(7);
		ostr.precision(2);
		ostr <<std::fixed << subtotal + tax << std::endl;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Toy& src)
	{
		src.display();
		return ostr;
	}
}

/*
* stoi(number);
int s = temp.find(':')
temp.erase(0,s+1);

int s = temp.find(':');
string te = temp.substr(0,s);

temp.erase(0,s+1);

*/