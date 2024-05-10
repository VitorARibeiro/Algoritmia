#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100
#define MAX 20

typedef struct _DIR {
  char desig[MAX];
  int tamanho, Kb;
} DIR;

typedef struct _BTREE_NODE {
  void *data;
  struct _BTREE_NODE *left;
  struct _BTREE_NODE *right;
} BTREE_NODE;

BTREE_NODE *CreateNode(DIR *data) {
  BTREE_NODE *node = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));

  if (!node) {
    perror("Erro ao alocar memoria para no \n");
    return NULL;
  }

  node->data = data;
  node->right = node->left = NULL;
  return node;
}

BTREE_NODE *InnitNode(DIR *data, BTREE_NODE *left, BTREE_NODE *right) {

  BTREE_NODE *node = NULL;

  node = CreateNode(data);
  node->left = left;
  node->right = right;
  return node;
}

BTREE_NODE *CreateBTree(DIR *array, int i, int size) {

  if (i >= size)
    return NULL;
  return InnitNode(array + i, CreateBTree(array, 2 * i + 1, size),
                   CreateBTree(array, 2 * i + 2, size));
}
int CountLine(char *FileName) {

  FILE *fp = fopen(FileName, "r");

  if (!fp) {
    perror("Erro ao abrir ficheiro");
    return 0;
  }

  int count = 0;
  char Line[MAXLINE];

  while (fgets(Line, MAXLINE, fp))
    count++;

  fclose(fp);
  return count;
}

DIR *ReadFromFile(char *FileName) {
  int LineCount = CountLine(FileName);
  int i = 0;
  FILE *fp = fopen(FileName, "r");

  if (!fp) {
    perror("Erro ao abrir ficheiro");
    return NULL;
  }
  char *Line = (char *)malloc(sizeof(char) * MAXLINE);
  DIR *array = (DIR *)malloc(sizeof(DIR) * LineCount);

  while (fgets(Line, MAXLINE, fp)) {
    DIR *dir = (DIR *)malloc(sizeof(DIR));
    if (!dir) {
      perror("Erro ao allocar memoria para dir");
      return NULL;
    }
    sscanf(Line, "%[^;];%i;%i", dir->desig, &(dir->tamanho), &(dir->Kb));
    array[i] = *dir;
    i++;
  }
  free(Line);
  fclose(fp);

  return array;
}
void printDir(DIR *dir) {
  printf("%s | %i | %i \n", dir->desig, dir->tamanho, dir->Kb);
}

void PrintTreePreOrder(BTREE_NODE *tree) {
  if (tree == NULL)
    return;
  printDir(tree->data);
  PrintTreePreOrder(tree->left);
  PrintTreePreOrder(tree->right);
}

void PrintMaiorQueX(BTREE_NODE *tree) {
  if (tree == NULL)
    return;
  DIR *dir = tree->data;
  if (dir->tamanho > 20)
    printDir(tree->data);
  PrintMaiorQueX(tree->left);
  PrintMaiorQueX(tree->right);
}

int TotalKbMaiorQueX(BTREE_NODE *tree) {
  if (tree == NULL)
    return 0;
  DIR *dir = tree->data;
  if (dir->tamanho > 10)
    return dir->Kb + TotalKbMaiorQueX(tree->left) +
           TotalKbMaiorQueX(tree->right);

  return TotalKbMaiorQueX(tree->left) + TotalKbMaiorQueX(tree->right);
}

void PrintTreeVisualPreOrder(BTREE_NODE *node, int space) {

  if (node == NULL)
    return;
  space += 15;

  // Process right child first
  PrintTreeVisualPreOrder(node->right, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = 5; i < space; i++)
    printf(" ");
  printDir(node->data);

  // Process left child
  PrintTreeVisualPreOrder(node->left, space);
}

int TotalKbSum(BTREE_NODE *tree) {
  if (tree == NULL)
    return 0;
  DIR *dir = tree->data;

  return dir->Kb + TotalKbSum(tree->left) + TotalKbSum(tree->right);
}

BTREE_NODE *NodeDesigFinder(BTREE_NODE *node, char *Name) {

  if (node == NULL)
    return NULL;
  DIR *dir = node->data;

  if (!strncmp(dir->desig, Name, MAX))
    return node;

  BTREE_NODE *leftNode = NodeDesigFinder(node->left, Name);
  BTREE_NODE *rightNode = NodeDesigFinder(node->right, Name);

  if (leftNode)
    return leftNode;

  return rightNode;
}

int SumAndFindDirectory(BTREE_NODE *tree, char *Name) {

  BTREE_NODE *node = NodeDesigFinder(tree, Name);

  if (!node) {
    printf("Not Found\n");
    return 0;
  }

  return TotalKbSum(node);
}

int main() {

  DIR *vetor = NULL;
  vetor = ReadFromFile("Input.txt");
  int LineCount = CountLine("Input.txt");

  BTREE_NODE *tree = NULL;
  tree = CreateBTree(vetor, 0, LineCount);
  //  PrintMaiorQueX(tree);
  //  printf("Numero Total de Kb em que Tamanho > 10 = %i",
  //  TotalKbMaiorQueX(tree));
  PrintTreeVisualPreOrder(tree, 0);
  printf("Soma do diretorio: %i\n", SumAndFindDirectory(tree, "Testando"));

  return 0;
}
