#ifndef CHILD_H
#define CHILD_H

#include "Toy.h"

namespace sdds
{
    class Child
    {
        const Toy **m_Toy;
        std::string m_name;
        int m_age;
        size_t m_count;

    public:
        Child(std::string name, int age, const Toy *toys[], size_t count);
        size_t size() const;
    }

}

#endif