#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct _Dados {

  char Nome[MAX];
  int Idade;
  float ContaBancaria;

} DADOS;

typedef struct _Node {

  DADOS *data;
  void *next;

} NODE;

void printList(NODE *Lista) {

  while (Lista != NULL) {
    DADOS *dados = (DADOS *)(Lista->data);

    printf("%s;%i;%f \n", dados->Nome, dados->Idade, dados->ContaBancaria);
    Lista = Lista->next;
  }
}

int ReadFile(NODE **Lista, char *Nome) {

  FILE *fp = fopen(Nome, "r");

  if (!fp) {
    printf("Erro ao abrir ficheiro");
    return 1;
  }

  char *string = (char *)malloc(sizeof(char) * MAX * 2);
  if (string == NULL) {
    printf("Erro ao alocar memoria para string");
    return 1;
  }

  while (fgets(string, MAX * 2, fp)) {
    DADOS *dados = (DADOS *)malloc(sizeof(DADOS));
    if (dados == NULL) {
      printf("Erro ao alocar memoria");
      return 1;
    }

    sscanf(string, "%[^;];%i;%f", dados->Nome, &(dados->Idade),
           &(dados->ContaBancaria));

    // adicionar no inicio da Lista1

    NODE *new = (NODE *)malloc(sizeof(NODE));
    if (new == NULL) {
      printf("Erro ao alocar node");
      return 1;
    }

    new->data = dados;
    new->next = *Lista;
    *Lista = new;
  }

  fclose(fp);
  free(string);
  return 0; // sem erros
}

int EscreverFicheiro(NODE *Lista, char *Nome) {

  FILE *fp = fopen(Nome, "w");
  if (!fp) {

    printf("Erro ao abrir ficheiro");
    return 1;
  }

  while (Lista != NULL) {
    DADOS *dados = (DADOS *)(Lista->data);

    fprintf(fp, "%s;%i;%f \n", dados->Nome, dados->Idade, dados->ContaBancaria);

    Lista = Lista->next;
  }

  return 0;
}

int main() {

  NODE *Lista1 = NULL;

  ReadFile(&Lista1, "Ficheiro.txt");

  printList(Lista1);

  EscreverFicheiro(Lista1, "FicheiroEscrita.txt");

  return 0;
}
