/*
*****************************************************************************
							Workshop-2

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 25/01/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <chrono>

namespace sdds
{
	
	class TimedTask
	{
		// MEMBER VARIABLES
		int m_totalRecords = 0;
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		struct {
			std::string m_taskName{};
			std::string m_timeUnit{};
			std::chrono::steady_clock::duration m_duration{};
		} Task[10]{}; // Array of structures

	public:

		// *** Default Constructor
		TimedTask();

		// MEMBER FUNCTIONS
		void startClock();
		void stopClock();
		void addTask(const char* task);

		// Friend insertion operator
		friend std::ostream& operator<<(std::ostream& ostr, TimedTask& obj);
	};
}

#endif