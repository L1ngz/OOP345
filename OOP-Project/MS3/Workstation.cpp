/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: Aug 06 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#include "Workstation.h"
namespace sdds
{
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string &data) : Station{data} {}

    void Workstation::fill(std::ostream &os)
    {
        if (!m_orders.empty())
        {
            m_orders.front().fillItem(*this, os);
        }
    }
    bool Workstation::attemptToMoveOrder()
    {
        if (m_orders.empty())
        {
            return true;
        }
        else
        {
            if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() == 0)
            {
                if (m_pNextStation == nullptr)
                {
                    if (m_orders.front().isOrderFilled())
                    {
                        g_completed.emplace_back(std::move(m_orders.front()));
                    }
                    else
                    {
                        g_incomplete.emplace_back(std::move(m_orders.front()));
                    }
                }
                else
                {
                    (*m_pNextStation) += std::move(m_orders.front());
                }
                m_orders.pop_front();
                return true;
            }
            return false;
        }
    }
    void Workstation::setNextStation(Workstation *station)
    {
        m_pNextStation = station;
    }
    Workstation *Workstation::getNextStation() const
    {
        return m_pNextStation;
    }
    void Workstation::display(std::ostream &os) const
    {
        os << getItemName();
        os << " --> ";

        if (m_pNextStation == nullptr)
        {
            os << "End of Line" << std::endl;
        }
        else
        {
            os << m_pNextStation->getItemName() << std::endl;
        }
    }
    Workstation &Workstation::operator+=(CustomerOrder &&newOrder)
    {
        m_orders.emplace_back(std::move(newOrder));
        return *this;
    }
    bool Workstation::empty() const
    {
        return m_orders.empty();
    }
}