#include <stdio.h>
#include <stdlib.h>
#include "prog00.h"

int main()
{
  int i,num;

  printf("[Initial]\n");
  head = make_1node(0, NULL);
  for (i = 1; i <= 9; i++) insert(i);
  listprint();

  printf("[Insert](enter number)\n");
  while (scanf("%d", &num) == 1) {
    if (insert(num) == NULL) printf("Data %d is already on the list\n", num);
    listprint();
  }
  return 0;
}

NodePointer insert(int keydata)
{
  NodePointer newnode;

  if (finditem(keydata) == NULL) {
    newnode = make_1node(keydata, head->next);
    head->next = newnode;

    return newnode;
  }
  else return NULL;
}

void listprint(void)
{
  NodePointer n;

  printf("Head");
  for (n = head->next; n != NULL; n = n->next) {
    printf(" - %d", n->key);
  }
  printf("\n");
}

NodePointer finditem(int keydata)
{
  NodePointer n;

  for (n = head; n->next != NULL; n = n->next) {
    if (n->next->key == keydata) return n;
  }

  return NULL;
}

NodePointer make_1node(int keydata, NodePointer p)
{
  NodePointer n;

  if ((n = (NodePointer)malloc(sizeof(struct node))) == NULL) {
    printf("Error in memory allocation\n");
    exit(8);
  }

  n->key = keydata;
  n->next = p;

  return n;
}
