// test1.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

bool isSubstring(string s1,string s2)
{
	if (s1.find(s2)!=string::npos)
		return true;
	else
		return false;
}

bool isRotatesub(string s1,string s2)
{
	if (s1.length()!=s2.length() || s1.length()==0)
		return false;
	return isSubstring(s1+s1,s2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s1="waterbottle";
	string s2="erbottlewat";
	if (isRotatesub(s2,s1))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}

