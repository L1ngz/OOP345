/*
---------------------------------
Student Name: Ling Zhang
Student ID:150903219
Date: July 10 2022
----------------------------------
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
----------------------------------------------------------------------------------------
*/
#include <string>
#include <sstream>
#include "Car.h"
#include "Racecar.h"
#include "Utilities.h"
namespace sdds
{
    Vehicle *createInstance(std::istream &in)
    {
        Vehicle *result = nullptr;

        char vType = '\0';

        std::string str;
        std::stringstream sstr;
        getline(in, str);
        if (in.eof())
            in.setstate(std::ios_base::failbit);
        sstr.str(str);
        std::streampos pos = sstr.tellg();
        sstr >> vType;
        sstr.seekg(pos);

        if (vType == 'c' || vType == 'C')
        {
            result = new Car(sstr);
        }
        else if (vType == 'r' || vType == 'R')
        {
            result = new Racecar(sstr);
        }
        else
        {
            throw vType;
        }

        return result;
    }
}
