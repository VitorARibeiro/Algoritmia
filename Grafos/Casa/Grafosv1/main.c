#include "grafos.h"
#include <stdio.h>
int main() {

  GRAFO *grafo1 = CreateGrafo();
  EDGE *edge1 = CreateEdge(6, 7, 10.2);
  EDGE *edge4 = CreateEdge(6, 8, 10.2);
  EDGE *edge5 = CreateEdge(6, 10, 10.2);
  EDGE *edge2 = CreateEdge(8, 6, 13);
  EDGE *edge3 = CreateEdge(10, 6, 20);

  AddNode(grafo1, 5);
  AddNode(grafo1, 6);
  AddNode(grafo1, 7);
  AddNode(grafo1, 8);
  AddNode(grafo1, 10);

  AddLigacao(grafo1, edge1, 1);
  AddLigacao(grafo1, edge2, 0);
  AddLigacao(grafo1, edge3, 0);
  AddLigacao(grafo1, edge4, 0);
  AddLigacao(grafo1, edge5, 0);

  PrintNode(*grafo1);
  PrintMatrix(*grafo1);
  printf("\n\nO node 6 tem %i ligacoes", CountEdge(grafo1, 6));
  return 0;
}
