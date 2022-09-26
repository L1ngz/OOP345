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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
namespace sdds
{

    class Utilities
    {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(size_t);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string &, size_t &, bool &);
        static void setDelimiter(char);
        static char getDelimiter();
    };

}

#endif
