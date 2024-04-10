#include "DoublyLinkedLists.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

  NODE *Lista1 = NULL;

  AddHead(&Lista1, 7);
  AddHead(&Lista1, 2);
  AddHead(&Lista1, 3);
  AddTail(&Lista1, 1);
  AddTail(&Lista1, 1);
  AddTail(&Lista1, 1);
  PrintList(Lista1);
  // RemoveHead(&Lista1);
  // RemoveHead(&Lista1);

  // PrintList(Lista1);
  return 0;
}
