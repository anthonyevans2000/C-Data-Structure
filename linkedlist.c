/*
 * Anthony Evans
 *
 * Functions pertaining to the creation, alteration and destruction
 * of linked lists
 */

#include "linkedlist.h"
#include <string.h>

void *emptylist (void)
{
	
	head_l * head;
	head = (head_l*) smalloc(sizeof(head_l));
	head->first = NULL;
	head->last = NULL;
	return head;
}

void *read_integer(void)
{
	data_l *data;
	intdata_l *intptr;
	int input;
	intptr = (intdata_l *) smalloc(sizeof(intdata_l));
	data = (data_l *) smalloc(sizeof(data_l));
	printf("Enter an Integer\n");
	scanf("%d",&input);
	intptr->integer = input;
	data->type = INTEGER;
	data->value = intptr;
	printf("read_integer clear\n");
	fflush(stdout);
	return data;
}	


void data_transfer(node_l *node, data_l *data)
{
	data_l *current;
	intdata_l *intnew, *inttrans ;
	stringdata_l *stringnew, *stringtrans;
	persondata_l *personnew, *persontrans;

	switch(data->type)
	{
		case 0: 
		{
			printf("case is int\n");
			fflush(stdout);
			inttrans = (intdata_l*) data->value;
			intnew = (intdata_l*) smalloc(sizeof(intdata_l));
			
			node->val->key=1;

			printf("case is 1\n");
			fflush(stdout);
			intnew->key = inttrans->key;
			
			printf("case is 2\n");
			fflush(stdout);
			intnew->integer = inttrans->integer;
			
			printf("case is 3\n");
			fflush(stdout);
			node->val->type = INTEGER;
			
			printf("case is 4\n");
			fflush(stdout);

			node->val->value = intnew;
			printf("transfer ok, integer is %d, type is %d\n", intnew->integer, node->val->type);
			fflush(stdout);
			break;
		}
		case 1:
		{
			stringtrans = (stringdata_l*) data->value;
			stringnew = (stringdata_l*) smalloc(sizeof(stringdata_l));
			stringnew->key = inttrans->key;
			strcpy(stringnew->string, stringtrans->string);
			node->val->type = STRING;
			node->val->value = stringnew;
			break;
		}
		case 2:
		{
			persontrans = (persondata_l*) data->value;
			personnew = (persondata_l*) smalloc(sizeof(persondata_l));
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
	printf("in endinsert\n");
	fflush(stdout);
	if(head->first == NULL)
	{
		printf("head is null\n");
		head->first = node;
		head->last = node;
		node->next = NULL;
		node->prev = NULL;
		printf("up to data_transfer\n");
		fflush(stdout);
		node->val = data;
		data_transfer(node,input);
	}else
	{	
		node->prev = head->last;
		node->next = NULL;
		
		head->last->next = node;
		head->last = node;
		
		node->val = data;
		data_transfer(node,input);
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

