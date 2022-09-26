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
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
namespace sdds
{
    class Book
    {
        std::string m_author;
        std::string m_title;
        std::string m_country;
        size_t m_year;
        double m_price;
        std::string m_description;

    public:
        Book();
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;
        double &price();
        void setprice(double);
        Book(const std::string &strBook);
        friend std::ostream &operator<<(std::ostream &ostr, const Book &book);
        friend std::string &trim(std::string &);
        template <typename T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(m_description);
        }
    };
};

#endif