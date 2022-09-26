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
#ifndef TOY_H
#define TOY_H
#include <iostream>
#include <string>
namespace sdds
{
    class Toy
    {
        unsigned int m_Order_ID{0};
        std::string m_name{};
        unsigned int m_Num_Item{0};
        double m_Price{0};
        double m_Tax{0.13};

    public:
        Toy();
        void update(int numItems);
        Toy(const std::string &toy);
        Toy(const Toy &toy);
        Toy &operator=(const Toy &toy);
        ~Toy();
        friend std::ostream &operator<<(std::ostream &ostr, const Toy &toy);
    };

}
#endif