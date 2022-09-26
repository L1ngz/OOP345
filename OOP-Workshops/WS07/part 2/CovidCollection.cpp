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
#include "CovidCollection.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

namespace sdds
{

    void trim(std::string &src)
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
    };

    std::ostream &operator<<(std::ostream &out, const Covid &theCovid)
    {
        out << "| " << std::setw(20) << std::left << theCovid.m_country
            << "  | " << std::setw(15) << theCovid.m_city << " | "
            << std::setw(20) << theCovid.m_varient << " | "
            << std::setw(6) << std::right;
        if (theCovid.m_year == 0)
        {
            out << "";
        }
        else
        {

            out << theCovid.m_year;
        }
        out << " | "
            << std::setw(4) << theCovid.m_numOfCases << " | "
            << std::setw(3) << theCovid.m_deaths << " |";

        return out;
    }

    CovidCollection::CovidCollection(std::string filename)
    {
        std::fstream ifstr(filename);
        Covid temp;
        std::string line;

        if (!ifstr)
        {
            throw "Error, file name is not correct";
        }
        else
        {
            do
            {
                getline(ifstr, line);
                if (ifstr)
                {
                    temp.m_country = line.substr(0, 25);
                    trim(temp.m_country);
                    temp.m_city = line.substr(25, 25);
                    trim(temp.m_city);
                    temp.m_varient = line.substr(50, 25);
                    trim(temp.m_varient);
                    try
                    {
                        temp.m_year = std::stoi(line.substr(75, 5));
                        if (temp.m_year < 0)
                            throw(-1);
                    }
                    catch (...)
                    {
                        temp.m_year = 0;
                    }
                    temp.m_numOfCases = std::stoi(line.substr(80, 5));
                    temp.m_deaths = std::stoi(line.substr(85, 5));
                    m_Covid.push_back(temp);
                }
            } while (ifstr);
            ifstr.close();
        }
    }

    void CovidCollection::display(std::ostream &out) const
    {
        int total_cases = 0, total_death = 0;
        for (auto &&i : m_Covid)
        {
            out << i << std::endl;
            total_cases += i.m_numOfCases;
            total_death += i.m_deaths;
        }
        out << std::setw(89) << std::setfill('-') << '\n';
        out << "| " << std::setw(77) << std::setfill(' ') << std::right << "Total Cases Around the World:";
        out << std::setw(7) << std::right << total_cases << " |" << std::endl;

        out << "| " << std::setw(77) << std::right << "Total Deaths Around the World:";
        out << std::setw(7) << std::right << total_death << " |" << std::endl;
    }

    void CovidCollection::sort(const std::string &params)
    {
        std::sort(m_Covid.begin(), m_Covid.end(), [&params](const Covid &c1, const Covid &c2)
                  {
				if (params == "country") return c1.m_country < c2.m_country;
				else if (params == "variant") return c1.m_varient < c2.m_varient;
				else if (params == "cases") return c1.m_numOfCases < c2.m_numOfCases;
				else if (params == "deaths") return c1.m_deaths < c2.m_deaths;
                else return c1.m_city < c2.m_city; });
    }

    void CovidCollection::cleanList()
    {
        Covid temp;
        std::replace_if(
            m_Covid.begin(), m_Covid.end(), [&temp](const Covid &covid)
            {temp = covid; temp.m_varient = ""; return covid.m_varient == "[None]"; },
            temp);
    }

    bool CovidCollection::inCollection(std::string param) const
    {
        return any_of(m_Covid.begin(), m_Covid.end(), [&param](const Covid &covid)
                      { return covid.m_varient == param; });
    }

    std::list<Covid> CovidCollection::getListForCountry(const std::string param) const
    {
        std::list<Covid> Covidlist(m_Covid.size());
        auto it = copy_if(m_Covid.begin(), m_Covid.end(), Covidlist.begin(), [&param](const Covid &Covid)
                          { return Covid.m_country == param; });
        Covidlist.resize(std::distance(Covidlist.begin(), it));
        return Covidlist;
    }

    std::list<Covid> CovidCollection::getListForVariant(const std::string param)
    {
        std::list<Covid> Covidlist(m_Covid.size());
        auto it = copy_if(m_Covid.begin(), m_Covid.end(), Covidlist.begin(), [&param](const Covid &Covid)
                          { return Covid.m_varient == param; });
        Covidlist.resize(std::distance(Covidlist.begin(), it));
        return Covidlist;
    }
}