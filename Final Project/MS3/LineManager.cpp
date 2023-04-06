#include "LineManager.h"

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream openFile(file);
		if (openFile)
		{
			std::vector<Workstation*> temp;
			std::string str, station1, station2;
			Workstation* st1Add{};
			Workstation* st2Add{};
			Utilities util;

			while (openFile)
			{
				std::getline(openFile, str, '\n');
				bool more = true;
				size_t pos = 0u;
				if (openFile)
				{
					station1 = util.extractToken(str, pos, more);
					std::for_each(stations.begin(), stations.end(), [&st1Add, station1](Workstation* station) {
						if (station->getItemName() == station1)
						{
							st1Add = station;
						}
						});
					if (more)
					{
						station2 = util.extractToken(str, pos, more);
						std::for_each(stations.begin(), stations.end(), [&st2Add, station2](Workstation* station) {
							if (station->getItemName() == station2)
							{
								st2Add = station;
							}
							});
						temp.push_back(st2Add);
						st1Add->setNextStation(st2Add);
					}
					else
					{
						st1Add->setNextStation(nullptr);
					}
					m_activeLine.push_back(st1Add);
				}
			}
			auto it = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&temp](const auto& elem) {
				return std::find(temp.begin(), temp.end(), elem) == temp.end();
				});
			if (it != m_activeLine.end()) {
				m_firstStation = *it;
			}

			m_cntCustomerOrder = g_pending.size();
		}
	}
	void LineManager::reorderStations()
	{
		m_activeLine.clear();
		m_activeLine.push_back(m_firstStation);
		for (auto i = 0u; i < m_activeLine.size(); ++i)
		{
			if (m_activeLine[i]->getNextStation())
				m_activeLine.push_back(m_activeLine[i]->getNextStation());
		}
	}
	bool LineManager::run(std::ostream& os)
	{
		bool returnVal = false;
		static size_t iteration = 1;
		os << "Line Manager Iteration: " << iteration << std::endl;

		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}

		for (auto* station : m_activeLine) {
			station->fill(os);
		}

		for (auto* station : m_activeLine) {
			station->attemptToMoveOrder();
		}
		if (g_pending.empty() == true)
		{
			if(g_completed.size() + g_incomplete.size() == m_cntCustomerOrder)
				returnVal = true;
		}
		++iteration;
		return returnVal;
	}
	void LineManager::display(std::ostream& os) const
	{
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](const Workstation* station) {
			station->display(os);
			});
	}
}