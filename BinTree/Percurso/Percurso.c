#include <stdio.h>
#include <stdlib.h>

typedef struct node {

  char *caracter;
  struct node *right;
  struct node *left;
} NODE;

NODE *InitNode(char *data) {

  NODE *no = (NODE *)malloc(sizeof(NODE));

  if (!no) {
    printf("Erro ao alocar memoria para no");
    return 0; // Return erro
  }

  no->caracter = data;
  no->right = no->left = NULL;

  return no;
}
NODE *CreateNode(char *data, NODE *left, NODE *right) {

  NODE *no = NULL;

  no = InitNode(data);
  if (no) {

    no->right = right;
    no->left = left;
  }

  return no;
}
NODE *CreateBTree(char *array, int i, int size) {

  if (i >= size) {
    return NULL;
  }
  return CreateNode((array + i), CreateBTree(array, 2 * i + 1, size),
                    CreateBTree(array, 2 * i + 2, size));
}

void PrintPreOder(NODE *tree) {

  if (tree == NULL)
    return;
  printf("%c -", *(tree->caracter));
  PrintPreOder(tree->left);
  PrintPreOder(tree->right);
}

void PrintInOrder(NODE *tree) {

  if (tree == NULL)
    return;

  PrintInOrder(tree->left);
  printf("%c -", *(tree->caracter));
  PrintInOrder(tree->right);
}

void PrintPostOrder(NODE *tree) {

  if (tree == NULL)
    return;

  PrintPostOrder(tree->left);
  PrintPostOrder(tree->right);
  printf("%c -", *(tree->caracter));
}
int main() {

  char array[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  NODE *btree = CreateBTree(array, 0, 7);
  printf("PreOrder: \t");
  PrintPreOder(btree);
  printf("\n");
  printf("InOrder: \t");
  PrintInOrder(btree);
  printf("\n");
  printf("PostOrder: \t");
  PrintPostOrder(btree);
  printf("\n");
  printf("Hello World");
  return 0;
}
