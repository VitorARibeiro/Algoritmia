
#ifndef DOUBLY_LINKED_LISTS_H
#define DOUBLY_LINKED_LISTS_H

typedef struct _node {

  int data;
  struct _node *next;
  struct _node *previous;
} NODE;

void PrintList(NODE *Lista);
int AddHead(NODE **Lista, int number);
int AddTail(NODE **Lista, int number);
int removeTail(NODE **Lista);
int RemoveHead(NODE **Lista);

#endif // DOUBLY_LINKED_LISTS_H
