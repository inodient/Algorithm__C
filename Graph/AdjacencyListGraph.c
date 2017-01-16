#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

typedef struct tagVertex{
	ElementType Data;
	int Index;
	int Visited;
	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
} Vertex;

typedef struct tagEdge{
	int Weight;
	struct tagVertex* From;
	struct tagVertex* Target;
	struct tagEdge* Next;
} Edge;

typedef struct tagGraph{
	struct tagVertex* Vertices;
	int VertexCount;
} Graph;




Graph* CreateGrpah();
void DestroyGraph( Graph* _G );

Vertex* CreateVertex( ElementType NewData );
void DestroyVertex( Vertex* _V );

Edge* CreateEdge( Vertex* From, Vertex* Target, int Weight );
void DestroyEdge( Edge* _E );

void AddVertex( Graph* G, Vertex* V );
void AddEdge( Vertex* V, Edge* E );

void PrintGraph( Graph* G );




Graph* CreateGraph(){
	Graph* NewGraph = (Graph*)malloc( sizeof(Graph) );

	NewGraph->Vertices = NULL;
	NewGraph->VertexCount = 0;

	return NewGraph;
}

void DestroyGraph( Graph* _G ){
	while( _G->Vertices != NULL ){
		Vertex* NextVertex = _G->Vertices->Next;
		DestroyVertex( _G->Vertices );
		_G->Vertices = NextVertex;
	}

	free( _G );
}

Vertex* CreateVertex( ElementType NewData ){
	Vertex* NewVertex = (Vertex*)malloc( sizeof(Vertex) );

	NewVertex->Data = NewData;
	NewVertex->Index = -1;
	NewVertex->Visited = NotVisited;
	NewVertex->Next = NULL;
	NewVertex->AdjacencyList = NULL;

	return NewVertex;
}

void DestroyVertex( Vertex* _V ){
	while( _V->AdjacencyList != NULL ){
		Edge* NextEdge = _V->AdjacencyList->Next;
		DestroyEdge( _V->AdjacencyList );
		_V->AdjacencyList = NextEdge;
	}

	free( _V );
}

Edge* CreateEdge( Vertex* From, Vertex* Target, int Weight ){
	Edge* NewEdge = (Edge*)malloc( sizeof(Edge) );

	NewEdge->Weight = Weight;
	NewEdge->From = From;
	NewEdge->Target = Target;
	NewEdge->Next = NULL;

	return NewEdge;
}

void DestroyEdge( Edge* _E ){
	free( _E );
}

void AddVertex( Graph* G, Vertex* V ){
	if( G->Vertices == NULL ){
		G->Vertices = V;
	} else{
		Vertex* CursorVertex = G->Vertices;

		while( CursorVertex->Next != NULL ){
			CursorVertex = CursorVertex->Next;
		}

		CursorVertex->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge( Vertex* V, Edge* E ){
	if( V->AdjacencyList == NULL ){
		V->AdjacencyList = E;
	} else{
		Edge* CursorEdge = V->AdjacencyList;

		while( CursorEdge->Next != NULL ){
			CursorEdge = CursorEdge->Next;
		}

		CursorEdge->Next = E;
	}
}

void PrintGraph( Graph* G ){
	Vertex* V = NULL;
	Edge* E = NULL;

	if( (V = G->Vertices) == NULL ) return;

	while( V != NULL ){
		printf( "%c : ", V->Data );

		if( (E = V->AdjacencyList) == NULL ){
			printf( "\n" );
			V = V->Next;
			continue;
		}

		while( E != NULL ){
			printf( "%c[%d] : ", E->Target->Data, E->Weight );
			E = E->Next;
		}

		printf( "\n" );

		V = V->Next;
	}

	printf( "\n" );
}




int Test_AdjacencyList( void ){
	Graph* G = CreateGraph();

	Vertex* V1 = CreateVertex( '1' );
	Vertex* V2 = CreateVertex( '2' );
	Vertex* V3 = CreateVertex( '3' );
	Vertex* V4 = CreateVertex( '4' );
	Vertex* V5 = CreateVertex( '5' );

	AddVertex( G, V1 );
	AddVertex( G, V2 );
	AddVertex( G, V3 );
	AddVertex( G, V4 );
	AddVertex( G, V5 );

	AddEdge( V1, CreateEdge( V1, V2, 0 ) );
	AddEdge( V1, CreateEdge( V1, V3, 0 ) );
	AddEdge( V1, CreateEdge( V1, V4, 0 ) );
	AddEdge( V1, CreateEdge( V1, V5, 0 ) );

	PrintGraph( G );

	DestroyGraph( G );

	return 0;
}

int main( void ){
	Test_AdjacencyList();

	return 0;
}
