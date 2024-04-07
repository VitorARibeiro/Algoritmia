#include "DoublyLinkedLists.h"
#include <stdio.h>
#include <stdlib.h>

void PrintList(NODE *Lista) {

  while (Lista != NULL) {

    printf("%i - ", Lista->data);
    Lista = Lista->next;
  }

  printf("\n");
}

int AddHead(NODE **Lista, int number) {
  // alocar novo node
  NODE *new = (NODE *)malloc(sizeof(NODE));
  if (!new) {
    printf("Erro ao alocar new node \n");
    return 1;
  }

  new->data = number;
  new->next = *Lista;
  if (*Lista == NULL) { // Adicionar primeiro elemento

    new->previous = NULL;
  } else {
    new->previous = (*Lista)->previous;
  }
  *Lista = new;
  return 0; // sem erros
}

int AddTail(NODE **Lista, int number) { // Vante
  // agens de Biencadeads :)

  NODE *new = (NODE *)malloc(sizeof(NODE));
  if (!new) {

    printf("Erro ao alocar memoria para node");
    return 1;
  }

  new->data = number;
  new->next = *Lista;

  if (*Lista == NULL) {

    new->previous = NULL;
    *Lista = new;
  } else {
    NODE *last = (*Lista)->previous;

    last->next = new;
    new->previous = last;
    (*Lista)->previous = new;
  }

  return 0; // sem erros
}
