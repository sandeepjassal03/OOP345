/*
*****************************************************************************
							Workshop-8

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 23/03/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include<iostream>
#include <iomanip>
#include <string>
#include <cstring>
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

	template <typename T>
	class Database
	{
		static std::shared_ptr<Database> m_address;
		size_t m_numEntries{};
		std::string m_keys[20];
		T m_values[20];
		std::string m_filename;

		// Private Constructor
		Database(const std::string& filename);
		void encryptDecrypt(T& value) {}
	public:
		// CLass Function to get the shared_ptr of the instance of Database class
		static std::shared_ptr<Database> getInstance(const std::string filename);

		// Gets the value corresponding to the key passed
		Err_Status GetValue(const std::string& key, T& value) const;

		// Sets the value corresponding to the key passed
		Err_Status SetValue(const std::string& key, const T& value);
		~Database();
	};

	// Initialising the class variable
	template<typename T>
	std::shared_ptr<Database<T>> Database<T>::m_address = nullptr;


	template<typename T>
	Database<T>::Database(const std::string& filename)
	{
		// Prints to the screen the address of the current instance and the prototype of the Constructor
		std::cout << "[" << this << "] Database(const std::string&)" << std::endl;

		// Creates an instance of ifstream using filename
		std::ifstream file(filename);

		m_filename = filename;
		m_numEntries = 0;
		// Temporary variables to store data from the file
		std::string key{};
		T value{};

		for (auto i = 0u; file; ++i)
		{
			// Reads a pair of key and value from the file and ignores the newline character
			file >> key >> value;

			if (file)
			{
				// encryptDecrypt: Since the data in the file was encrypted, this function decrypts the value
				encryptDecrypt(value);

				// std::replace: Replaces the _ in the key with ' ' (empty space) character
				std::replace(key.begin(), key.end(), '_', ' ');

				// Stores the key and value in the parallel arrays
				m_keys[i] = key;
				m_values[i] = value;

				// Increments m_numEntries by 1
				++m_numEntries;
			}
		}
	}

	template <typename T>
	std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string filename)
	{
		// If the m_addresss is a nullptr, creates a new resource and returns its address stored in the class variable
		if (!m_address)
		{
			m_address = std::shared_ptr<Database<T>>(new Database<T>(filename));
		}
		return m_address;
	}

	template <typename T>
	Err_Status Database<T>::GetValue(const std::string& key, T& value) const
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

	template <typename T>
	Err_Status Database<T>::SetValue(const std::string& key, const T& value)
	{
		if (m_numEntries != 20)
		{
			m_keys[m_numEntries] = key;
			m_values[m_numEntries] = value;
			++m_numEntries;
		}
		return Err_Status::Err_Success;
	}

	template <typename T>
	Database<T>::~Database()
	{
		std::cout << "[" << this << "] ~Database()" << std::endl;
		std::string filename = m_filename + ".bkp.txt";
		std::ofstream file(filename);
		for (auto i = 0u; i < m_numEntries; ++i)
		{
			file.width(25);
			file << std::left << m_keys[i];
			encryptDecrypt(m_values[i]);
			file << " -> " << m_values[i] << std::endl;
		}
	}

	template<>
	void Database<std::string>::encryptDecrypt(std::string& value)
	{
		const char secret[]{ "secret encryption key" };

		for (char& c : value)
		{
			for (char k : secret)
				c = c ^ k;
		}
	}

	template<>
	void Database<long long>::encryptDecrypt(long long& value)
	{
		const char secret[]{ "super secret encryption key" };
		char* bytes = reinterpret_cast<char*>(&value);

		for (auto B = 0u; B < sizeof(value); ++B) {
			for (auto K = 0u; K < strlen(secret); ++K) {
				bytes[B] = bytes[B] ^ secret[K];
			}
		}
	}
}

#endif
