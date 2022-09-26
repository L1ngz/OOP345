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
#include "Child.h"

namespace sdds
{
    Child::Child()
    {
        delete[] m_Toy;
        m_Toy = nullptr;
    }
    Child::Child(std::string Toy_Name, int age, const Toy *toys[], size_t count)
        : m_name(Toy_Name), m_age(age)
    {
        for (auto i = 0u; i < m_count; ++i)
            delete m_Toy[i];

        delete[] m_Toy;
        m_count = count;
        m_Toy = new const Toy *[count];

        for (size_t i = 0; i < count; i++)
        {

            m_Toy[i] = new Toy(*(toys[i]));
        }
    }
    Child::Child(const Child &obj)
    {
        *this = obj;
    }
    Child &Child::operator=(const Child &obj)
    {
        if (this != &obj)
        {
            for (auto i = 0u; i < m_count; ++i)
                delete m_Toy[i];
            delete[] m_Toy;
            m_count = obj.m_count;
            m_age = obj.m_age;
            m_name = obj.m_name;
            m_Toy = new const Toy *[m_count];
            for (size_t i = 0; i < m_count; i++)
            {
                m_Toy[i] = new Toy(*(obj.m_Toy[i]));
            }
        }
        return *this;
    }

    Child::Child(Child &&obj)
    {
        *this = std::move(obj);
    }

    Child &Child::operator=(Child &&obj)
    {
        if (this != &obj)
        {

            delete[] m_Toy;
            m_count = obj.m_count;
            m_age = obj.m_age;
            m_name = obj.m_name;
            m_Toy = obj.m_Toy;
            obj.m_Toy = nullptr;
            obj.m_age = 0;
            obj.m_name = "";
            obj.m_count = 0;
        }
        return *this;
    }

    Child::~Child()
    {
        for (size_t i = 0; i < m_count; ++i)
            delete m_Toy[i];

        delete[] m_Toy;
        m_Toy = nullptr;
    }

    size_t Child::size() const
    {
        return this->m_count;
    }

    std::ostream &operator<<(std::ostream &ostr, const Child &child)
    {
        static size_t CALL_CNT = 1;
        ostr << "--------------------------" << std::endl;
        if (child.m_Toy == nullptr)
        {
            ostr << "Child " << CALL_CNT << ": "
                 << " "
                 << "0 years old:" << std::endl;
            ostr << "--------------------------" << std::endl;
            ostr << "This child has no toys!" << std::endl;
        }
        else
        {
            ostr << "Child " << CALL_CNT << ": " << child.m_name << " " << child.m_age << " years old:" << std::endl;
            ostr << "--------------------------" << std::endl;
            for (size_t i = 0; i < child.m_count; i++)
            {
                ostr << *(child.m_Toy[i]);
            }
        }
        CALL_CNT++;
        ostr << "--------------------------" << std::endl;

        return ostr;
    }

}