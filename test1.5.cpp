// test1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

char *compression(char *str)
{
	int size=strlen(str);
	if (size==0) return str;

	char *compstr=(char *)malloc((size+1)*sizeof(char));
	int i=0,j=0,count,tail;

	while (i<size)
	{
		count=1;
		compstr[j++]=str[i++];
		while (i<size && str[i]==compstr[j-1])
		{
			++count;
			++i;
		} //after while, i point to the next new char

		//add count into compstr
		tail=size-1;
	    while (count!=0 && tail>=0)
	    {
		    compstr[tail--]=(count%10)+'0';
		    count=count/10;
	    }
	   	if (count!=0 && tail<0) return str; //the compressed str is longer than original str

	   	tail++;
	   	while (j<size && tail<size)
	    {
		   	compstr[j++]=compstr[tail++];
		}

		if (tail<size && j==size) return str; //the compressed str is longer than original str
	}

	compstr[j]='\0';
	return compstr;

}


int _tmain(int argc, _TCHAR* argv[])
{
	char *teststr="     ";
	
	char *shortstr=compression(teststr);
	if (strcmp(shortstr," 5")==0)
		cout << "successful" << endl;
	else
		cout << "failed" << endl;
	return 0;
}

