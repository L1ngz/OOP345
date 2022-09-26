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
#include "SpellChecker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
namespace sdds
{
    SpellChecker::SpellChecker(const char *filename)
    {
        std::ifstream ifstr(filename);
        if (!ifstr)
        {
            throw "Bad file name!";
        }
        else
        {
            int index = 0;
            do
            {
                ifstr >> m_badWords[index] >> m_goodWords[index];
                index++;
            } while (index < MAX_ARRAY_SIZE && ifstr);
        }
    }
    void SpellChecker::operator()(std::string &text)
    {
        std::string::size_type pos;
        for (int i = 0; i < MAX_ARRAY_SIZE && m_badWords[i].length() != 0; i++)
        {
            int count = 0;
            while (text.find(m_badWords[i]) != std::string::npos)
            {
                pos = text.find(m_badWords[i]);
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                pos += m_goodWords[i].length();
                count++;
            }
            m_count[i] += count;
        }
    };

    void sdds::SpellChecker::showStatistics(std::ostream &out) const
    {
        out << "Spellchecker Statistics" << std::endl;
        for (size_t i = 0; i < 6 && m_badWords[i].length() != 0; i++)
        {
            out << std::setw(15) << std::right << m_badWords[i] << ": " << m_count[i] << " replacements" << std::endl;
        }
    }

}