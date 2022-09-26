/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: July 17 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#ifndef COVIDCOLLECTION_H
#define COVIDCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

namespace sdds
{
    struct Covid
    {
        std::string m_country;
        std::string m_city;
        std::string m_varient;
        int m_numOfCases;
        int m_year;
        int m_deaths;
    };

    class CovidCollection
    {
        std::vector<Covid> m_Covid;

    public:
        CovidCollection(std::string filename);
        void display(std::ostream &out) const;
        void sort(const std::string &params);
        void cleanList();
        bool inCollection(std::string param) const;
        std::list<Covid> getListForVariant(const std::string param);
        std::list<Covid> getListForCountry(const std::string param) const;
    };
    void trim(std::string &src);
    std::ostream &operator<<(std::ostream &out, const Covid &theCovid);

}

#endif