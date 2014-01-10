// test2.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

struct linkList {
	int val;
	linkList *next;
	linkList(int v) {val=v; next=NULL; }
};

void printList(linkList *head)
{
	while (head)
	{
		cout << head->val << "    " ;
		head=head->next;
	}
	cout << endl;
}

void partition(linkList **headNode,int pivot)
{
	linkList *head=*headNode;

	if (!head) return;

	linkList *smallHead=NULL,*smallTail=NULL;
	linkList *largeHead=NULL,*largeTail=NULL;

	while (head)
	{
		if (head->val<pivot) //insert smaller list
			if (!smallHead)
				smallHead=smallTail=head;
			else
			{
				smallTail->next=head;
				smallTail=head;
			}
		else
			if (!largeHead)
				largeHead=largeTail=head;
			else
			{
				largeTail->next=head;
				largeTail=head;
			}
		head=head->next;
	}

    if (smallHead)
	{
		*headNode=smallHead;
		smallTail->next=largeHead;
		largeTail->next=NULL;
	}
	else
		*headNode=largeHead;

	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	linkList *head=NULL,*tail=NULL;
	srand(time(NULL));
	for (int i=0;i<10;++i)
	{
		//linkList node(rand()%100+1);
		linkList *node=new linkList(rand()%100+1);
		if (!head)
			head=tail=node;
		else
		{
			tail->next=node;
			tail=tail->next;
		}
	}
	printList(head);
	partition(&head,50);
	printList(head);
	return 0;
}

