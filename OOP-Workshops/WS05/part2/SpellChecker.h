/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: June 12 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include <string>
#include <iostream>

#define MAX_ARRAY_SIZE 6
namespace sdds
{

    class SpellChecker
    {
        std::string m_badWords[MAX_ARRAY_SIZE]{};
        std::string m_goodWords[MAX_ARRAY_SIZE]{};
        int m_count[MAX_ARRAY_SIZE]{};

    public:
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
    };
};

#endif