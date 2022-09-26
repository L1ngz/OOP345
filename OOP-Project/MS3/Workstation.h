
/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: Aug 06 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
    extern std::deque<sdds::CustomerOrder> g_pending;
    extern std::deque<sdds::CustomerOrder> g_completed;
    extern std::deque<sdds::CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders;
        Workstation *m_pNextStation = nullptr;

    public:
        Workstation(const std::string &data);
        Workstation(const Workstation &a) = delete;
        Workstation(Workstation &&a) = delete;
        Workstation &operator=(const Workstation &a) = delete;
        Workstation &operator=(Workstation &a) = delete;
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station = nullptr);
        Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);
        bool empty() const;
    };
};

#endif