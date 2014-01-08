// test1.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>
using namespace std;

void reverse(char* str)
{
	int size=strlen(str);

	int front=0,back=size-1;
	while (front<=back)
	{
		char temp=str[back];
		str[back]=str[front];
		str[front]=temp;
		++front;
		--back;
	}

	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//char teststr[]="";
	char *teststr=(char *)malloc(15*sizeof(char));
	strcpy_s(teststr,5,"hello world");
	reverse(teststr);
	cout << teststr << endl;
	return 0;
}

