#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 50

typedef struct _DEPT {
  char desig[20];
  float ganhos, despesas;
  int n_pessoas;
} DEPT;

typedef struct _BTREE_NODE {
  DEPT *data;
  struct _BTREE_NODE *left;
  struct _BTREE_NODE *right;
} BTREE_NODE;

#define DATA(node) ((node)->data)
#define LEFT(node) ((node)->left)
#define RIGHT(node) ((node)->right)
typedef BTREE_NODE *BTREE;
typedef enum _BOOLEAN { FALSE = 0, TRUE = 1 } BOOLEAN;
typedef enum _STATUS { ERROR = 0, OK = 1 } STATUS;

BTREE_NODE *NewBtreeNode(void *data) {
  BTREE_NODE *tmp_pt;
  if ((tmp_pt = (BTREE_NODE *)malloc(sizeof(BTREE_NODE))) != NULL) {
    DATA(tmp_pt) = data;
    LEFT(tmp_pt) = RIGHT(tmp_pt) = NULL;
  }
  return tmp_pt;
}

void BtreeFree(BTREE btree) {
  if (btree != NULL) {
    BtreeFree(LEFT(btree));
    BtreeFree(RIGHT(btree));
    free(DATA(btree));
    free(btree);
  }
}

BTREE_NODE *InitNode(void *ptr_data, BTREE_NODE *node1, BTREE_NODE *node2) {
  BTREE_NODE *tmp_pt = NULL;
  tmp_pt = NewBtreeNode(ptr_data);
  LEFT(tmp_pt) = node1;
  RIGHT(tmp_pt) = node2;
  return (tmp_pt);
}

STATUS ReadFile(void **depts, char *file_name) {
  FILE *fp;
  int j, i = 0;
  DEPT *ptr_data;
  if ((fp = fopen(file_name, "r")) != NULL) {
    char *Line = (char *)malloc(sizeof(char) * MAXLINE);
    if (!Line)
      return ERROR;
    while (fgets(Line, MAXLINE, fp)) {
      if ((ptr_data = (DEPT *)malloc(sizeof(DEPT))) != NULL) {
        sscanf(Line, "%[^;];%f;%f;%i\n", ptr_data->desig, &(ptr_data->ganhos),
               &(ptr_data->despesas), &(ptr_data->n_pessoas));
        depts[i] = ptr_data;
        i++;
      } else {
        for (j = i; j >= 0; j--)
          free(depts[j]);
        return (ERROR);
      }
    }

    fclose(fp);
    return (OK);
  } else
    return (ERROR);
}

BTREE_NODE *CreateBtree(void **v, int i, int size) {
  if (i >= size)
    return (NULL);
  else
    return (InitNode(*(v + i), CreateBtree(v, 2 * i + 1, size),
                     CreateBtree(v, 2 * i + 2, size)));
}
void PrintDep(DEPT *dept) {

  printf("%s-%.2f-%.2f-%i\n", dept->desig, dept->ganhos, dept->despesas,
         dept->n_pessoas);
}

void PrintPreOrder(BTREE_NODE *tree) {

  if (tree == NULL)
    return;

  PrintDep(tree->data);
  PrintPreOrder(tree->left);
  PrintPreOrder(tree->right);
}

float LucroEmpresa(BTREE_NODE *tree) {
  if (tree == NULL)
    return 0;

  int valor = 0;

  valor += tree->data->ganhos - tree->data->despesas;
  valor += LucroEmpresa(tree->left);
  valor += LucroEmpresa(tree->right);

  return valor;
}

BTREE_NODE *findMaxNode(BTREE_NODE *tree) {
  if (tree == NULL)
    return NULL; // Base case: empty tree

  BTREE_NODE *leftMax = findMaxNode(tree->left);
  BTREE_NODE *rightMax = findMaxNode(tree->right);

  if (leftMax && leftMax->data->n_pessoas > tree->data->n_pessoas) {
    if (leftMax->data->n_pessoas > rightMax->data->n_pessoas)
      return leftMax;
    else
      return rightMax;
  } else {
    if (rightMax && rightMax->data->n_pessoas > tree->data->n_pessoas)
      return rightMax;
    else
      return tree;
  }
}

int main(int argc, char *argv[]) {
  BTREE btree;
  void *depts[15];
  char file_name[20];
  printf("Nome do ficheiro: ");
  scanf("%s", file_name);
  if (ReadFile(depts, file_name)) {
    btree = CreateBtree(depts, 0, 15);
    // inserir codigo aqui
    PrintPreOrder(btree);

    printf("O valor ganhos - despesas = %.2f", LucroEmpresa(btree));
    BTREE_NODE *maisPessoas = findMaxNode(btree);
    printf("\nDepartamento com mais pessoas: ");
    PrintDep(maisPessoas->data);
    BtreeFree(btree);
  } else
    printf("ERRO na leitura do ficheiro\n");
  return 1;
}
