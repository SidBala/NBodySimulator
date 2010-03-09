#include "stdafx.h"
#include "PerfTool.h"


CPerfCounter::CPerfCounter()
{
	iStart = iFreq = iEnd = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&iFreq);
}
CPerfCounter::CPerfCounter(CString Name, bool bStart)
{
	CSName = Name;
	QueryPerformanceFrequency((LARGE_INTEGER*)&iFreq);

	if(bStart == true)
		QueryPerformanceCounter((LARGE_INTEGER*)&iStart);
	
}

void CPerfCounter::Start()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&iStart);

}
void CPerfCounter::Stop()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&iEnd);
}
void CPerfCounter::Log()
{
	Stop();
	__int64 interval = iEnd - iStart;
	float timeInms = 1000* (float)(iEnd - iStart)/iFreq;

	printf("\n %15s | %3.3f ms",CSName,timeInms);
}

CPerfCounter::~CPerfCounter()
{
}


CPerfTool::CPerfTool(void)
{
}

CPerfTool::~CPerfTool(void)
{
}
