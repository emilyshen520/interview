// test2.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct linkList
{
	int val;
	linkList *next;
	linkList(int v) { val=v; next=NULL; }
};

void removeMid(linkList *node)
{
	if (!node) return;

	if (node->next)
	{
		node->val=(node->next)->val;
		node->next=(node->next)->next;
	}

}

void printList(linkList *head)
{
	while (head)
	{
		cout << head->val << "    " ;
		head=head->next;
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	linkList *head=NULL,*tail=NULL;
	for (int i=0;i<3;++i)
	{
		linkList *node=new linkList(i);
		if (!head)
			head=tail=node;
		else
		{
			tail->next=node;
			tail=tail->next;
		}
	}
	
	printList(head);
	removeMid(head->next);
	printList(head);
	return 0;
}

