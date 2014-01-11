// test1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char *compression(char *str)
{
	char buffer[33];
	int bufsize=0;
	int size=strlen(str);
	if (size==0) return str;

	char *compstr=(char *)malloc((size+1)*sizeof(char));
	int i=0,j=0,count;

	while (i<size)
	{
		count=1;
		compstr[j++]=str[i++];
		while (i<size && str[i]==compstr[j-1])
		{
			++count;
			++i;
		} //after while, i point to the next new char

		//sprintf_s(buffer,33,"%d",count);
		_itoa_s(count,buffer,33,10);
		bufsize=strlen(buffer);
		if ((j+bufsize)>size) return str; //the compressed str is longer than original str
		strncpy_s(compstr+j,size-j,buffer,bufsize);
		j+=bufsize;
	}

	compstr[j]='\0';
	return compstr;

}


int _tmain(int argc, _TCHAR* argv[])
{
	char *teststr="aabbbccccd";
	char *shortstr=compression(teststr);
	if (strcmp(shortstr,"a2b3c4d1")==0)
		cout << "successful" << endl;
	else
		cout << "failed" << endl;
	free(shortstr);
	return 0;
}

