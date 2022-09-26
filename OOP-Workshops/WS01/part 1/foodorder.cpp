#include "foodorder.h"
#include <cstring>
#include <iostream>
#include <iomanip>
namespace sdds
{

    FoodOrder::FoodOrder()
    {
        char temp[] = "N/A";
        strcpy(m_name, temp);
        strcpy(m_desc, temp);
        m_price = 0;
        m_discount = false;
    }
    FoodOrder::FoodOrder(const FoodOrder &a)
    {
        strcpy(m_name, a.m_name);
        strcpy(m_desc, a.m_desc);
        m_price = a.m_price;
        m_discount = a.m_discount;
    }

    FoodOrder &FoodOrder::operator=(const FoodOrder &a)
    {
        strcpy(m_name, a.m_name);
        strcpy(m_desc, a.m_desc);
        m_price = a.m_price;
        m_discount = a.m_discount;
    }

    void FoodOrder::read(std::istream &istr)
    {
        char dis;
        if (!istr.fail())
        {
            istr.get(m_name, 10, ',');
            istr.ignore();
            istr.getline(m_desc, 25, ',');
            istr >> m_price;
            istr.ignore();
            istr >> dis;
            if (dis == 'Y')
                m_discount = true;
            else
                m_discount = false;
        }
    };

    void FoodOrder::display() const
    {
        static int index = 1;
        double special_price = m_price * (1 - g_dailydiscount);
        if (m_name[0] != '\0')
        {
            std::cout
                << std::setw(2)
                << std::left
                << index
                << ". "
                << std::setw(10)
                << std::left
                << m_name
                << "|"
                << std::setw(25)
                << std::left
                << m_desc
                << "|"
                << std::setw(12)
                << std::left
                << std::fixed
                << std::setprecision(2)
                << m_price
                << "|"
                << std::setw(13)
                << std::right;
            if (m_discount)
            {
                std::cout << std::fixed << std::setprecision(2) << special_price << std::endl;
            }
            else
            {
                std::cout << std::setfill(' ') << std::endl;
            }
        }
        else
        {
            std::cout << std::setw(2) << std::left << index << ". No Order" << std::endl;
        }
    }
}