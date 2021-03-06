#include "GraphTraversal.h"

void DFS( Vertex* V );
void BFS( Vertex* V, LinkedQueue* Queue );



void DFS( Vertex* V ){
	Edge* E = NULL;

	printf( "%d ", V->Data );
	V->Visited = Visited;

	E = V->AdjacencyList;

	while( E != NULL ){
		if( E->Target != NULL && E->Target->Visited == NotVisited ){
			DFS( E->Target );
		}

		E = E->Next;
	}
}

void BFS( Vertex* V, LinkedQueue* Queue ){
	Edge* E = NULL;

	printf( "%d ", V->Data );
	V->Visited = Visited;

	LQ_Enqueue( Queue, LQ_CreateNode(V) );

	while( !LQ_IsEmpty(Queue) ){
		Node* Dequeued = LQ_Dequeue( Queue );

		V = Dequeued->Data;
		E = V->AdjacencyList;

		while( E != NULL ){
			if( E->Target != NULL && E->Target->Visited == NotVisited ){
				printf( "%d ", E->Target->Data );
				E->Target->Visited = Visited;
				LQ_Enqueue( Queue, LQ_CreateNode(E->Target) );
			}

			E = E->Next;
		}
	}
}




int Test_GraphTraversal( void ){
	int Mode = 0;
	Graph* graph = CreateGraph();

	Vertex* V1 = CreateVertex( 1 );
	Vertex* V2 = CreateVertex( 2 );
	Vertex* V3 = CreateVertex( 3 );
	Vertex* V4 = CreateVertex( 4 );
	Vertex* V5 = CreateVertex( 5 );
	Vertex* V6 = CreateVertex( 6 );
	Vertex* V7 = CreateVertex( 7 );

	AddVertex( graph, V1 );
	AddVertex( graph, V2 );
	AddVertex( graph, V3 );
	AddVertex( graph, V4 );
	AddVertex( graph, V5 );
	AddVertex( graph, V6 );
	AddVertex( graph, V7 );

	AddEdge( V1, CreateEdge( V1, V2, 0 ) );
	AddEdge( V1, CreateEdge( V1, V3, 0 ) );

	AddEdge( V2, CreateEdge( V2, V4, 0 ) );
	AddEdge( V2, CreateEdge( V2, V5, 0 ) );

	AddEdge( V3, CreateEdge( V3, V4, 0 ) );
	AddEdge( V3, CreateEdge( V3, V6, 0 ) );

	AddEdge( V4, CreateEdge( V4, V5, 0 ) );
	AddEdge( V4, CreateEdge( V4, V7, 0 ) );

	AddEdge( V5, CreateEdge( V5, V7, 0 ) );

	AddEdge( V6, CreateEdge( V6, V7, 0 ) );

	printf( "Enter Traversal Mode ( 0:DFS, 1:BFS ) : " );
	scanf( "%d", &Mode );

	if( Mode == 0 ){
		DFS( graph->Vertices );
	} else{
		LinkedQueue* Queue = NULL;
		LQ_CreateQueue( &Queue );

		BFS( V1, Queue );

		LQ_DestroyQueue( Queue );
	}

	DestroyGraph( graph );

	return 0;
}

//int main( void ){
//	Test_GraphTraversal();
//
//	return 0;
//}
