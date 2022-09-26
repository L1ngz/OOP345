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
#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
namespace sdds
{
    template <typename T>
    class Collection
    {
        std::string m_name;
        T *m_arr;
        size_t m_size;
        void (*m_observer)(const Collection<T> &, const T &);

    public:
        Collection(const std::string &name) : m_name{name}, m_arr{}, m_size{}, m_observer{} {};
        ~Collection()
        {
            delete[] m_arr;
        };
        Collection(const Collection &I) = delete;
        Collection(Collection &&I) = delete;
        Collection &operator=(const Collection &other) = delete;
        Collection &operator=(Collection &&other) = delete;
        const std::string &name() const
        {
            return m_name;
        };
        size_t size() const
        {
            return m_size;
        }
        void setObserver(void (*observer)(const Collection<T> &, const T &))
        {
            m_observer = observer;
        }

        Collection<T> &operator+=(const T &item)
        {
            bool found = false;
            if (m_size == 0)
            {
                m_arr = new T[1];
                m_arr[m_size] = item;
                m_size++;
            }
            else if (m_size > 0)
            {
                for (size_t i = 0; i < m_size && !found; i++)
                {
                    if (m_arr[i].title() == item.title())
                        found = true;
                }
                if (!found)
                {
                    T *temp = new T[m_size];
                    for (size_t i = 0; i < m_size; i++)
                    {
                        temp[i] = m_arr[i];
                    }
                    delete[] m_arr;
                    m_arr = new T[++m_size];
                    for (size_t i = 0; i < m_size - 1; i++)
                    {
                        m_arr[i] = temp[i];
                    }
                    delete[] temp;
                    m_arr[m_size - 1] = item;
                    if (m_observer != nullptr)
                        m_observer(*this, item);
                }
            }
            return *this;
        }
        T &operator[](size_t idx) const
        {
            if (idx < 0 || idx >= m_size)
                throw std::out_of_range(std::string("Bad index [") + std::to_string(idx) + std::string("]. Collection has [") + std::to_string(m_size) + std::string("] items."));
            else
                return m_arr[idx];
        }

        T *operator[](const std::string &title) const
        {
            int found = -1;
            for (size_t i = 0; i < m_size && found < 0; i++)
            {
                if (m_arr[i].title() == title)
                    found = i;
            }
            return found > 0 ? &m_arr[found] : nullptr;
        }
    };
    template <typename T>
    std::ostream &operator<<(std::ostream &ostr, const Collection<T> &collection)
    {
        for (size_t i = 0; i < collection.size(); i++)
        {
            ostr << collection[i];
        }
        return ostr;
    }
}
#endif