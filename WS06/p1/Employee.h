#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

namespace sdds
{
	class Employee : public Person
	{
		std::string m_name{};
		unsigned int m_age{};
		std::string m_id{};
	public:
		Employee();
		Employee(std::istream& istr);
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream& out) const;
	};
}

#endif