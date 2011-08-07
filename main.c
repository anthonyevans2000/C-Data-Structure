/* Anthony Evans
 *
 * Project utilising a linked list data stack data structure
 * Possibly scouring thee web for information
 */
#include <stdio.h>
#include "smalloc.c"
#include "linkedlist.c"

int main()
{
	head_l *head;
	data_l *data, *test;
	intdata_l *intptr;
	head = (head_l *) emptylist();
	data = (data_l *) read_integer();
	endinsert(head, data);
	test = (data_l *) endretrieve(head);
	intptr = (intdata_l *) test->value;
	printf("value is %d\n",intptr->integer);
	fflush(stdout);
	return 0;
}
