#ifndef GRAFOS_H
#define GRAFOS_H

#define MAXNODES 20
typedef struct _egde {
  int x, y;
  float weigth;
} EDGE;

typedef struct _grafo {
  int nNodes;
  int nLigacoes;
  int *arrayNodes;
  float **MatrixAdjacencia;
} GRAFO;

GRAFO *CreateGrafo();
EDGE *CreateEdge(int x, int y, float peso);
int AddNode(GRAFO *grafo, int node);
int AddLigacao(GRAFO *grafo, EDGE *edge, int bidirecional); // todo 2
int RemoveNode(GRAFO *grafo, int node);
void PrintNode(GRAFO grafo);
void PrintMatrix(GRAFO grafo);
int CountEdge(GRAFO *grafo, int node);
#endif // DEBUG
