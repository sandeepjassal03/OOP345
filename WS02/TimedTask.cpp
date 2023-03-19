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

#include "TimedTask.h"

namespace sdds
{
	// Default Constructor: sets m_totalRecords to 0
	TimedTask::TimedTask()
	{
		m_totalRecords = 0;
	}
	
	// Sets m_startTime to the current time
	void TimedTask::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
	}

	// Sets m_endTime to the current time
	void TimedTask::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* task)
	{
		// Creates a temporary string and initialises it using task parameter
		std::string temp(task);

		// Sets taskName to the one stored in temp
		Task[m_totalRecords].m_taskName = temp;

		// Modify temp to store nanoseconds and store it in timeUnit
		temp = "nanoseconds";
		Task[m_totalRecords].m_timeUnit = temp;

		// Calculate the duration of execution by finding the difference between end time and start time
		Task[m_totalRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);

		// Increment m_totalRecords by 1
		++m_totalRecords;
	}

	std::ostream& operator<<(std::ostream& ostr, TimedTask& obj)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Execution Times:" << std::endl;
		ostr << "--------------------------" << std::endl;

		// Loop until m_totalRecords to display execution time for each task
		for (int i = 0; i < obj.m_totalRecords; ++i)
		{
			ostr.width(21);
			ostr.setf(std::ios::left);
			ostr << obj.Task[i].m_taskName;
			ostr.unsetf(std::ios::left);
			ostr.width(13);
			ostr.setf(std::ios::right);
			ostr << obj.Task[i].m_duration.count() << obj.Task[i].m_timeUnit << std::endl;
			ostr.unsetf(std::ios::right);
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}
}