#include "Database.h"

namespace sdds
{
	std::shared_ptr<Database> Database::m_address = nullptr;


	Database::Database(const std::string& filename)
	{
		std::cout << "[" << this << "] Database(const std::string&)";
		std::ifstream file(filename);
		m_filename = filename;
		m_numEntries = 0;
		std::string key;
		std::string value;
		for (auto i = 0u; file; ++i)
		{
			file >> key >> value;
			file.ignore(100, '\n');
			std::replace(key.begin(), key.end(), '_', ' ');
			m_keys[i] = key;
			m_values[i] = value;
			++m_numEntries;
		}

	}
	std::shared_ptr<Database> Database::getInstance(const std::string& filename)
	{
		if (!m_address)
		{
			m_address = std::shared_ptr<Database>(new Database(filename));
		}
		return m_address;
	}
	Err_Status Database::GetValue(const std::string& key, std::string& value) const
	{
		bool found = false;
		Err_Status returnVal{};
		for (auto i = 0u; i < m_numEntries; ++i)
		{
			if (m_keys[i] == key)
			{
				value = m_values[i];
				found = true;
			}
		}
		if (found)
		{
			returnVal = Err_Status::Err_Success;
		}
		else
		{
			returnVal = Err_Status::Err_NotFound;
		}
		return returnVal;
	}
	Err_Status Database::SetValue(const std::string& key, const std::string& value)
	{
		if (m_numEntries != 20)
		{
			m_keys[m_numEntries] = key;
			m_values[m_numEntries] = value;
			++m_numEntries;
		}
		return Err_Status::Err_Success;
	}
	Database::~Database()
	{
		std::cout << "[" << this << "] ~Database()";
		std::string filename = m_filename + ".bkp.txt";
		std::ofstream file(filename);
		for (auto i = 0u;i <  m_numEntries; ++i)
		{
			file.width(25);
			file <<std::left<< m_keys[i];
			file << " -> " << m_values[i] << std::endl;
		}
	}
}