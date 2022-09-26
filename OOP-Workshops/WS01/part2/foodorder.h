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

#ifndef FOODORDER_H
#define FOODORDER_H
#include <iostream>
namespace sdds
{

    class FoodOrder
    {
        char *m_name;
        char *m_desc;
        double m_price;
        bool m_discount;

    public:
        FoodOrder();
        FoodOrder(const FoodOrder &a);
        ~FoodOrder();
        FoodOrder &operator=(const FoodOrder &a);
        std::istream &read(std::istream &istr);
        void display() const;
    };

}

#endif