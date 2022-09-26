/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: June 18 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#include "Movie.h"
#include <iostream>
#include <iomanip>
namespace sdds
{
    std::string &trimm(std::string &a)
    {
        int begin = a.find_first_not_of(' ');
        int end = a.find_last_not_of(' ');
        a = a.substr(begin, end - begin + 1);
        return a;
    };
    Movie::Movie(){};

    Movie::Movie(const std::string &strMovie)
    {
        std::string temp = strMovie;
        m_title = temp.substr(0, temp.find(','));
        m_title = trimm(m_title);
        temp.erase(0, temp.find(',') + 1);
        m_year = stoi(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);
        // m_description = temp.substr(0, temp.find(','));
        m_description = trimm(temp);
    }

    std::ostream &operator<<(std::ostream &ostr, const Movie &movie)
    {
        ostr << std::setw(40) << std::right << movie.m_title << " | ";
        ostr << std::setw(4) << std::right << movie.m_year << " | ";
        ostr << std::left << movie.m_description << std::endl;

        return ostr;
    }

    const std::string &Movie::title() const
    {
        return m_title;
    };

}