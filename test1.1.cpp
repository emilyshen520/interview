// test1-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool uniqueChar(string &str)
{
    int size=str.size();
    for (int i=0;i<size;++i)
    {
        for (int j=i+1;j<size;++j)
            if (str[i]==str[j])
                return false;
    }
    return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string teststr="abt";
	if (uniqueChar(teststr))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	return 0;
}

