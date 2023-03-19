#include "Professor.h"

namespace sdds
{
	Professor::Professor(std::istream& in):Employee(in)
	{
		std::string temp{};
		std::getline(in, temp, '\n');
		auto first = temp.find_first_not_of(' ');
		auto last = temp.find_last_not_of(' ');
		m_department = temp.substr(first, (last - first) + 1);
	}
	void Professor::display(std::ostream& out) const
	{
		Employee::display(out);
		out << "|" << m_department << "| Professor";
	}
	std::string Professor::status() const
	{
		return "Professor";
	}
	std::string Professor::department() const
	{
		return m_department;
	}
}