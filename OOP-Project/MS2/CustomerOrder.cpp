/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: July 30 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/

#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"
#include <vector>
#include <iomanip>
namespace sdds
{
    size_t CustomerOrder::m_widthField = 0;

    // CustomerOrder::CustomerOrder(){};

    CustomerOrder::CustomerOrder(const std::string &str)
    {
        Utilities util;
        size_t pos = 0;
        bool flag = true;

        m_name = util.extractToken(str, pos, flag);
        m_product = util.extractToken(str, pos, flag);
        std::vector<Item *> vec;
        Item *temp;
        while (flag)
        {
            temp = new Item(util.extractToken(str, pos, flag));
            vec.push_back(temp);
        }
        m_cntItem = vec.size();
        m_lstItem = new Item *[m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++)
        {
            m_lstItem[i] = vec[i];
        }
        CustomerOrder::m_widthField = CustomerOrder::m_widthField > util.getFieldWidth() ? CustomerOrder::m_widthField : util.getFieldWidth();
    }

    CustomerOrder::CustomerOrder(const CustomerOrder &cus)
    {
        throw "delete copy constructor";
    }

    CustomerOrder::CustomerOrder(CustomerOrder &&I) noexcept
    {
        *this = std::move(I);
    }

    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&param) noexcept
    {
        if (this != &param)
        {
            for (size_t i = 0; i < m_cntItem; i++)
                delete m_lstItem[i];
            delete[] m_lstItem;
            m_name = param.m_name;
            m_product = param.m_product;
            m_cntItem = param.m_cntItem;
            m_lstItem = param.m_lstItem;
            param.m_lstItem = nullptr;
            param.m_cntItem = 0;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder()
    {
        for (size_t i = 0; i < m_cntItem; i++)
            delete m_lstItem[i];
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const
    {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem && flag; i++)
        {
            if (m_lstItem[i]->m_isFilled == false)
                flag = false;
        }
        return flag;
    }

    bool CustomerOrder::isItemFilled(const std::string &item) const
    {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem && flag; i++)
        {
            if (m_lstItem[i]->m_itemName == item && m_lstItem[i]->m_isFilled == false)
                flag = false;
        }
        return flag;
    }

    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
            {
                if (station.getQuantity() >= 1)
                {
                    station.updateQuantity();
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    os << "    Filled " << m_name << ", "
                       << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
                else
                {
                    os << "    Unable to fill " << m_name << ", " << m_product
                       << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream &os) const
    {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] "
               << std::setw(m_widthField) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName
               << "   - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }

}
