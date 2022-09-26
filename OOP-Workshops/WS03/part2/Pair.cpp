#include "Pair.h"
#include <iostream>
#include <iomanip>
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
        return *this;
    }

    std::ostream &Pair::display(std::ostream &ostr)
    {
        ostr << std::left;
        ostr << std::setw(20);
        ostr << getKey();
        ostr << std::left;
        ostr << ": " << getValue();
        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, Pair &a)
    {
        return a.display(ostr);
    };
}