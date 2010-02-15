// PointerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int* a;
	int* b;
	
	b = a=new int[2];

	printf("%x\n",a);
	a--;
	printf("%x\n",a);
	a--;
	printf("%x\n",a);
	a--;
	printf("%x\n",a);
	a--;
	printf("%x\n",a);
	a--;
	printf("%x\n",a);
	a--;
	printf("%x\n",a);

	delete[] b;
	return 0;  
}

