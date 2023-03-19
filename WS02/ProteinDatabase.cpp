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

#include "ProteinDatabase.h"

namespace sdds
{
	/*************************************
			*** CONSTRUCTORS ***
	**************************************/
	ProteinDatabase::ProteinDatabase()
	{
		// Sets the member variables to a safe empty state
		m_size = 0;
		m_database = nullptr;
	}

	// 1-arg constructor makes an inline call for default constructor to initialise the member variables
	ProteinDatabase::ProteinDatabase(const char* m_filename) :ProteinDatabase()
	{
		// Created an instance of ifstream with m_filename to open the file for read
		std::ifstream fstr(m_filename);

		// Checks if the file opened successfully
		if (fstr.is_open())
		{
			// If yes, create a temporary string and read the file one line at a time to count the total sequences
			std::string temp{};
			do
			{
				// gets a line from the file and stores it in the temp string
				std::getline(fstr, temp, '\n');

				// If the first character of the string is '>', increment m_size by 1.
				if (temp[0] == '>')
				{
					++m_size;
				}
			} while (fstr); // and loop until the stream variable is valid (till it hasn't reached the end of file)
		}

		// Clear the fstr and reset it to the beginning of the file
		fstr.clear();
		fstr.seekg(0, std::ios::beg);

		// Allocate memory dynamically to m_database for an array of size equal to m_size
		m_database = new std::string[m_size]{};

		// Temporary variable index to keep track of the index at which sequence is to be stored.
		size_t index = 0;
		// Temporary string to check for the line before the beginning of every sequence
		std::string line{};

		std::getline(fstr, line, '\n');
		// peek(): Reads the file but does not extract data from it; checks if the character read is not the End Of File.
		while (fstr.peek() != EOF && line[0] == '>') // Loop until its not EOF and the first character of a line before sequence is the special character '>'
		{
			bool flag = true;
			std::string sequence{}, temp{};

			while (flag && fstr) // Loop until flag and fstr are true.
			{
				std::getline(fstr, temp, '\n');
				// If the line from the file does not begin with '>', concatenate it to the sequence string
				if (temp[0] != '>')
				{
					sequence += temp;
				}
				// Otherwise, set line to the temp and exit the loop.
				else
				{
					line = temp;
					flag = false;
				}
			}

			// Set the sequence extracted at the respective index in the string array; also increment index by 1.
			m_database[index] = sequence;
			++index;
		}
	}

	// *** COPY CONSTRUCTOR ***

	// Inline call to initialise data members to safe state
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) :ProteinDatabase()
	{
		// Uses the assignment operator to set the current object to the received object
		*this = src;
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		// Checks for self-assignment
		if (this != &src)
		{
			// Removes existing DMA if any
			delete[] m_database;

			// Shallow copying non-resource variables
			if (src.m_size != 0)
			{
				m_size = src.m_size;
				// Allocates new memory for m_database based on the src object and copies contents.
				m_database = new std::string[m_size];

				for (auto i = 0u; i < m_size; ++i)
				{
					m_database[i] = src.m_database[i];
				}
			}
		}

		// Returns the current object
		return *this;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src):ProteinDatabase()
	{
		*this = std::move(src);
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src)
	{
		if(this != &src)
		{
			delete[] m_database;

			m_size = src.m_size;
			m_database = src.m_database;
			src.m_database = nullptr;
		}
		return *this;
	}


	// *** DESTRUCTOR ***
	ProteinDatabase::~ProteinDatabase()
	{
		// Deallocates the memory pointed by the m_database pointer
		delete[] m_database;
	}

	// Query: size(): Returns the total strings in the m_database (stored in m_size)
	size_t ProteinDatabase::size() const
	{
		return m_size;
	}

	// Operator[]: Returns a copy of the string stored at the index received as the parameter
	std::string ProteinDatabase::operator[](size_t index) const
	{
		std::string temp{};

		// If the size is 0 or the index is not in the required range, return an empty string
		if (!m_size || index < 0 || index > m_size - 1)
		{
			temp = "";
		}
		// Otherwise return the sequence at the index received
		else
		{
			if(m_database)
				temp = m_database[index];
		}
		return temp;
	}
}