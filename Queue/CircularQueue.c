#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
} Node;

typedef struct tagCircularQueue{
	int Capacity;
	int Front;
	int Rear;
	Node* Nodes;
} CircularQueue;




void CQ_CreateQueue( CircularQueue** Queue, int Capacity );
void CQ_DestroyQueue( CircularQueue* _Queue );

void CQ_Enqueue( CircularQueue* Queue, ElementType NewData );
ElementType CQ_Dequeue( CircularQueue* Queue );

int CQ_IsEmpty( CircularQueue* Queue );
int CQ_IsFull( CircularQueue* Queue );
int CQ_GetSize( CircularQueue* Queue );




void CQ_CreateQueue( CircularQueue** Queue, int Capacity ){
	*Queue = (CircularQueue*)malloc( sizeof(CircularQueue) );

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
	(*Queue)->Nodes = (Node*)malloc( sizeof(Node) * (Capacity + 1) );
}

void CQ_DestroyQueue( CircularQueue* _Queue ){
	free( _Queue->Nodes );
	free( _Queue );
}

void CQ_Enqueue( CircularQueue* Queue, ElementType NewData ){
	int Position = 0;

	if( Queue->Rear == Queue->Capacity ){
		Queue->Rear = 0;
		Position = Queue->Capacity;
	} else{
		Position = Queue->Rear++;
	}

	Queue->Nodes[Position].Data = NewData;
}

ElementType CQ_Dequeue( CircularQueue* Queue ){
	int Position = Queue->Front;

	if( Queue->Front == Queue->Capacity ){
		Queue->Front = 0;
	} else{
		Queue->Front++;
	}

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty( CircularQueue* Queue ){
	return Queue->Front == Queue->Rear;
}

int CQ_IsFull( CircularQueue* Queue ){
	if( Queue->Front <= Queue->Rear ){
		return Queue->Rear - Queue->Front == Queue->Capacity;
	} else{
		return Queue->Rear + ( Queue->Capacity - Queue->Front + 1 ) == Queue->Capacity;
	}
}

int CQ_GetSize( CircularQueue* Queue ){
	if( Queue->Front <= Queue->Rear ){
		return Queue->Rear - Queue->Front;
	} else{
		return Queue->Rear + ( Queue->Capacity - Queue->Front + 1 );
	}
}




int Test_CircularQueue( void ){
	int i;
	CircularQueue* Queue;

	CQ_CreateQueue( &Queue, 10 );

	CQ_Enqueue( Queue, 1 );
	CQ_Enqueue( Queue, 2 );
	CQ_Enqueue( Queue, 3 );
	CQ_Enqueue( Queue, 4 );

	for( i=0; i<3; i++ ){
		printf( "Dequeue : %d, ", CQ_Dequeue( Queue ) );
		printf( "Front : %d, Rear : %d\n", Queue->Front, Queue->Rear );
	}

	i = 100;
	while( !CQ_IsFull( Queue ) ){
		CQ_Enqueue( Queue, i++ );
	}

	printf( "Capacity : %d, Size : %d\n", Queue->Capacity, CQ_GetSize( Queue ) );

	while( !CQ_IsEmpty( Queue ) ){
		printf( "Dequeue : %d, ", CQ_Dequeue( Queue ) );
		printf( "Front : %d, Rear : %d\n", Queue->Front, Queue->Rear );
	}

	CQ_DestroyQueue( Queue );

	return 0;
}

//int main( void ){
//	Test_CircularQueue();
//}
