#pragma once

#include <Windows.h>

class CpuUsageReader
{
public:
	CpuUsageReader(int pid);
	~CpuUsageReader();

	//float GetCPULoad();
	int GetCpuUsage();

private:
	//static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
	//static unsigned long long FileTimeToInt64(const FILETIME& ft);

	static __int64 FileTime2Utc(const FILETIME* ftime);
	static int GetProcessorNumber();

private:
	int m_pid;
};

