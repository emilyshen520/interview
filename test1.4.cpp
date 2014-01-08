// test1.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int replace(char *str)
{
	int sizestr=strlen(str);
	int orgpos=0,spacenum=0;

	while (orgpos<sizestr)
	{
		if (str[orgpos++]==' ')
			spacenum++;
	}

	int newpos=sizestr+spacenum*2-1;
	str[newpos+1]='\0';
	orgpos=sizestr-1;
	while (orgpos>=0)
	{
		if (str[orgpos]!=' ')
			str[newpos--]=str[orgpos--];
		else
		{
			str[newpos--]='0';
			str[newpos--]='2';
			str[newpos--]='%';
			orgpos--;
		}
	}

	return sizestr+spacenum*2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *teststr=(char *)malloc(50*sizeof(char));
	strcpy_s(teststr,50,"Mr John Smith");
	cout << "the new length " << replace(teststr) << endl;
	cout << teststr << endl;
	free(teststr);

	return 0;
}

