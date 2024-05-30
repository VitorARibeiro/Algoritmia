#include "graph.h"

int main() {

  GRAPH_M graf;
  EDGE femea = setEdge(10, 3, 7.3);
  EDGE femea2 = setEdge(10, 5, 6.3);
  initGraph_M(&graf, NMAX_VERTICE);
  addVertexGraph_M(&graf, 3);
  addVertexGraph_M(&graf, 5);
  addVertexGraph_M(&graf, 9);
  addVertexGraph_M(&graf, 10);
  addEdgeGraph_M(&graf, femea, TRUE);
  addEdgeGraph_M(&graf, femea2, TRUE);
  printVertices(graf);
  printAdjMatrix(graf);
  removeVertexGraph_M(&graf, 3);
  printVertices(graf);
  printAdjMatrix(graf);
  return 0;
}
