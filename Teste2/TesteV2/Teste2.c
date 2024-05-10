#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct cesar {

  float litro, preco, desconto;
  char tipo[MAX];
} CESAR;

typedef struct node {
  CESAR *faria;
  struct node *left;
  struct node *right;
} NODE;

NODE *CreateNode(CESAR *valor) {

  NODE *no = (NODE *)malloc(sizeof(NODE));

  if (!no) {

    perror("Erro ao alocar memoria");
    return NULL;
  }

  no->faria = valor;
  no->left = no->right = NULL;
  return no;
}

NODE *InnitNode(CESAR *valor, NODE *left, NODE *right) {

  NODE *no = CreateNode(valor);

  if (!no)
    return NULL;

  no->left = left;
  no->right = right;

  return no;
}

NODE *CreateBTree(CESAR *vetor, int i, int size) {

  if (i >= size)
    return NULL;

  return InnitNode(vetor + i, CreateBTree(vetor, 2 * i + 1, size),
                   CreateBTree(vetor, 2 * i + 2, size));
}

void PrintCesar(CESAR *faria) {

  printf("%.2f | %.2f | %.2f | %s\n", faria->litro, faria->preco,
         faria->desconto, faria->tipo);
}

void PrintInOrder(NODE *tree) {
  if (tree == NULL)
    return;

  PrintInOrder(tree->left);
  PrintCesar(tree->faria);
  PrintInOrder(tree->right);
}

int FileLine(char *FILENAME) {

  int count = 0;
  FILE *fp = fopen(FILENAME, "r");
  if (!fp) {
    perror("Erro ao abrir ficheiro");
    return 0;
  }
  char Line[50];

  while (fgets(Line, 50, fp)) {
    count++;
  }
  fclose(fp);
  return count;
}

CESAR *CreateVetor(char *FILENAME) {

  int LineCount = FileLine(FILENAME);

  FILE *fp = fopen(FILENAME, "r");

  if (!fp) {
    perror("Erro ao abrir ficheiro");
    return NULL;
  }
  char *Line = (char *)malloc(sizeof(char) * 50);

  if (!Line) {

    perror("Erro ao alocar memoria para linha ");
    return NULL;
  }

  CESAR *vetor = (CESAR *)malloc(sizeof(CESAR) * LineCount);

  if (!vetor) {
    perror("Erro ao alocar memoria para vetor cesar");
    return NULL;
  }

  int i = 0;
  while (fgets(Line, 50, fp)) {

    CESAR *cesar = (CESAR *)malloc(sizeof(CESAR));
    if (!cesar) {
      perror("Erro ao alocar memoria para cesar");
      return NULL;
    }
    sscanf(Line, "%f;%f;%f;%s", &(cesar->litro), &(cesar->preco),
           &(cesar->desconto), cesar->tipo);
    vetor[i] = *cesar;
    i++;
  }
  fclose(fp);
  free(Line);
  return vetor;
}

void PrintVetor(CESAR *vetor, int size) {

  for (int i = 0; i < size; i++) {
    PrintCesar(vetor + i);
  }
}

void PrintTreeVisualPreOrder(NODE *node, int space) {

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

  PrintCesar(node->faria);
  // Process left child
  PrintTreeVisualPreOrder(node->left, space);
}
void PrintSup50(NODE *tree) {
  if (tree == NULL)
    return;

  if (tree->faria->preco > 50)
    PrintCesar(tree->faria);

  PrintSup50(tree->left);
  PrintSup50(tree->right);
}

void AdicionarRightMost(NODE *tree) {
  if (tree == NULL)
    return;
  AdicionarRightMost(tree->right);
  if (tree->right == NULL) {
    AdicionarRightMost(tree->left);
    if (tree->left == NULL) {
      tree->faria->litro += 10;
    }
  }
}

int main() {
  int LineCount = FileLine("ficheiro.txt");
  CESAR *vetor = CreateVetor("ficheiro.txt");
  NODE *tree = CreateBTree(vetor, 0, LineCount);
  // PrintInOrder(tree);
  PrintTreeVisualPreOrder(tree, 0);

  // exercicios
  printf("Superior a 50 \n\n");
  PrintSup50(tree);

  printf("Adicionar ao no da direita\n\n");
  AdicionarRightMost(tree);
  PrintTreeVisualPreOrder(tree, 0);

  return 0;
}
