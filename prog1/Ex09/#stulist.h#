/* struct declaration */

typedef struct{
  char class[3];
  int  id;
  char name[15];
} Record;



typedef struct node *NodePointer;
struct node {
  Record      data;
  NodePointer next;
}; 

typedef struct node *NodePointer;

/* prototype declaration */
NodePointer insert(Record);
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(Record, NodePointer);

/* Global Variable head */
NodePointer head;
