#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>
#include <string>

namespace sdds
{
	class Toy
	{
		unsigned int m_orderID{};
		std::string m_name{};
		int m_quantity{};
		double m_price{};
		const double HST{ 0.13 };
	public:

		/*******************************
				 CONSTRUCTORS
		*******************************/
		Toy();
		Toy(const std::string& toy);

		/*******************************
			PUBLIC MEMBER FUNCTIONS
		*******************************/
		void update(int numItems);
		std::ostream& display(std::ostream& ostr=std::cout) const;
		friend std::ostream& operator<<(std::ostream& ostr, const Toy& src);
	};

}

#endif