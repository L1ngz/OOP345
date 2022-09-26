#ifndef FOODORDER_H
#define FOODORDER_H
#include <iostream>
namespace sdds
{

    class FoodOrder
    {
        char m_name[10];
        char m_desc[25];
        double m_price;
        bool m_discount;

    public:
        FoodOrder();
        FoodOrder(const FoodOrder &a);
        FoodOrder &operator=(const FoodOrder &a);
        void read(std::istream &istr);
        void display() const;
    };

}

#endif