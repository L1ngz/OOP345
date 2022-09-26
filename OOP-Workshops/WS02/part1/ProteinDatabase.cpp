#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>

namespace sdds
{
    ProteinDatabase::ProteinDatabase()
    {
        m_sequence = nullptr;
        m_size = 0;
    };
    ProteinDatabase::ProteinDatabase(std::string filename)
    {
        m_size = 0;
        m_sequence = nullptr;
        std::ifstream ifstr(filename);

        if (ifstr)
        {
            size_t count = 0;
            std::string desc;
            while (!ifstr.eof())
            {
                std::string desc;
                std::getline(ifstr, desc);
                std::getline(ifstr, desc, '>');
                count++;
            }
            m_size = count;
            m_sequence = new std::string[m_size];
            ifstr.clear();
            ifstr.seekg(0);
            while (!ifstr.eof())
            {
                std::string desc;
                int i = 0;
                std::getline(ifstr, desc);
                std::getline(ifstr, m_sequence[i], '>');
                i++;
            }
        }
    }

    std::size_t ProteinDatabase::size()
    {
        return m_size;
    }

    std::string ProteinDatabase::operator[](size_t s)
    {
        return (s >= 0 && s < m_size) ? m_sequence[s] : "";
    }

}