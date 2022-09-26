/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: July 30 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include "Station.h"
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };
    class CustomerOrder
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item **m_lstItem{};
        static size_t m_widthField;

    public:
        CustomerOrder(){};
        CustomerOrder(const std::string &);
        CustomerOrder(const CustomerOrder &);
        CustomerOrder(CustomerOrder &&) noexcept;
        CustomerOrder &operator=(CustomerOrder &&) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;
    };
}

#endif