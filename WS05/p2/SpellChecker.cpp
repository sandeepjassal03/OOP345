/*
*****************************************************************************
							Workshop-5

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NAA
Date       : 15/02/2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		std::string str{};
		std::string temp{};
		if (file)
		{
			do
			{
				// Getline from the stream
				std::getline(file, str);

				// Find the index of the first space character
				auto index = str.find(' ');
				m_badWords[m_counter] = str.substr(0, index);
				str.erase(0, index);

				index = str.find_first_not_of(' ');
				str.erase(0, index);
				index = str.find('\0');
				m_goodWords[m_counter] = str.substr(0, index);
				++m_counter;
			} while (file.peek() != EOF);
		}
		else // if the file stream is initialised with a missing file, throw an exception
		{
			throw "Bad file name!";
		}
	}
	void SpellChecker::operator()(std::string& text)
	{
		bool flag = false;
		for (auto i = 0u; i < m_counter; ++i) // Loop to check for all the words
		{
			flag = false;
			while (!flag)
			{
				// Find the index where the bad word is found
				auto index = text.find(m_badWords[i]);
				if (index < text.length()) // if the word is actually found:
				{
					// replace the bad word with the goodWord and increment the replacement count for that word
					text.replace(index, m_badWords[i].length(), m_goodWords[i]);
					++m_replacements[i];
				}
				else // If the word is not found, exit the inner loop
				{
					flag = true;
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (auto i = 0u; i < m_counter; ++i)
		{
			out.width(15);
			out << std::right << m_badWords[i];
			out << ": ";
			out << m_replacements[i] << " replacements" << std::endl;
		}
	}
}