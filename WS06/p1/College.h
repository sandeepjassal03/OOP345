#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

namespace sdds
{
	class College
	{
		std::vector<Person*> m_persons{};
	public:
		College();
		College(College& src) = delete;
		College& operator=(College& src) = delete;
		College& operator +=(Person* thePerson);
		void display(std::ostream& out) const;
		~College();
	};
}

#endif