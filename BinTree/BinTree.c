#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {

  int data;
  struct Tree *right;
  struct Tree *left;

} TREENODE;

TREENODE *CreateNode(int _data) { // Utilizado para iniciar uma Folha

  TREENODE *node = (TREENODE *)malloc(sizeof(TREENODE));
  if (!node) {

    printf("Erro ao alocar memoria");
    return node;
  }
  node->data = _data;
  node->left = node->right = NULL;

  return node; // sem erros
}

TREENODE *CreateNodeInfo(int _data, TREENODE *_left,
                         TREENODE *_right) { // Usado para iniciar um nó

  TREENODE *node = NULL;

  node = CreateNode(_data);
  if (node) {
    node->right = _right;
    node->left = _left;
  }

  return node;
}

TREENODE *CreateBinTree(int *v, int i, int size) {

  if (i >= size) {

    return NULL;
  }
  return CreateNodeInfo(*(v + i), CreateBinTree(v, 2 * i + 1, size),
                        CreateBinTree(v, 2 * i + 1, size));
}

void PrintTree(TREENODE *node) {

  if (node == NULL) {
    return;
  }
  printf("%i - ", node->data);

  PrintTree(node->left);
  PrintTree(node->right);
}

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  TREENODE *tree = CreateBinTree(array, 0, 10);
  PrintTree(tree);

  return 0;
}
