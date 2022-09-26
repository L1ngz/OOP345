#include "TimedTask.h"
#include <iomanip>

namespace sdds
{
    TimedTask::TimedTask() : m_Stored(0) {}

    void TimedTask::startClock()
    {
        m_Start = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock()
    {
        m_End = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(std::string name)
    {
        m_task[m_Stored].m_TaskName = name;
        m_task[m_Stored].m_UnitofTime = "nanoseconds";
        m_task[m_Stored].m_Duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_End - m_Start);
        m_Stored++;
    }

    std::ostream &operator<<(std::ostream &ostr, const TimedTask &task)
    {
        ostr << "Execution Times:\n"
             << "--------------------------\n";
        for (int i = 0; i < task.m_Stored; i++)
        {
            ostr << std::setw(21) << std::left
                 << task.m_task[i].m_TaskName << " "
                 << std::setw(13) << std::right
                 << task.m_task[i].m_Duration.count() << " "
                 << task.m_task[i].m_UnitofTime << std::endl;
        }
        ostr << "--------------------------\n";
        return ostr;
    };
}