
#ifndef TIMEDTASK
#define TIMEDTASK

#include <iostream>
#include <chrono>
#include <string>

namespace sdds
{
    const int max_Event = 10;
    struct Task
    {
        std::string m_TaskName;
        std::string m_UnitofTime;
        std::chrono::steady_clock::duration m_Duration;
    };
    class TimedTask
    {
    public:
        int m_Stored;
        std::chrono::steady_clock::time_point m_Start;
        std::chrono::steady_clock::time_point m_End;
        Task m_task[max_Event];
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(std::string taskName);
        friend std::ostream &operator<<(std::ostream &ostr, const TimedTask &timedtask);
    };
}

#endif