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
#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
#include "Vehicle.h"
namespace sdds
{
    class Car : public Vehicle
    {
        std::string m_maker{};
        std::string m_condition{};
        double m_topSpeed{};

    public:
        Car(std::istream &istr);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream &out) const;
        void trim(std::string &src);
    };

};

#endif