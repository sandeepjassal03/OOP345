/*
*****************************************************************************
							Workshop-6

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 08/03/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
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
		std::string* m_courses{};
		unsigned int m_count{};

		void removeSpaces(std::string& copy);
	public:
		Student(std::istream& istr);
		Student(Student& src) = delete;
		Student& operator=(Student& src) = delete;
		~Student();
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream& out) const;
	};
}

#endif
