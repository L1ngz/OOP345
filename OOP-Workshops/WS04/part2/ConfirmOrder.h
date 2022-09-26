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
#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H
#include <iostream>
#include "Toy.h"
namespace sdds
{

    class ConfirmOrder
    {
        const Toy **m_toy{nullptr};
        size_t m_OrderCount{0};

    public:
        ConfirmOrder();
        ConfirmOrder(const ConfirmOrder &co);
        ConfirmOrder &operator=(const ConfirmOrder &co);
        ConfirmOrder(ConfirmOrder &&co);
        ConfirmOrder &operator=(ConfirmOrder &&co);
        ~ConfirmOrder();
        ConfirmOrder &operator+=(const Toy &toy);
        ConfirmOrder &operator-=(const Toy &toy);
        friend std::ostream &operator<<(std::ostream &ostr, const ConfirmOrder &co);
    };
};

#endif