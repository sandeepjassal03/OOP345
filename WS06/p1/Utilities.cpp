#include "Utilities.h"


namespace sdds
{
	Person* buildInstance(std::istream& in)
	{
		Person* returnVal = nullptr;
		char input{};
		in >> input;
		if (input == 'e' || input == 'E')
		{
			returnVal = new Employee(in);
		}
		else
		{
			in.ignore(1000, '\n');
		}
		return returnVal;
	}
}
