#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------
// Constructor and Destructor Functions -----------
STATUS initGraph_M(GRAPH_M *pG, int size) {
  // adjacency matrix allocation
  if ((pG->adjMatrix = (float **)malloc(size * sizeof(float *))) == NULL) {
    printf("\nGraph: adjacency matrix memory allocation error.");
    return ERROR;
  }
  for (int i = 0; i < size; i++) {
    if ((pG->adjMatrix[i] = (float *)malloc(size * sizeof(float))) == NULL) {
      printf("\nGraph: adjacency matrix memory allocation error.");
      for (int j = i; j >= 0; j--)
        free(pG->adjMatrix[j]);
      free(pG->adjMatrix);
      return ERROR;
    }
  }
  // vertices’ data array allocation
  if ((pG->pD = (int *)malloc(size * sizeof(int))) == NULL) {
    printf("\nGraph: vertices data memory allocation error.");
    return ERROR;
  }
  // adjacency matrix update
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      pG->adjMatrix[i][j] = 0.0;
  pG->nEdges = 0;
  pG->nVertices = 0;
  return OK;
}
//-------------------------------------------------
STATUS destroyGraph_M(GRAPH_M *pG) {
  // underflow
  if (emptyGraph_M(*pG))
    return ERROR;
  // freeing allocated memory
  free(pG->pD);
  for (int i = 0; i < pG->nVertices; i++)
    free(pG->adjMatrix[i]);
  free(pG->adjMatrix);
  pG->nEdges = 0;
  pG->nVertices = 0;
  return OK;
}
//-------------------------------------------------
// Input Functions --------------------------------
EDGE setEdge(int v, int w, float weight) {
  EDGE e;
  e.v = v;
  e.w = w;
  e.weight = weight;
  return e;
}
//-------------------------------------------------
// Query Functions --------------------------------
BOOLEAN emptyGraph_M(GRAPH_M G) { return ((G.nVertices == 0) ? TRUE : FALSE); }
//-------------------------------------------------
// Query Functions – Traversing & Printing --------
// recursive DepthFirstSearch version
STATUS DFSGraph_M(GRAPH_M G, EDGE e, int order[], int from[], int *pCnt)
// non-generic - suitable only for int data
// order[] is to keep the order vertices are visited
// from[] is to keep where from vertices are visited
{
  // treats startting vertex differently
  if (*pCnt == 0)
    printf("\nvertex %-3d: %d", 0, G.pD[0]);
  order[e.w] = (*pCnt)++;
  from[e.w] = e.v;
  // searches for the next non-empty connection
  for (int j = 0; j < G.nVertices; j++)
    if (G.adjMatrix[e.w][j] != 0)
      if (order[j] == -1) {
        printf("\nvertex %-3d: %d", j, G.pD[j]);
        // searches for the next non-empty connection of the previous destiny
        // vertex
        DFSGraph_M(G, setEdge(e.w, j, 0), order, from, pCnt);
      }
  return OK;
}
//-------------------------------------------------
// Query Functions - Printing ---------------------
STATUS printAdjMatrix(GRAPH_M G) {
  // underflow
  if (emptyGraph_M(G))
    return ERROR;
  printf("\n\nAdjacency Matrix:\n\n");
  printf(" ");
  for (int i = 0; i < G.nVertices; i++)
    printf("%3d ", i);
  printf("\n\n");
  for (int i = 0; i < G.nVertices; i++) {
    printf("%3d ", i);
    for (int j = 0; j < G.nVertices; j++)
      printf(" %2.1f ", G.adjMatrix[i][j]);
    printf("\n");
  }
  return OK;
}
//-------------------------------------------------
STATUS printVertices(GRAPH_M G)
// non-generic - suitable only for int data
{
  // underflow
  if (emptyGraph_M(G))
    return ERROR;
  printf("\nVertices:\n");
  for (int i = 0; i < G.nVertices; i++)
    printf("\nvertex %-3d: %d", i, G.pD[i]);
  return OK;
}
//-------------------------------------------------
STATUS DFSTraverseGraph_M(GRAPH_M G)
// non-generic - suitable only for int data
{
  // underflow
  // checkar se o grafo esta vazio ou nao
  if (emptyGraph_M(G))
    return ERROR;
  // starting vertex
  EDGE e;
  e.v = 0;
  e.w = 0;
  e.weight = 0;
  // order[] is to keep the order vertices are visited
  // from[] is to keep where from vertices are visited
  int order[NMAX_VERTICE];
  int from[NMAX_VERTICE];
  // settar tudo com inf -1
  for (int i = 0; i < NMAX_VERTICE; i++) {
    order[i] = -1;
    from[i] = -1;
  }

  int cnt = 0;
  printf("\nvertices");
  DFSGraph_M(G, e, order, from,
             &cnt); // recursive DFS function – prints each vertex in turn
  // prints order[] and from[]
  printf("\n\nvisiting order");
  for (int i = 0; i < G.nVertices; i++)
    printf("\nvertex %-3d: #%d", i, order[i]);
  printf("\n\nantecessors");
  for (int i = 0; i < G.nVertices; i++)
    printf("\nvertex %-3d: from vertex %d ", i, from[i]);
  return OK;
}

STATUS addVertexGraph_M(GRAPH_M *pG, int x) {

  pG->pD[pG->nVertices] = x;
  pG->nVertices++;

  return OK;
}

STATUS addEdgeGraph_M(GRAPH_M *pG, EDGE e, BOOLEAN bool) {
  int PosI = -1, PosJ = -1;

  for (int i = 0, j = 0; i < pG->nVertices; i++, j++) {
    if (e.v == pG->pD[i]) {
      PosI = i;
    }
    if (e.w == pG->pD[j]) {
      PosJ = j;
    }

    if (PosJ != -1 && PosI != -1) {
      printf("Encontrou %i- %i \n", PosI, PosJ);
      break;
    }
  }
  // Nao encontrou os nos

  if (PosJ == -1 || PosI == -1) {
    return ERROR;
  }

  pG->adjMatrix[PosI][PosJ] = e.weight;
  if (!bool)
    pG->adjMatrix[PosJ][PosI] = e.weight;

  return OK;
} // the BOOLEAN argunment is to indicate whether

int removeVertexGraph_M(GRAPH_M *graf, int vertice) {
  // para talremovemos o vertice e colocamos o ultimo no lugar do removido e
  // depois diminuimos o tamanho do nvertices
  int index = -1;
  for (int i = 0; i < graf->nVertices; i++) {
    if (graf->pD[i] == vertice) {
      index = i;
      graf->nVertices--;
      graf->pD[i] = graf->pD[graf->nVertices];
      graf->pD[graf->nVertices] = 0;
      break;
    }
  }

  if (index == -1) {
    printf("Vertice nao existe");
    return ERROR;
  }

  // temos de ajustar matriz de adjacencia com o pd novo
  for (int i = 0; i < graf->nVertices; i++) {
    graf->adjMatrix[index][i] = graf->adjMatrix[graf->nVertices][i];
    graf->adjMatrix[i][index] = graf->adjMatrix[i][graf->nVertices];
    graf->adjMatrix[i][graf->nVertices] = 0;
    graf->adjMatrix[graf->nVertices][i] = 0;
  }

  return OK;
}
