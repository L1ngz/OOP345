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
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
namespace sdds
{

    class Movie
    {
        std::string m_title{};
        int m_year{0};
        std::string m_description{};

    public:
        Movie();
        const std::string &title() const;
        Movie(const std::string &strMovie);
        template <typename T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_description);
        };
        friend std::ostream &operator<<(std::ostream &os, const Movie &movie);
        friend std::string &trimm(std::string &);
    };
}
#endif