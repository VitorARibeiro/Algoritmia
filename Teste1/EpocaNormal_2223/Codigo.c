#include <stdio.h>
#include <stdlib.h>

typedef enum _STATUS { ERROR, OK } STATUS;
typedef enum _BOOLEAN { FALSE, TRUE } BOOLEAN;

#define MAX 20

typedef struct _LIST_NODE {
  void *data;
  struct _LIST_NODE *next;

} LIST_NODE;

typedef struct _departamento {
  int numeroFuncionarios;
  char nome[MAX];
  int dinheiroDisponivel;
} Departamento;

void PrintLista(LIST_NODE *Lista) {

  while (Lista != NULL) {
    Departamento *DP = (Departamento *)(Lista->data);

    printf("Departamento: %s | NumeroFuncionarios: %i |Dinheiro: %i\n",
           DP->nome, DP->numeroFuncionarios, DP->dinheiroDisponivel);
    Lista = Lista->next;
  }
}

int LerFicheiro(LIST_NODE **Lista) {
  FILE *fp = fopen("Ficheiro.txt", "r");

  if (fp == NULL) {
    printf("Erro ao abrir fiheiro");
    return 1;
  }
  char *string = (char *)malloc(sizeof(char) * MAX * 2);
  while (fgets(string, MAX * 2, fp) != NULL) {
    Departamento *DP;

    if ((DP = (Departamento *)malloc(sizeof(Departamento))) == NULL) {
      printf("erro ao alocar memoria");
      return 1;
    }

    if (sscanf(string, "%i;%[^;];%i", &(DP->numeroFuncionarios),
               DP->nome, // C le string ate chegar ao \0 sem considerar o resto
               &(DP->dinheiroDisponivel)) == EOF) {
      printf("Erro de leitura\n");
      return 1;
    }

    // inserir na Lista
    LIST_NODE *new = (LIST_NODE *)malloc(sizeof(LIST_NODE));

    new->data = DP;
    new->next = *Lista;
    *Lista = new;

    printf("Loop\n");
  }

  free(string);

  return 0;
}

int SomaDinheiro(LIST_NODE *Lista) {
  int soma = 0;

  while (Lista != NULL) {
    Departamento *DP = (Departamento *)(Lista->data);

    soma += DP->dinheiroDisponivel;

    Lista = Lista->next;
  }

  return soma;
}

// Funcao para remover certo Nome da lista Pode aparecer varias vezes

int RemoverNome(LIST_NODE **Lista, char *Nome) {

  LIST_NODE *Current = *Lista;
  LIST_NODE *Previous = NULL;
  while (Current != NULL) {

    Current = Current->next;
  }

  return 0;
}

int GuardarFicheiro(LIST_NODE *Lista, char *Ficheiro) {
  FILE *fp = fopen(Ficheiro, "w");
  if (!fp) {

    printf("Erro ao abrir Ficheiro");

    return 1;
  }
  while (Lista != NULL) {
    Departamento *dp = (Departamento *)(Lista->data);
    fprintf(fp, "%i;%s;%i\n", dp->numeroFuncionarios, dp->nome,
            dp->dinheiroDisponivel);
    Lista = Lista->next;
  }
  fclose(fp);
  return 0;
}
int main() {
  LIST_NODE *Lista = NULL;
  LerFicheiro(&Lista);
  PrintLista(Lista);
  printf("Valor somado é : %i\n", SomaDinheiro(Lista));
  GuardarFicheiro(Lista, "FicheiroEscrita.txt");
  return 1;
}
