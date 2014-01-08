// test1.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> >  &matrix)
{
	int n=matrix.size();
	if (n<=1) return;
	
	for (int layer=0;layer<(n/2);++layer)
    {
	   	for (int i=layer;i<(n-1-layer);++i)
	   	{
	   		int temp=matrix[n-1-i][layer];
		   	matrix[n-1-i][layer]=matrix[n-1-layer][n-1-i];
		   	matrix[n-1-layer][n-1-i]=matrix[i][n-1-layer];
		   	matrix[i][n-1-layer]=matrix[layer][i];
		   	matrix[layer][i]=temp;
	   	}
    }

	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> > image;
	int arr1[]={2,29,20,26,16,28};
	vector<int> line1(arr1,arr1+6);
	image.push_back(line1);
	int arr2[]={12,27,9,25,13,21};
	vector<int> line2(arr2,arr2+6);
	image.push_back(line2);
	int arr3[]={32,33,32,2,28,14};
	vector<int> line3(arr3,arr3+6);
	image.push_back(line3);
	int arr4[]={13,14,32,27,22,26};
	vector<int> line4(arr4,arr4+6);
	image.push_back(line4);
	int arr5[]={33,1,20,7,21,7};
	vector<int> line5(arr5,arr5+6);
	image.push_back(line5);
	int arr6[]={4,24,1,6,32,34};
	vector<int> line6(arr6,arr6+6);
	image.push_back(line6);
	rotate(image);
	return 0;
}

