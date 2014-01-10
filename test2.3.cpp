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

void removeMid(linkList *head)
{
	if (!head || !(head->next)) 
		return;

	linkList *slow=head;
	linkList *fast=(head->next)->next;

	while (fast && fast->next)
	{
		slow=slow->next;
		fast=(fast->next)->next;
	}

	if (!fast)  return; //this list has even elements

	//slow point to the element before middle element
	slow->next = (slow->next)->next;
	return;

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
	for (int i=0;i<1;++i)
	{
		linkList node(i);
		if (!head)
			head=tail=&node;
		else
		{
			tail->next=&node;
			tail=tail->next;
		}
	}
	
	removeMid(head);
	printList(head);
	return 0;
}

