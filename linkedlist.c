/*
 * Anthony Evans
 *
 * Functions pertaining to the creation, alteration and destruction
 * of linked lists
 */

#include "linkedlist.h"
#include <string.h>

void* emptylist (void)
{
	
	head_l * head;
	head = (head_l*) smalloc(sizeof(head_l));
	head->first = NULL;
	head->last = NULL;
	return head;
}

void data_transfer(node_l *node,data_l *data)
{
	data_l *current;
	intdata *intnew, *inttrans ;
	stringdata *stringnew, *stringtrans;
	persondata *personnew, *persontrans;

	switch(data->type)
	{
		case 0: 
		{	
			inttrans = (intdata*) data->value;
			intnew = (intdata*) smalloc(sizeof(intdata));
			intnew->key = inttrans->key;
			intnew->integer = inttrans->integer;
			node->val->type = INTEGER;
			node->val->value = intnew;
			break;
		}
		case 1:
		{
			stringtrans = (stringdata*) data->value;
			stringnew = (stringdata*) smalloc(sizeof(stringdata));
			stringnew->key = inttrans->key;
			strcpy(stringnew->string, stringtrans->string);
			node->val->type = STRING;
			node->val->value = stringnew;
			break;
		}
		case 2:
		{
			persontrans = (persondata*) data->value;
			personnew = (persondata*) smalloc(sizeof(persondata));
			personnew->key = persontrans->key;
			strcpy(personnew->name, persontrans->name);
			strcpy(personnew->address_line_1, persontrans->address_line_1);
			strcpy(personnew->address_line_2, persontrans->address_line_2);
			strcpy(personnew->phone_number, persontrans->phone_number);
			node->val->type = PERSON;
			node->val->value = personnew;
			break;
		}
	}
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
		//data_transfer(node,input);
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

