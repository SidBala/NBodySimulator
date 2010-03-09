#pragma once

class CPerfCounter
{
	public:
		CString CSName;
		__int64 iStart;
		__int64 iEnd;
		__int64 iFreq;

	public:
		
		CPerfCounter();
		CPerfCounter(CString Name, bool bStart);

		void Start();
		void Stop();
		void Log();

		~CPerfCounter();
};



class CPerfTool
{
public:
	CPerfTool(void);
	~CPerfTool(void);
};
