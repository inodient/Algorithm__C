#include "../Graph/AdjacencyListGraph.h"
#include "../Queue/PriorityQueue.h"
#include "../Tree/DisjointSet.h"

#define MAX_WEIGHT 36267

void Prim( Graph* G, Vertex* StartVertex, Graph* MST );
void Kruskal( Graph* G, Graph* MST );




void Prim( Graph* G, Vertex* StartVertex, Graph* MST ){
	// Declaration
	int i=0;

	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	Vertex** MSTVertices = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );
	Vertex** Fringes = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );
	Vertex** Precedences = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );

	int* Weights = (int*)malloc( sizeof(int) * G->VertexCount );

	PriorityQueue* PQ = PQ_Create( 10 );

	// Initializing
	CurrentVertex = G->Vertices;
	while( CurrentVertex != NULL ){
		Vertex* NewVertex = CreateVertex( CurrentVertex->Data );
		AddVertex( MST, NewVertex );

		MSTVertices[i] = NewVertex;
		Fringes[i] = NULL;
		Precedences[i] = NULL;
		Weights[i] = MAX_WEIGHT;

		CurrentVertex = CurrentVertex->Next;
		i++;
	}

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

			if( Fringes[TargetVertex->Index] == NULL && Weights[TargetVertex->Index] > CurrentEdge->Weight ){
				PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
				PQ_Enqueue( PQ, NewNode );

				Precedences[TargetVertex->Index] = CurrentEdge->From;
				Weights[TargetVertex->Index] = CurrentEdge->Weight;
			}

			CurrentEdge  = CurrentEdge->Next;
		}
	}

	// Connecting
	for( i=0; i<G->VertexCount; i++ ){
		int FromIndex, ToIndex;

		if( Precedences[i] == NULL ) continue;

		FromIndex = Precedences[i]->Index;
		ToIndex = i;

		AddEdge( MSTVertices[FromIndex], CreateEdge( MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[ToIndex] ) );
		AddEdge( MSTVertices[ToIndex], CreateEdge( MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[ToIndex] ) );
	}

	// Destroying
	free( Fringes );
	free( Precedences );
	free( MSTVertices );
	free( Weights );

	PQ_Destroy( PQ );
}

void Kruskal( Graph* G, Graph* MST ){
	// Declaration
	int i=0;

	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	Vertex** MSTVertices = (Vertex**)malloc( sizeof(Vertex*) * G->VertexCount );
	DisjointSet** VertexSet = (DisjointSet**)malloc( sizeof(DisjointSet*) * G->VertexCount );

	PriorityQueue* PQ = PQ_Create( 10 );

	// Initialize
	CurrentVertex = G->Vertices;
	while( CurrentVertex != NULL ){
		MSTVertices[i] = CreateVertex( CurrentVertex->Data );
		VertexSet[i] = DS_MakeSet( CurrentVertex );
		AddVertex( MST, MSTVertices[i] );

		CurrentEdge = CurrentVertex->AdjacencyList;
		while( CurrentEdge != NULL ){
			PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };
			PQ_Enqueue( PQ, NewNode );

			CurrentEdge = CurrentEdge->Next;
		}

		CurrentVertex = CurrentVertex->Next;
		i++;
	}

	// Executing
	while( !PQ_IsEmpty(PQ) ){
		int FromIndex, ToIndex;

		PQNode Dequeued;
		PQ_Dequeue( PQ, &Dequeued );

		CurrentEdge = (Edge*)Dequeued.Data;

		FromIndex = CurrentEdge->From->Index;
		ToIndex = CurrentEdge->Target->Index;

		if( DS_FindSet( VertexSet[FromIndex] ) != DS_FindSet( VertexSet[ToIndex] ) ){
			AddEdge( MSTVertices[FromIndex], CreateEdge( MSTVertices[FromIndex], MSTVertices[ToIndex], CurrentEdge->Weight ) );
			AddEdge( MSTVertices[ToIndex], CreateEdge( MSTVertices[ToIndex], MSTVertices[FromIndex], CurrentEdge->Weight ) );

			DS_UnionSet( VertexSet[FromIndex], VertexSet[ToIndex] );
		}
	}

	// Destroying
	free( MSTVertices );
	free( VertexSet );

	PQ_Destroy( PQ );
}




int Test_MinimumSpanningTree( void ){
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

  AddEdge( A, CreateEdge( A, B, 35 ) );
  AddEdge( A, CreateEdge( A, E, 247 ) );

  AddEdge( B, CreateEdge( B, A, 35 ) );
  AddEdge( B, CreateEdge( B, C, 126 ) );
  AddEdge( B, CreateEdge( B, F, 150 ) );

  AddEdge( C, CreateEdge( C, B, 126 ) );
  AddEdge( C, CreateEdge( C, D, 117 ) );
  AddEdge( C, CreateEdge( C, F, 162 ) );
  AddEdge( C, CreateEdge( C, G, 220 ) );

  AddEdge( D, CreateEdge( D, C, 117 ) );

  AddEdge( E, CreateEdge( E, A, 247 ) );
  AddEdge( E, CreateEdge( E, F, 82 ) );
  AddEdge( E, CreateEdge( E, H, 98 ) );

  AddEdge( F, CreateEdge( F, B, 150 ) );
  AddEdge( F, CreateEdge( F, C, 162 ) );
  AddEdge( F, CreateEdge( F, E, 82 ) );
  AddEdge( F, CreateEdge( F, G, 154 ) );
  AddEdge( F, CreateEdge( F, H, 120 ) );

  AddEdge( G, CreateEdge( G, C, 220 ) );
  AddEdge( G, CreateEdge( G, F, 154 ) );
  AddEdge( G, CreateEdge( G, I, 106 ) );

  AddEdge( H, CreateEdge( H, E, 98 ) );
  AddEdge( H, CreateEdge( H, F, 120 ) );

  AddEdge( I, CreateEdge( I, G, 106 ) );

  printf( "Prim's Algorithm...\n" );
  Prim( graph, B, PrimMST );
  PrintGraph( PrimMST );

  printf( "Kruskal's Algorithm...\n" );
  Kruskal( graph, KruskalMST );
  PrintGraph( KruskalMST );

  DestroyGraph( PrimMST );
  DestroyGraph( KruskalMST );
  DestroyGraph( graph );

  return 0;
}

//int main( void ){
//	Test_MinimumSpanningTree();
//
//	return 0;
//}
