#include "Student.h"

namespace sdds
{
	Student::Student(std::istream& istr)
	{
		std::string temp{};
		istr.ignore(10, ',');

		std::getline(istr, temp, ',');
		auto first = temp.find_first_not_of(' ');
		auto last = temp.find_last_not_of(' ');
		m_name = temp.substr(first, (last - first) + 1);

		std::getline(istr, temp, ',');
		if (temp[0] < '0' || temp[0] > '9')
			throw (m_name + "++Invalid record!");
		m_age = stoi(temp);
		istr.ignore();


		std::getline(istr, temp, ',');
		if (temp[0] == 'E')
		{
			m_id = temp;
		}
		else
		{
			throw (m_name + "++Invalid record!");
		}
	}
	std::string Student::status() const
	{
		return "Student";
	}
	std::string Student::name() const
	{
		return m_name;
	}
	void Student::display(std::ostream& out) const
	{

	}
}