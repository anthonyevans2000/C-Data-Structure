/*
 * Anthony Evans
 *
 * Functions pertaining to the creation, alteration and destruction
 * of linked lists
 */

#include "linkedlist.h"

void* emptylist (void)
{
	
	head_l * head;
	head = (head_l*) smalloc(sizeof(head_l));
	head->first = NULL;
	head->last = NULL;
	return head;
}

void endinsert (head_l *head, data_l *input)
{
	node_l *node;
	data_l *data;
	node_l *current;

	data = (data_l*) smalloc(sizeof(data));
	node = (node_l*) smalloc(sizeof(node));
	
	if(head->first == NULL)
	{	
		head->first = node;
		head->last = node;
		node->next = NULL;
		node->prev = NULL;
		node->val = input;

	}else
	{	
		node->prev = head->last;
		node->next = NULL;
		
		head->last->next = node;
		head->last = node;
		
		node->val = data;
		//data_transfer(head,input);
	}
}

//Returns NULL if there are no elements
void * endretrieve (head_l *head)
{
	if(head == NULL)
	{
		return NULL;
	}else
	{
		return head->last;
	}

}

