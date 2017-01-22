#include "../Graph/AdjacencyListGraph.h"
#include "../Queue/PriorityQueue.h"

#define MAX_WEIGHT 36267

void Dijkstra( Graph* G, Vertex* StartVertex, Graph* ShortestPath );




void Dijkstra( Graph* G, Vertex* StartVertex, Graph* ShortestPath ){
	// Declaration
	int i=0;

	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	Vertex** ShortestPathVertices = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );
	Vertex** Fringes = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );
	Vertex** Precedences = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );

	int* Weights = (int*)malloc( sizeof(int) * G->VertexCount );

	PriorityQueue* PQ = PQ_Create( 10 );

	// Initializing
	CurrentVertex = G->Vertices;
	while( CurrentVertex != NULL ){
		Vertex* NewVertex = CreateVertex( CurrentVertex->Data );
		AddVertex( ShortestPath, NewVertex );

		ShortestPathVertices[i] = NewVertex;
		Fringes[i] = NULL;
		Precedences[i] = NULL;

		Weights[i] = MAX_WEIGHT;

		CurrentVertex = CurrentVertex->Next;
		i++;
	}

	Weights[StartVertex->Index] = 0;

	// Initial Queueing
	PQNode StartNode = { 0, StartVertex };
	PQ_Enqueue( PQ, StartNode );


	// Executing
	while( !PQ_IsEmpty(PQ) ){
		PQNode Dequeued;
		PQ_Dequeue( PQ, &Dequeued );

		CurrentVertex = (Vertex*)Dequeued.Data;

		Fringes[CurrentVertex->Index] = CurrentVertex;

		CurrentEdge = CurrentVertex->AdjacencyList;
		while( CurrentEdge != NULL ){
			Vertex* TargetVertex = CurrentEdge->Target;

			if( Fringes[TargetVertex->Index] == NULL && Weights[CurrentVertex->Index] + CurrentEdge->Weight < Weights[TargetVertex->Index] ){
				PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
				PQ_Enqueue( PQ, NewNode );

				Precedences[TargetVertex->Index] = CurrentEdge->From;
				Weights[TargetVertex->Index] = Weights[CurrentVertex->Index] + CurrentEdge->Weight;
			}

			CurrentEdge = CurrentEdge->Next;
		}
	}

	// Connecting
	for( i=0; i<G->VertexCount; i++ ){
		int FromIndex, ToIndex;

		if( Precedences[i] == NULL ) continue;

		FromIndex = Precedences[i]->Index;
		ToIndex = i;

		AddEdge( ShortestPathVertices[FromIndex], CreateEdge( ShortestPathVertices[FromIndex], ShortestPathVertices[ToIndex], Weights[ToIndex] ) );
	}

	// Destroying
	free( ShortestPathVertices );
	free( Fringes );
	free( Precedences );
	free( Weights );

	PQ_Destroy( PQ );
}




int Test_ShortestPath( void ){
  Graph* graph = CreateGraph();
  Graph* PrimMST = CreateGraph();
  Graph* KruskalMST = CreateGraph();

  Vertex* A = CreateVertex( 'A' );
  Vertex* B = CreateVertex( 'B' );
  Vertex* C = CreateVertex( 'C' );
  Vertex* D = CreateVertex( 'D' );
  Vertex* E = CreateVertex( 'E' );
  Vertex* F = CreateVertex( 'F' );
  Vertex* G = CreateVertex( 'G' );
  Vertex* H = CreateVertex( 'H' );
  Vertex* I = CreateVertex( 'I' );

  AddVertex( graph, A );
  AddVertex( graph, B );
  AddVertex( graph, C );
  AddVertex( graph, D );
  AddVertex( graph, E );
  AddVertex( graph, F );
  AddVertex( graph, G );
  AddVertex( graph, H );
  AddVertex( graph, I );

  AddEdge( A, CreateEdge( A, E, 247 ) );

  AddEdge( B, CreateEdge( B, A, 35 ) );
  AddEdge( B, CreateEdge( B, C, 126 ) );
  AddEdge( B, CreateEdge( B, F, 150 ) );

  AddEdge( C, CreateEdge( C, D, 117 ) );
  AddEdge( C, CreateEdge( C, F, 162 ) );
  AddEdge( C, CreateEdge( C, G, 220 ) );

  AddEdge( E, CreateEdge( E, H, 98 ) );

  AddEdge( F, CreateEdge( F, E, 82 ) );
  AddEdge( F, CreateEdge( F, G, 154 ) );
  AddEdge( F, CreateEdge( F, H, 120 ) );

  AddEdge( G, CreateEdge( G, I, 106 ) );

  printf( "Dijstra's Algorithm...\n" );
  Dijkstra( graph, B, PrimMST );
  PrintGraph( PrimMST );

  DestroyGraph( PrimMST );
  DestroyGraph( KruskalMST );
  DestroyGraph( graph );

  return 0;
}

int main( void ){
  Test_ShortestPath();

  return 0;
}
