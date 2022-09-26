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
#include "Car.h"
#include <iomanip>
namespace sdds
{
    Car::Car(std::istream &istr)
    {
        std::string str;
        getline(istr, str);
        if (str.length() != 0)
        {
            str.erase(0, str.find(',') + 1);
            m_maker = str.substr(0, str.find(','));
            trim(m_maker);

            str.erase(0, str.find(',') + 1);
            m_condition = str.substr(0, str.find(','));
            trim(m_condition);
            if (m_condition == "")
                m_condition = "n";
            if (m_condition != "n" && m_condition != "u" && m_condition != "b")
                throw "Invalid record!";
            str.erase(0, str.find(',') + 1);
            try
            {
                m_topSpeed = stoi(str);
            }
            catch (const std::invalid_argument &e)
            {
                throw e;
            }
        }
    }

    std::string Car::condition() const
    {
        std::string re;
        if (m_condition == "n")
            re = "new";
        else if (m_condition == "u")
            re = "used";
        else if (m_condition == "b")
            re = "broken";
        return re;
    }

    double Car::topSpeed() const
    {
        return m_topSpeed;
    }

    void Car::display(std::ostream &out) const
    {
        out << "| " << std::setw(10) << std::right << m_maker << " | "
            << std::setw(6) << std::left << this->condition() << " | "
            << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }

    void Car::trim(std::string &src)
    {
        if (src.length() > 0)
        {
            int begin = src.find_first_not_of(' ');
            int end = src.find_last_not_of(' ');
            if (begin == -1)
                src = "";
            else
                src = src.substr(begin, end - begin + 1);
        }
    }
}