#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds
{
	template <typename T>
	class GeneratingList
	{

		std::vector<T> list;

	public:
		GeneratingList() {}
		GeneratingList(const char *f)
		{
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file)
			{
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T &operator[](size_t i) const { return list[i]; }

		// TODO: Implement the Luhn Algorithm to check the
		//       valadity of SIN No's
		bool checkLuhn(std::string input)
		{
			size_t len = input.length();
			size_t number = 0;
			size_t sum = 0;
			for (size_t i = 0; i < len; i++)
			{
				number = input[i] - '0';
				if (i % 2 != 0)
				{
					number *= 2;
					if (number > 9)
					{
						number -= 9;
					}
				}
				sum += number;
			}
			return sum % 10 == 0;
		}

		// TODO: Overload the += operator with a smart pointer
		//  as a second operand.
		void operator+=(T &obj)
		{
			list.push_back(obj);
		}

		// TODO: Overload the += operator with a raw pointer
		//  as a second operand.
		void operator+=(T *obj)
		{
			list.push_back(*obj);
		}

		void print(std::ostream &os) const
		{
			os << std::fixed << std::setprecision(2);
			for (auto &e : list)
				e.print(os);
		}
	};

	template <typename T>
	std::ostream &operator<<(std::ostream &os, const GeneratingList<T> &rd)
	{
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
