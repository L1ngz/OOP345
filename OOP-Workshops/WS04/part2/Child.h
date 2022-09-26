/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: June 12 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#ifndef CHILD_H
#define CHILD_H

#include "Toy.h"

namespace sdds
{
    class Child
    {
        const Toy **m_Toy{nullptr};
        std::string m_name{};
        int m_age{0};
        size_t m_count{0};

    public:
        Child(std::string name, int age, const Toy *toys[], size_t count);
        size_t size() const;
        Child();
        Child(Child &&child);
        Child &operator=(Child &&child);
        Child(const Child &child);
        Child &operator=(const Child &child);
        ~Child();
        friend std::ostream &operator<<(std::ostream &ostr, const Child &child);
    };

}

#endif