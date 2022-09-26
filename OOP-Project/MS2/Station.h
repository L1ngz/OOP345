/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: July 24 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
namespace sdds
{

    class Station
    {
        int m_stationId{};
        std::string m_itemName{};
        std::string m_desc{};
        size_t m_nextSerialNum{};
        size_t m_numOfItems{};
        static size_t m_widthField;
        static int id_generator;

    public:
        Station(const std::string &str);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &ostr, bool full) const;
    };
}
#endif