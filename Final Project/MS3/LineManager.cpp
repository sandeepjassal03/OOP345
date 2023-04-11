/*
*****************************************************************************
							Milestone-3

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 30/03/2023

Authenticity Declaration:
I confirm that I am the only author of this file
and the content was created entirely by me.
*****************************************************************************
*/
#include "LineManager.h"

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream openFile(file);
		if (openFile)
		{
			// Temporary variables
			std::vector<Workstation*> temp;
			std::string str, station1, station2;
			Workstation* st1Address{};
			Workstation* st2Address{};
			Utilities util;

			while (openFile)
			{
				// Get one line from the file
				std::getline(openFile, str, '\n');
				bool more = true;
				size_t pos = 0u;

				// If the file stream is still in valid state:
				if (openFile)
				{
					// extract a token into station1
					station1 = util.extractToken(str, pos, more);
					// Search for the station that has the same name as the string station1 and store its address in st1Address
					std::for_each(stations.begin(), stations.end(), [&st1Address, station1](Workstation* station) {
						if (station->getItemName() == station1)
						{
							st1Address = station;
						}
						});
					// If more is still true (i.e., the station1 does not represent the last station)
					if (more)
					{
						// extract a token into station2
						station2 = util.extractToken(str, pos, more);
						// Search for the station that has the same name as the string station2 and store its address in st2Address
						std::for_each(stations.begin(), stations.end(), [&st2Address, station2](Workstation* station) {
							if (station->getItemName() == station2)
							{
								st2Address = station;
							}
							});

						// Add the second station to the temp vector and also set the next station for first station equal to the second one
						temp.push_back(st2Address);
						st1Address->setNextStation(st2Address);
					}
					else
					{
						// This means station 1 was the last station on the line
						st1Address->setNextStation(nullptr);
					}
					m_activeLine.push_back(st1Address);
				}
			}

			// This finds the first station from the m_activeLine using the temp vector
			// The temp vector contains all stations except the one station that is the first station
			// So, if the std::find returns true for an instance of m_activeLine, it indicates that the current element does not exist in temp and is the desired first station.
			// The std::find_if returns the iterator to that element for which the lambda was true.
			auto it = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&temp](const auto& elem) {
				return std::find(temp.begin(), temp.end(), elem) == temp.end();
				});

			// If the station was found, set it to m_firstStation
			if (it != m_activeLine.end()) {
				m_firstStation = *it;
			}

			m_cntCustomerOrder = g_pending.size();
		}
	}
	void LineManager::reorderStations()
	{
		// Clear the m_activeLine vector (but keep its size)
		m_activeLine.clear();
		// Push the address of the m_firstStation into m_activeLine
		m_activeLine.push_back(m_firstStation);

		for (auto i = 0u; i < m_activeLine.size(); ++i)
		{
			if (m_activeLine[i]->getNextStation())
				m_activeLine.push_back(m_activeLine[i]->getNextStation());
		}
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t iteration = 1;
		os << "Line Manager Iteration: " << iteration << std::endl;

		// Move the first order in the g_pending to m_firstStation's orders
		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		// For every station on the m_activeLine, attempt a fill operation
		for (auto* station : m_activeLine) {
			station->fill(os);
		}

		// For every station on the m_activeLine, attempt a move order operation
		for (auto* station : m_activeLine) {
			station->attemptToMoveOrder();
		}
		++iteration;
		return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
	}
	void LineManager::display(std::ostream& os) const
	{
		// For each station in m_activeLine, display its contents using Station::display()
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](const Workstation* station) {
			station->display(os);
			});
	}
}