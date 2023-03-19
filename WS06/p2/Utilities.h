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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Professor.h"
#include "Student.h"
#include <sstream>

namespace sdds
{
	Person* buildInstance(std::istream& in);
}
#endif