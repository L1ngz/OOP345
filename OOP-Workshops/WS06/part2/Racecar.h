/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: July 10 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#ifndef RACECAR_H
#define RACECAR_H
#include "Car.h"
namespace sdds
{
    class Racecar : public Car
    {
        double m_booster{};

    public:
        Racecar(std::istream &in);
        void display(std::ostream &out) const;
        double topSpeed() const;
    };

}

#endif