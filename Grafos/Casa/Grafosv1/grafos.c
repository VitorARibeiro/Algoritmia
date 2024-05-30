#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>

GRAFO *CreateGrafo() {

  // precisamos de alocar memoria para matrix , e para vertor e settar nNodes e
  // nLigacoes a zero
  // Criar GRAFO
  GRAFO *grafo = (GRAFO *)malloc(sizeof(GRAFO *));

  if (!grafo) {
    perror("Erro ao alocar memoria para grafo");
    return NULL;
  }

  // alocaçao de memoria para vertor
  grafo->arrayNodes = (int *)calloc(sizeof(int *), MAXNODES);

  if (!grafo->arrayNodes) {
    perror("Erro ao alocar memoria para arraynodes");
    return NULL;
  }

  // Alocar memoria para matrix de adjacencia
  grafo->MatrixAdjacencia = (float **)calloc(sizeof(float **), MAXNODES);

  if (!grafo->MatrixAdjacencia) {
    perror("Erro ao alocar memoria para matrix de adjacencia float**");
    return NULL;
  }

  for (int i = 0; i < MAXNODES; i++) {
    grafo->MatrixAdjacencia[i] = (float *)calloc(sizeof(float *), MAXNODES);

    if (!grafo->MatrixAdjacencia) {
      perror("Erro ao alocar memoria para matriz de adjacencia float*");
      return NULL;
    }
  }

  // Settar nNodes e NLigacoes a zero
  grafo->nNodes = 0;
  grafo->nLigacoes = 0;

  return grafo;
}

int AddNode(GRAFO *grafo, int node) {
  if (!grafo) {
    perror("Grafo e nullo nao podemos adicionar no");
    return 0; // 0 erro
  }

  grafo->arrayNodes[grafo->nNodes] = node;
  grafo->nNodes++;
  return 1; // 1 significa true
}
void PrintNode(GRAFO grafo) {

  printf("\n--Print Nodes--\n");

  for (int i = 0; i < grafo.nNodes; i++) {
    printf("%i \t", i);
  }

  printf("\n\n");

  for (int i = 0; i < grafo.nNodes; i++) {
    printf("%i \t", grafo.arrayNodes[i]);
  }

  printf("\n");
}
void PrintMatrix(GRAFO grafo) {

  printf("\n--Print Adj Matrix--\n");

  for (int linhas = -1; linhas < grafo.nNodes; linhas++) {

    if (linhas == -1) {
      printf("\t\t");
    } else {
      printf("%i\t\t", linhas);
    }

    for (int colunas = 0; colunas < grafo.nNodes; colunas++) {
      if (linhas == -1) {

        printf("%i \t", colunas);

      } else {
        printf("%.2f \t", grafo.MatrixAdjacencia[linhas][colunas]);
      }
    }

    printf("\n"); // line break mudanca de linhas
  }
}

int RemoveNode(GRAFO *grafo, int node) {
  // procurar index do no
  // substirui no pelo ultimo
  // Ajustar matrix de adjacencia
  // decrementar nNodes

  // checkar se o grafo existe

  if (!grafo) {
    perror("Grafo nao existe");
    return 0; // 0 representa erro
  }

  // procurar no e confirmar se existe ou nao
  int index = -1;
  for (int i = 0; i < grafo->nNodes; i++) {
    if (grafo->arrayNodes[i] == node) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Nao foi encontrado o no");
    return 0;
  }

  // no encontrado e no index, index
  grafo->nNodes--;
  grafo->arrayNodes[index] = grafo->arrayNodes[grafo->nNodes];
  grafo->arrayNodes[grafo->nNodes] = 0;
  // corrigir matrix

  for (int linhas = 0; linhas < grafo->nNodes + 1; linhas++) {

    grafo->MatrixAdjacencia[linhas][index] =
        grafo->MatrixAdjacencia[linhas][grafo->nNodes];
    grafo->MatrixAdjacencia[linhas][grafo->nNodes] = 0;
  }

  for (int colunas = 0; colunas < grafo->nNodes + 1; colunas++) {

    grafo->MatrixAdjacencia[index][colunas] =
        grafo->MatrixAdjacencia[grafo->nNodes][colunas];
    grafo->MatrixAdjacencia[grafo->nNodes][colunas] = 0;
  }

  return 1;
}

EDGE *CreateEdge(int x, int y, float peso) {
  EDGE *edge = (EDGE *)malloc(sizeof(EDGE *));

  if (!edge) {
    perror("Erro ao alocar memoria para edge");
    return NULL;
  }

  edge->x = x;
  edge->y = y;
  edge->weigth = peso;

  return edge;
}

int AddLigacao(GRAFO *grafo, EDGE *edge, int bidirecional) {

  if (!grafo || !edge) {
    printf("Grafo ou edge sao invalidos");
    return 0; // 0 representa erro
  }

  // encontrar x e y da edge;
  int indexX = -1;
  int indexY = -1;

  for (int i = 0; i < grafo->nNodes; i++) {
    if (grafo->arrayNodes[i] == edge->x) {
      indexX = i;
    }
    if (grafo->arrayNodes[i] == edge->y) {
      indexY = i;
    }

    if (indexX != -1 && indexY != -1)
      break;
  }

  if (indexX == -1 || indexY == -1) {
    printf("Nao encontrado");
    return 0;
  }

  if (bidirecional) {
    grafo->MatrixAdjacencia[indexX][indexY] = edge->weigth;
    grafo->MatrixAdjacencia[indexY][indexX] = edge->weigth;
  } else {

    grafo->MatrixAdjacencia[indexX][indexY] = edge->weigth;
  }

  return 1;
}

int CountEdge(GRAFO *grafo, int node) {
  if (!grafo) {
    printf("grafo e nullo");
    return 0;
  }
  int index = -1;

  for (int i = 0; i < grafo->nNodes; i++) {

    if (grafo->arrayNodes[i] == node) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Node nao enconrado");
    return 0;
  }

  int count = 0;

  for (int i = 0; i < grafo->nNodes; i++) {
    if (grafo->MatrixAdjacencia[index][i] != 0)
      count++;
  }

  return count;
}
