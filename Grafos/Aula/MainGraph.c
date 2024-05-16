#include "graph.h"

int main() {

  GRAPH_M graf;
  EDGE femea = setEdge(10, 3, 7.3);

  initGraph_M(&graf, NMAX_VERTICES);
  addVertexGraph_M(&graf, 3);
  addVertexGraph_M(&graf, 5);
  addVertexGraph_M(&graf, 9);
  addVertexGraph_M(&graf, 10);
  addEdgeGraph_M(&graf, femea, TRUE);
  printVertices(graf);
  return 0;
}
