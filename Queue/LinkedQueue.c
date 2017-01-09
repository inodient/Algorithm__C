#include <stdio.h>
#include <stdlib.h>

typedef char* ElementType;

typedef struct tagNode{
	ElementType Data;
	struct tagNode* Next;
} Node;

typedef struct tagLinkedQueue{
	Node* Front;
	Node* Rear;
} LinkedQueue;




void LQ_CreateQueue( LinkedQueue** Queue );
void LQ_DestroyQueue( LinkedQueue* _Queue );

Node* LQ_CreateNode( ElementType NewData );
void LQ_DestroyNode( Node* _Node );

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode );
Node* LQ_Dequeue( LinkedQueue* Queue );

int LQ_IsEmpty( LinkedQueue* Queue );
int LQ_GetSize( LinkedQueue* Queue );




void LQ_CreateQueue( LinkedQueue** Queue ){
	*Queue = (LinkedQueue*)malloc( sizeof(LinkedQueue) );

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
}

void LQ_DestroyQueue( LinkedQueue* _Queue ){
	while( !LQ_IsEmpty(_Queue) ){
		Node* Dequeued = LQ_Dequeue( _Queue );
		LQ_DestroyNode( Dequeued );
	}

	free( _Queue );
}

Node* LQ_CreateNode( ElementType NewData ){
	Node* NewNode = (Node*)malloc( sizeof(Node) );

	NewNode->Data = NewData;
	NewNode->Next = NULL;

	return NewNode;
}

void LQ_DestroyNode( Node* _Node ){
	free( _Node );
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode ){
	if( Queue->Front == NULL ){
		Queue->Front = NewNode;
	} else{
		Node* CursorNode = Queue->Front;

		while( CursorNode->Next != NULL ){
			CursorNode = CursorNode->Next;
		}

		CursorNode->Next = NewNode;
	}

	Queue->Rear = NewNode;
}

Node* LQ_Dequeue( LinkedQueue* Queue ){
	Node* Dequeued = Queue->Front;

	if( Queue->Front == Queue->Rear ){
		Queue->Front = NULL;
		Queue->Rear = NULL;
	} else{
		Queue->Front = Queue->Front->Next;
	}

	return Dequeued;
}

int LQ_IsEmpty( LinkedQueue* Queue ){
	return Queue->Front == NULL;
}

int LQ_GetSize( LinkedQueue* Queue ){
	int Count = 0;
	Node* CursorNode = Queue->Front;

	while( CursorNode != NULL ){
		CursorNode = CursorNode->Next;
		Count++;
	}

	return Count;
}




int Test_LinkedQueue( void ){
	Node* Dequeued;
	LinkedQueue* Queue;

	LQ_CreateQueue( &Queue );

	LQ_Enqueue( Queue, LQ_CreateNode( "abc" ) );
	LQ_Enqueue( Queue, LQ_CreateNode( "def" ) );
	LQ_Enqueue( Queue, LQ_CreateNode( "efg" ) );
	LQ_Enqueue( Queue, LQ_CreateNode( "hij" ) );

	printf( "Queue Size : %d\n", LQ_GetSize(Queue) );

	while( LQ_IsEmpty( Queue ) == 0 ){
		Dequeued = LQ_Dequeue( Queue );
		printf( "Dequeue : %s \n", Dequeued->Data );
		LQ_DestroyNode( Dequeued );
	}

	LQ_DestroyQueue( Queue );

	return 0;
}

//int main( void ){
//	Test_LinkedQueue();
//	return 0;
//}
