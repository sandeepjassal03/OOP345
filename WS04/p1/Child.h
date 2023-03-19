#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include "Toy.h"

namespace sdds
{
	using PtrToToy = const Toy*;
	class Child 
	{
		std::string m_name{};
		unsigned int m_age{};
		PtrToToy* m_toyList{};
		size_t m_size{};

		void deallocate();
	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& src);
		Child& operator=(const Child& src);
		Child(const Child&& src);
		Child& operator=(const Child&& src);


		size_t size() const;
		~Child();

		friend std::ostream& operator<<(std::ostream& ostr, const Child& src);
	};


}

#endif