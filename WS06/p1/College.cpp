#include "College.h"

namespace sdds
{
	College::College()
	{
		m_persons = {};
	}
	College& College::operator +=(Person* thePerson)
	{
		m_persons.push_back(thePerson);
		return *this;
	}
	void College::display(std::ostream& out) const
	{
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		out << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;		
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			(*it)->display(out);
			out << std::endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		out << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			out.setf(std::ios::left);
			out << "| ";
			out.width(10);
			out << (*it)->status();
			out << "| ";
			out.width(10);
			out << (*it)->id();
			out << "| ";
			out.width(20);
			out << (*it)->name();
			out << " | ";
			out.width(3);
			out << (*it)->age();
			out << " |";
			out.unsetf(std::ios::left);
			out << std::endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}

	College:: ~College()
	{
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			delete *it;
		}
	}
}