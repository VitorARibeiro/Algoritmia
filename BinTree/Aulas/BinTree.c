#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STAGES 15

typedef struct Jogador {
  char nome[64];
  int sets;

} JOGADOR;

typedef struct Tree {

  JOGADOR *data;
  struct Tree *right;
  struct Tree *left;

} TREENODE;

TREENODE *CreateNode(JOGADOR *_data) { // Utilizado para iniciar uma Folha

  TREENODE *node = (TREENODE *)malloc(sizeof(TREENODE));
  if (!node) {

    printf("Erro ao alocar memoria");
    return node;
  }
  node->data = _data;
  node->left = node->right = NULL;

  return node; // sem erros
}

TREENODE *CreateNodeInfo(JOGADOR *_data, TREENODE *_left,
                         TREENODE *_right) { // Usado para iniciar um nó

  TREENODE *node = NULL;

  node = CreateNode(_data);
  if (node) {
    node->right = _right;
    node->left = _left;
  }
  return node;
}

TREENODE *CreateBinTree(JOGADOR *v, int i, int size) {

  if (i >= size) {

    return NULL;
  }
  return CreateNodeInfo((v + i), CreateBinTree(v, 2 * i + 1, size),
                        CreateBinTree(v, 2 * i + 2, size));
}
bool ReadFromFile(char *filename, JOGADOR **vetor) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("Erro ao abrir ficheiro\n");
    return false;
  }

  int i = 0;
  char line[64];
  while (fgets(line, 64, fp)) {
    JOGADOR *jogador = (JOGADOR *)malloc(sizeof(JOGADOR));
    if (!jogador) {
      perror("Erro ao alocar memoria para jogador\n");
      fclose(fp);
      free(*vetor); // Free previously allocated memory
      return false;
    }
    sscanf(line, "%[^;];%i", jogador->nome, &(jogador->sets));
    (*vetor)[i] = *jogador; // Assign jogador to vetor[i]
    i++;
  }

  fclose(fp);
  return true;
}
void PrintArrayJogador(JOGADOR *v, int size) {

  for (int i = 0; i < size; i++) {
    printf("Jogador %i - \t nome: %s \t sets: %i \n", i, (v + i)->nome,
           (v + i)->sets);
  }
}

void PrintTreeJogadorPreOrder(TREENODE *node, int space) {

  if (node == NULL)
    return;
  space += 15;

  // Process right child first
  PrintTreeJogadorPreOrder(node->right, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = 5; i < space; i++)
    printf(" ");
  printf("%s / %i\n", node->data->nome, node->data->sets);

  // Process left child
  PrintTreeJogadorPreOrder(node->left, space);
}
bool IsLeaf(TREENODE *Node) {
  return (Node->left == NULL && Node->right == NULL);
}

int CountLeaf(TREENODE *btree) {
  if (btree == NULL)
    return 0;

  return (IsLeaf(btree)) ? 1 : CountLeaf(btree->left) + CountLeaf(btree->right);
}

int maxNumber(int a, int b) { return (a > b) ? a : b; }

int BtreeDepth(TREENODE *btree) {

  if (btree == NULL || IsLeaf(btree))
    return 0;

  return 1 + maxNumber(BtreeDepth(btree->left), BtreeDepth(btree->right));
}

int main() {

  JOGADOR *array = (JOGADOR *)malloc(STAGES * sizeof(JOGADOR));
  ReadFromFile("Jogadores.txt", &array);
  TREENODE *tree = CreateBinTree(array, 0, STAGES);

  PrintTreeJogadorPreOrder(tree, BtreeDepth(tree));
  // PrintArrayJogador(array, STAGES);

  printf("\n");
  printf("Tem %i Leafs\n", CountLeaf(tree));
  printf("Tem %i Niveis\n", BtreeDepth(tree));
  return 0;
}
