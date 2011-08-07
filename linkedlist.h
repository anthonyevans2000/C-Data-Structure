/*
 * Anthony Evans
 * Header for linkedlist.c
 */
#define STRING_LENGTH 100


typedef struct intdata
{
	int key;
	int integer;
} intdata_l;

typedef struct stringdata
{
	int key;
	char string[STRING_LENGTH];
} stringdata_l;

typedef struct persondata
{
	int key;
	char name[STRING_LENGTH];
	char address_line_1[STRING_LENGTH];
	char address_line_2[STRING_LENGTH];
	char phone_number[STRING_LENGTH];
} persondata_l;

//Stores a key and an array of voided arrays.
//Pointer array will be null terminated.
//Haskell style data structuring would be beneficial.

enum datatype {INTEGER,STRING,PERSON} type;

typedef struct listdata
{
	int key;
	enum datatype type;
	void *value;
} data_l;

//List node, doubly linked.
typedef struct listnode
{
	struct listnode * next;	
	struct listnode * prev;
	struct listdata * val;
} node_l;


//Head of a linked list- Can edit it to contain a finger array-
// If so, will need to alter the node struct.
typedef struct listhead 
{
	node_l * first;
	node_l * last;

} head_l;



void * emptylist (void);
void * read_integer (void);
void data_transfer (node_l *node, data_l *data);
void endinsert(head_l *head, data_l *input);
void * endretrieve (head_l* head);
