#include "LinkedQueue.h"

int Test_LinkedQueue(){
	Node* Dequeued;
	LinkedQueue* Queue;

	LQ_CreateQueue( &Queue );

	LQ_Enqueue( Queue, LQ_CreateNode( "abc" ) );
	LQ_Enqueue( Queue, LQ_CreateNode( "def" ) );
	LQ_Enqueue( Queue, LQ_CreateNode( "efg" ) );
	LQ_Enqueue( Queue, LQ_CreateNode( "hij" ) );

	printf( "Queue Size : %d\n", Queue->Count );

	while( LQ_IsEmpty( Queue ) == 0 ){
		Dequeued = LQ_Dequeue( Queue );
		printf( "Dequeue : %s \n", Dequeued->Data );
		LQ_DestroyNode( Dequeued );
	}

	LQ_DestroyQueue( Queue );

	return 0;
}

