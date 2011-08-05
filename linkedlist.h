/*
 * Anthony Evans
 * Header for linkedlist.c
 */
#define STRING_LENGTH 100


typedef struct intdata_l
{
	int key;
	int integer;
} intdata;

typedef struct stringdata_l
{
	int key;
	char string[STRING_LENGTH];
} stringdata;

typedef struct persondata_l
{
	int key;
	char name[STRING_LENGTH];
	char address_line_1[STRING_LENGTH];
	char address_line_2[STRING_LENGTH];
	char phone_number[STRING_LENGTH];
} persondata;

//Stores a key and an array of voided arrays.
//Pointer array will be null terminated.
//Haskell style data structuring would be beneficial.
typedef struct listdata
{
	int key;
	enum datatype {INTEGER,STRING,PERSON} type;
	void * value;
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
void * endretrieve (head_l*);
