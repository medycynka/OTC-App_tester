#include "CpuUsageReader.h"

CpuUsageReader::CpuUsageReader(int pid) : m_pid(pid)
{
}

CpuUsageReader::~CpuUsageReader()
{
}

//float CpuUsageReader::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
//{
//    static unsigned long long _previousTotalTicks = 0;
//    static unsigned long long _previousIdleTicks = 0;
//
//    unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
//    unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;
//
//    float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);
//
//    _previousTotalTicks = totalTicks;
//    _previousIdleTicks = idleTicks;
//    return ret;
//}
//
//unsigned long long CpuUsageReader::FileTimeToInt64(const FILETIME& ft)
//{
//    return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime);
//}

__int64 CpuUsageReader::FileTime2Utc(const FILETIME* ftime)
{
    LARGE_INTEGER li;

    li.LowPart = ftime->dwLowDateTime;
    li.HighPart = ftime->dwHighDateTime;
    return li.QuadPart;
}

int CpuUsageReader::GetProcessorNumber()
{
    SYSTEM_INFO info;
    GetSystemInfo(&info);
    return (int)info.dwNumberOfProcessors;
}

//float CpuUsageReader::GetCPULoad()
//{
//    FILETIME idleTime, kernelTime, userTime;
//    return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
//}

int CpuUsageReader::GetCpuUsage()
{
    //cpu quantity
    static int processor_count_ = -1;
    //Last time
    static __int64 last_time_ = 0;
    static __int64 last_system_time_ = 0;

    FILETIME now;
    FILETIME creation_time;
    FILETIME exit_time;
    FILETIME kernel_time;
    FILETIME user_time;
    __int64 system_time;
    __int64 time;
    __int64 system_time_delta;
    __int64 time_delta;

    int cpu = -1;

    if (processor_count_ == -1)
    {
        processor_count_ = GetProcessorNumber();
    }

    GetSystemTimeAsFileTime(&now);

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, m_pid);

    if (!GetProcessTimes(hProcess, &creation_time, &exit_time, &kernel_time, &user_time))
    {
        return -1;
    }

    system_time = (FileTime2Utc(&kernel_time) + FileTime2Utc(&user_time)) / processor_count_;
    time = FileTime2Utc(&now);

    if ((last_system_time_ == 0) || (last_time_ == 0))
    {
        last_system_time_ = system_time;
        last_time_ = time;
        return -1;
    }

    system_time_delta = system_time - last_system_time_;
    time_delta = time - last_time_;

    if (time_delta == 0)
        return -1;

    cpu = (int)((system_time_delta * 100 + time_delta / 2) / time_delta);
    last_system_time_ = system_time;
    last_time_ = time;

    return cpu;
}
