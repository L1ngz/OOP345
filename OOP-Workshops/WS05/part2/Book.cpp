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
#include "Book.h"
#include <iomanip>
namespace sdds
{

    std::string &trim(std::string &a)
    {
        int begin = a.find_first_not_of(' ');
        int end = a.find_last_not_of(' ');
        a = a.substr(begin, end - begin + 1);
        return a;
    };
    Book::Book() : m_author{}, m_title{}, m_country{}, m_year{0}, m_price{0}, m_description{} {};
    const std::string &Book::title() const
    {
        return m_title;
    };
    const std::string &Book::country() const
    {
        return m_country;
    }
    const size_t &Book::year() const
    {
        return m_year;
    };
    double &Book::price()
    {
        return m_price;
    };
    Book::Book(const std::string &strBook)
    {
        std::string temp = strBook;
        m_author = temp.substr(0, temp.find(','));
        m_author = trim(m_author);
        temp.erase(0, temp.find(',') + 1);
        m_title = temp.substr(0, temp.find(','));
        m_title = trim(m_title);
        temp.erase(0, temp.find(',') + 1);
        m_country = temp.substr(0, temp.find(','));
        m_country = trim(m_country);
        temp.erase(0, temp.find(',') + 1);
        m_price = stod(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);
        m_year = stoi(temp.substr(0, temp.find(',')));
        m_description = temp.erase(0, temp.find(',') + 1);
        m_description = trim(m_description);
    }
    std::ostream &operator<<(std::ostream &ostr, const Book &book)
    {

        ostr << std::setw(20) << std::right << book.m_author << " | ";
        ostr << std::setw(22) << std::right << book.m_title << " | ";
        ostr << std::setw(5) << std::right << book.m_country << " | ";
        ostr << std::setw(4) << std::right << book.m_year << " | ";
        ostr << std::setw(6) << std::right << std::fixed << std::setprecision(2) << book.m_price << " | ";
        ostr << std::left << book.m_description << std::endl;
        return ostr;
    };

    void Book::setprice(double a)
    {
        m_price = a;
    };
}