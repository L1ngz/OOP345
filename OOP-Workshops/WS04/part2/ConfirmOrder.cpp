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
#include "ConfirmOrder.h"

namespace sdds
{
    ConfirmOrder::ConfirmOrder()
    {
        delete[] m_toy;
        m_toy = nullptr;
    };
    ConfirmOrder::ConfirmOrder(const ConfirmOrder &co)
    {
        *this = co;
    }
    ConfirmOrder &ConfirmOrder::operator=(const ConfirmOrder &co)
    {
        if (this != &co)
        {
            m_OrderCount = co.m_OrderCount;
            delete[] m_toy;
            m_toy = new const Toy *[m_OrderCount];
            for (size_t i = 0; i < m_OrderCount; i++)
            {
                m_toy[i] = co.m_toy[i];
            }
        }
        return *this;
    }
    ConfirmOrder::ConfirmOrder(ConfirmOrder &&co)
    {
        *this = std::move(co);
    }
    ConfirmOrder &ConfirmOrder::operator=(ConfirmOrder &&co)
    {
        if (this != &co)
        {
            m_OrderCount = co.m_OrderCount;
            delete[] m_toy;
            m_toy = co.m_toy;

            co.m_toy = nullptr;
            co.m_OrderCount = 0;
        }

        return *this;
    }

    ConfirmOrder::~ConfirmOrder()
    {
        delete[] m_toy;
    }

    ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
    {

        bool isLocated = false;
        for (size_t i = 0; i < m_OrderCount && !isLocated; i++)
        {
            if (m_toy[i] == &toy)
            {
                isLocated = true;
            }
        }

        if (!isLocated)
        {
            const Toy **actingTemp = nullptr;
            actingTemp = new const Toy *[m_OrderCount + 1];
            for (size_t i = 0; i < m_OrderCount; i++)
            {
                actingTemp[i] = m_toy[i];
            }
            actingTemp[m_OrderCount] = &toy;
            m_OrderCount++;
            delete[] m_toy;
            m_toy = actingTemp;
        }
        return *this;
    }

    ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy)
    {
        bool isLocated = false;
        size_t i = 0;
        for (; i < m_OrderCount && !isLocated; i++)
        {
            if (m_toy[i] == &toy)
            {
                isLocated = true;
            }
        }
        if (isLocated)
        {
            for (; i < m_OrderCount; ++i)
                m_toy[i - 1] = m_toy[i];
            if (m_OrderCount > 0)
            {
                m_toy[m_OrderCount - 1] = nullptr;
                m_OrderCount--;
            }
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const ConfirmOrder &co)
    {

        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if (co.m_toy == nullptr)
        {

            os << "There are no confirmations to send!" << std::endl;
        }
        else
        {

            for (size_t i = 0; i < co.m_OrderCount; i++)
            {
                os << *(co.m_toy[i]);
            }
        }

        os << "--------------------------" << std::endl;
        return os;
    }

}