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
#include "Toy.h"
#include <iomanip>
#include <iostream>
namespace sdds
{
    // default constructor
    Toy::Toy(){};
    // copy constructor
    Toy::Toy(const Toy &toy)
    {
        *this = toy;
    };
    // copy assignment operator
    Toy &Toy::operator=(const Toy &toy)
    {
        m_name = toy.m_name;
        m_Num_Item = toy.m_Num_Item;
        m_Order_ID = toy.m_Order_ID;
        m_Price = toy.m_Price;
        m_Tax = toy.m_Tax;
        return *this;
    };

    void Toy::update(int numItems)
    {
        m_Num_Item = numItems;
    }

    Toy::Toy(const std::string &toy)
    {
        std::string temp = toy;
        std::string ele{};
        int position;
        bool flag = true;

        // WRONG!!! erased all space in the string
        // while (temp.find(' ') != std::string::npos || flag)
        // {
        //     position = temp.find(' ');
        //     if(temp[position - 1] == ' ')
        //         temp.erase(position-1, 1);
        //     else if(temp[position+1]==' ')
        //         temp.erase(position+1, 1);
        // };
        m_Order_ID = std::stoi(temp);
        position = temp.find(':');
        temp = temp.substr(position + 1);

        while (flag)
        {
            position = temp.find(':');
            if (temp[0] == ' ')
                temp.erase(0, 1);
            else if (temp[position - 1] == ' ')
                temp.erase(position - 1, 1);
            else
                flag = false;
        }

        position = temp.find(':');
        m_name = temp.substr(0, position);
        temp = temp.substr(position + 1);
        position = temp.find(':');
        ele = temp.substr(0, position);
        m_Num_Item = std::stoi(ele);
        temp = temp.substr(position + 1);
        m_Price = std::stof(temp);
    };
    Toy::~Toy(){};
    std::ostream &operator<<(std::ostream &ostr, const Toy &toy)
    {
        ostr << "Toy"
             << std::setw(8)
             << toy.m_Order_ID << ":"
             << std::setw(18) << std::right
             << toy.m_name
             << std::setw(3)
             << toy.m_Num_Item
             << " items"
             << std::setw(8)
             << toy.m_Price
             << "/item  subtotal:"
             << std::setw(7)
             << toy.m_Num_Item * toy.m_Price
             << " tax:"
             << std::setw(6) << std::fixed << std::setprecision(2)
             << toy.m_Num_Item * toy.m_Tax * toy.m_Price
             << " total:"
             << std::setw(7) << std::right
             << toy.m_Num_Item * (1 + toy.m_Tax) * toy.m_Price
             << std::endl;

        return ostr;
    }

}