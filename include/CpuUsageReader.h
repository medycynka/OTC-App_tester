#pragma once

#include <Windows.h>

class CpuUsageReader
{
public:
	CpuUsageReader();
	~CpuUsageReader();

	float GetCPULoad();

private:
	static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
	static unsigned long long FileTimeToInt64(const FILETIME& ft);
};

