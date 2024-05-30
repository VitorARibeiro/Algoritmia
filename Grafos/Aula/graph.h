#ifndef _GRAPH_DEFINITIONS
#define _GRAPH_DEFINITIONS

//-------------------------------------------------------
#ifndef _LOGICAL
#define _LOGICAL
#define NMAX_VERTICE 20
typedef enum { ERROR = 0, OK = 1 } STATUS;
typedef enum { FALSE = 0, TRUE = 1 } BOOLEAN;
#endif // !_LOGICAL
//-------------------------------------------------------
// graph edge definition
typedef struct _EDGE {
  int v, w;
  float weight;
} EDGE;
//-------------------------------------------------------
// graph definitions
typedef struct _GRAPH_M {
  int nVertices;
  int nEdges;
  int *pD;
  float **adjMatrix;
} GRAPH_M;
//
// typedef struct _GRAPH_L {
//  int nVertices;
//  int nEdges;
//  int *pD;
//  LINKED_LIST **adjList;
//} GRAPH_L;
//-------------------------------------------------------
#ifndef _VERTICE_DATA_MACRO
#define _VERTICE_DATA_MACRO
// macro definition for easy access to a vertice data field
#define DATA_V(X) ((X)->pD)
#endif // !_DATA_MACRO
//-------------------------------------------------------
// Functions Declarations -------------------------------
// (only for adjacency matrix representation) -----------
//-------------------------------------------------------
// Constructors and Destructors -------------------------
STATUS initGraph_M(GRAPH_M *, int);
STATUS destroyGraph_M(GRAPH_M *);
// Input and Output -------------------------------------
EDGE setEdge(int, int, float);
STATUS addVertexGraph_M(GRAPH_M *, int);
STATUS addEdgeGraph_M(GRAPH_M *, EDGE,
                      BOOLEAN); // the BOOLEAN argunment is to indicate whether
// the graph is directed or not
int removeVertexGraph_M(GRAPH_M *, int);
EDGE removeEdgeGraph_M(GRAPH_M *);
// Query ------------------------------------------------
BOOLEAN emptyGraph_M(GRAPH_M G);
STATUS printAdjMatrix(GRAPH_M);
STATUS printVertices(GRAPH_M);
STATUS DFSTraverseGraph_M(GRAPH_M);
STATUS DFSGraph_M(GRAPH_M, EDGE, int *, int *, int *);
#endif // !_GRAPH_DEFINITIONS
