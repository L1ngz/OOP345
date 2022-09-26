#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include "Pair.h"

namespace sdds
{
    template <typename T, size_t Capacity>
    class Collection
    {
    protected:
        T m_dummy{};
        T m_collection[Capacity];
        size_t m_stored{0};

    public:
        Collection(){};

        size_t size()
        {
            return m_stored;
        };
        void display()
        {
            std::cout << "----------------------" << std::endl;
            std::cout << "|"
                      << " Collection Content "
                      << "|" << std::endl;
            std::cout << "----------------------" << std::endl;
            for (size_t i = 0; i < m_stored; i++)
            {
                std::cout << m_collection[i] << std::endl;
            }
            std::cout << "----------------------" << std::endl;
        };
        virtual bool add(const T &item)
        {
            bool suc = false;
            if (m_stored < Capacity)
            {
                m_collection[m_stored] = item;
                m_stored++;
                suc = true;
            }
            return suc;
        };

        virtual ~Collection(){};

        T &operator[](size_t index)
        {
            if (index >= 0 && index < Capacity)
            {
                return m_collection[index];
            }
            return m_dummy;
        };
    };
    template <>
    Collection<Pair, 100>::Collection()
    {
        Pair a("No Key", "No Value");
        m_dummy = a;
    };

}
#endif