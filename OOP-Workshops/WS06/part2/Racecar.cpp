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
#include "Racecar.h"
namespace sdds
{

    Racecar::Racecar(std::istream &in) : Car(in)
    {
        in.seekg(std::ios_base::beg);
        std::string str;
        getline(in, str);
        str.erase(0, str.find_last_of(',') + 1);
        m_booster = stod(str);
    }

    void Racecar::display(std::ostream &out) const
    {
        Car::display(out);
        out << '*';
    }

    double Racecar::topSpeed() const
    {
        return Car::topSpeed() * (1 + m_booster);
    }

}