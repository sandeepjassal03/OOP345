#include "Book.h"

namespace sdds
{
	Book::Book()
	{
		m_author = {};
		m_title = {};
		m_countryOfPublish = {};
		m_yearOfPublish = {};
		m_price= {};
		m_description = {};
	}

	std::string Book::removeSpaces(std::string& copy, const char delim)
	{
		std::string temp{};
		std::string str{};

		auto index = copy.find(delim);
		temp = copy.substr(0, index);

		auto first = temp.find_first_not_of(' ');
		auto last = temp.find_last_not_of(' ');

		str = temp.substr(first, (last - first) + 1);

		copy.erase(0, index + 1);

		return str;
	}
	Book::Book(const std::string& strBook)
	{
		std::string copy{ strBook };
		std::string temp{};

		m_author = removeSpaces(copy, ',');
		m_title = removeSpaces(copy, ',');
		m_countryOfPublish = removeSpaces(copy, ',');
		m_price = std::stod(removeSpaces(copy,','));
		m_yearOfPublish = std::stoi(removeSpaces(copy,','));
		m_description = removeSpaces(copy,'\n');

	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_countryOfPublish;
	}
	const size_t& Book::year() const
	{
		return m_yearOfPublish;
	}

	double& Book::price()
	{
		return m_price;
	}
	std::ostream& Book::display(std::ostream& ostr) const
	{
		ostr.width(20);
		ostr << std::right << m_author;
		ostr << " | ";

		ostr.width(22);
		ostr << std::right << m_title;
		ostr << " | ";

		ostr.width(5);
		ostr << std::right << m_countryOfPublish;
		ostr << " | ";

		ostr.width(4);
		ostr  << m_yearOfPublish;
		ostr << " | ";

		ostr.width(6);
		ostr.precision(2);
		ostr << std::fixed << m_price;
		ostr << " | ";

		ostr << m_description;
		ostr << std::endl;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& src)
	{
		src.display(ostr);
		return ostr;
	}
}