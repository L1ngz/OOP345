/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: May 22 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#include "foodorder.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>

double g_taxrate, g_dailydiscount;
namespace sdds
{
    FoodOrder::FoodOrder()
    {
        m_name = nullptr;
        m_desc = nullptr;
        m_price = 0;
        m_discount = false;
    }
    FoodOrder::FoodOrder(const FoodOrder &a)
    {
        m_name = new char[std::char_traits<char>::length(a.m_name) + 1];
        strcpy(m_name, a.m_name);
        m_desc = new char[std::char_traits<char>::length(a.m_desc) + 1];
        strcpy(m_desc, a.m_desc);
        m_price = a.m_price;
        m_discount = a.m_discount;
    }

    FoodOrder &FoodOrder::operator=(const FoodOrder &a)
    {
        delete[] m_name;
        delete[] m_desc;
        m_name = nullptr;
        m_desc = nullptr;
        m_name = new char[std::char_traits<char>::length(a.m_name) + 1];
        strcpy(m_name, a.m_name);
        m_desc = new char[std::char_traits<char>::length(a.m_desc) + 1];
        strcpy(m_desc, a.m_desc);
        m_price = a.m_price;
        m_discount = a.m_discount;
        return *this;
    }

    std::istream &FoodOrder::read(std::istream &istr)
    {
        std::string temp_name;
        std::string temp_desc;

        char dis;
        if (!istr.fail())
        {
            delete[] m_name;
            delete[] m_desc;
            std::getline(istr, temp_name, ',');
            // istr.ignore();
            m_name = new char[temp_name.length() + 1];
            strcpy(m_name, temp_name.c_str());
            std::getline(istr, temp_desc, ',');
            // istr.ignore();
            m_desc = new char[temp_desc.length() + 1];
            strcpy(m_desc, temp_desc.c_str());
            istr >> m_price;
            istr.ignore();
            istr >> dis;
            if (dis == 'Y')
                m_discount = true;
            else
                m_discount = false;
        }
        return istr;
    };

    void FoodOrder::display() const
    {
        static int index = 1;
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
                << m_price * (1 + g_taxrate)
                << "|"
                << std::setw(13)
                << std::right;
            if (m_discount)
            {
                std::cout << std::fixed << std::setprecision(2) << m_price * (1 + g_taxrate) - g_dailydiscount << std::endl;
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
        index++;
    }

    FoodOrder::~FoodOrder()
    {
        delete[] m_name;
        delete[] m_desc;
    }
}