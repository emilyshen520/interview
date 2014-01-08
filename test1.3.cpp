// test1.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

bool isPermutation(string& s1,string& s2)
{
	map<char,int> records;
	map<char,int>::iterator is;
	string::iterator it=s1.begin();

	while (it!=s1.end())
	{
		is=records.find(*it);
		if (is!=records.end())
			is->second++;
		else
			records[*it]=1;
		++it;
	}

	it=s2.begin();
	while (it!=s2.end())
	{
		is=records.find(*it);
		if (is==records.end())  /*this char does not exist in s1*/
			return false;
		else
		{   /*remove this char from records*/
			if (is->second>1)
				is->second--;
			else
				records.erase(is);
		}
		++it;
	}

	return records.empty();

}

int _tmain(int argc, _TCHAR* argv[])
{
	string s1="";
	string s2="";
	if (isPermutation(s1,s2))
		cout << "successful" << endl;
	else
		cout << "fail" << endl;
	return 0;
}

