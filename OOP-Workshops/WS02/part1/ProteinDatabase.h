#ifndef PROTEINDATABASE
#define PROTEINDATABASE

#include <string>
namespace sdds
{
    class ProteinDatabase
    {
    public:
        std::string *m_sequence;
        std::size_t m_size;
        ProteinDatabase();
        ProteinDatabase(std::string file);
        std::size_t size();
        std::string operator[](size_t);
    };

}

#endif