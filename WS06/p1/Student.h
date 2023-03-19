#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

namespace sdds
{
	class Student : public Person
	{
		std::string m_name{};
		unsigned int m_age{};
		std::string m_id{};
		std::vector<std::string> m_courses{};
		unsigned int m_count{};
	public:
		Student(std::istream& istr);
		Student(Student& src) = delete;
		Student& operator=(Student& src) = delete;
		std::string status() const;
		std::string name() const;
		void display(std::ostream& out) const;
	};
}

#endif
