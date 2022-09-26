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

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"

namespace sdds
{
    class LineManager
    {
        std::vector<Workstation *> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation *m_firstStation;

    public:
        LineManager(const std::string &file, const std::vector<Workstation *> &stations);
        void reorderStations();
        bool run(std::ostream &os);
        void display(std::ostream &os) const;
    };
};

#endif