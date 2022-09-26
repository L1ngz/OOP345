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
#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include "Vehicle.h"
#include <list>
namespace sdds
{
    class Autoshop
    {
        std::vector<Vehicle *> m_vehicles;

    public:
        Autoshop &operator+=(Vehicle *theVehicle);
        Autoshop(){};
        Autoshop(const Autoshop &I) = delete;
        Autoshop &operator=(const Autoshop &other) = delete;
        void display(std::ostream &out) const;
        ~Autoshop();

        template <typename T>
        void select(T test, std::list<const Vehicle *> &vehicles)
        {
            for (auto &v : m_vehicles)
            {
                if (test(v))
                    vehicles.push_back(v);
            }
        }
    };
}

#endif
