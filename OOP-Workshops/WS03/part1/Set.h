#ifndef SET_H
#define SET_H

#include <cmath>
#include "Collection.h"
namespace sdds
{
    template <typename T>
    class Set : public Collection<T, 100>
    {
        const size_t Capacity = 100;

    public:
        Set(){};
        bool add(const T &a)
        {
            for (size_t i = 0; i < m_stored; i++)
            {
                if (a == *this)
                    return false;
            }
            return Collection<T, 100>::add(a);
        }
    };

    template <>
    bool Set<double>::add(const double &a)
    {
        for (size_t i = 0; i < m_stored; i++)
        {
            if (std::fabs(a - m_collection[i]) <= 0.01)
            {
                return false;
            }
        }

        return Collection<double, 100>::add(a);
    }

};

#endif