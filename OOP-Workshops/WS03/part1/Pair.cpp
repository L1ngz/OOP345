#include "Pair.h"

namespace sdds
{
    bool Pair::operator==(const Pair &a) const
    {
        if (m_key == a.m_key && m_value == a.m_value)
            return true;
        else
            return false;
    };

    Pair &Pair::operator=(const Pair &a)
    {
        m_key = a.m_key;
        m_value = a.m_value;
    }

}