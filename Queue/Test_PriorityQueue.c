#include "PriorityQueue.h"

int main( void ){
	PriorityQueue* PQ = PQ_Create( 3 );
	PQNode Popped;
	
	PQNode Nodes[7] = {
		{34, (void*)"Coding"},
		{12, (void*)"Client Meeting"},
		{87, (void*)"Prepare Coffee"},
		{45, (void*)"Documentation"},
		{35, (void*)"Debugging"},
		{66, (void*)"Clean Tooth"}
	};
	
	PQ_Enqueue( PQ, Nodes[0] );
	PQ_Enqueue( PQ, Nodes[1] );
	PQ_Enqueue( PQ, Nodes[2] );
	PQ_Enqueue( PQ, Nodes[3] );
	PQ_Enqueue( PQ, Nodes[4] );
	PQ_Enqueue( PQ, Nodes[5] );
	
	printf( "Remaining Tasks Count : %d\n", PQ->UsedSize );
	
	while( !PQ_IsEmpty( PQ ) ){
		PQ_Dequeue( PQ, &Popped );
		PQ_PrintNode( &Popped );
	}
	
	return 0;
}
