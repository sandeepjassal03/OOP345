#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include<iostream>
#include <string>
#include<fstream>
#include <algorithm>
#include <memory>

namespace sdds
{
	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	class Database
	{
		static std::shared_ptr<Database> m_address;
		size_t m_numEntries{};
		std::string m_keys[20];
		std::string m_values[20];
		std::string m_filename;
		Database(const std::string& filename);
	public:
		static std::shared_ptr<Database> getInstance(const std::string& filename);
		Err_Status GetValue(const std::string& key, std::string& value) const;
		Err_Status SetValue(const std::string& key, const std::string& value);
		~Database();
	};

}

#endif
