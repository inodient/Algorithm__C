#include "DoublyLinkedList.h"

Node* DLL_CreateNode( ElementType NewData ){
	Node* NewNode = (Node*)malloc( sizeof( Node ) );

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DLL_DestroyNode( Node* _Node ){
	free( _Node );
}

void DLL_AppendNode( Node** Head, Node* NewNode ){
	if( *Head == NULL ){
		*Head = NewNode;
	} else{
		Node* Tail = *Head;

		while( Tail->NextNode != NULL ){
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

void DLL_InsertAfter( Node* Current, Node* NewNode ){
	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;

	if( Current->NextNode != NULL ){
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

void DLL_RemoveNode( Node** Head, Node* Remove ){
	if( *Head == Remove ){
		*Head = Remove->NextNode;
	} else{
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;
	}

	Remove->PrevNode = NULL;
	Remove->NextNode = NULL;
}

Node* DLL_GetNodeAt( Node* Head, int Location ){
	Node* Current = Head;

	while( Current != NULL && (--Location) >= 0 ){
		Current = Current->NextNode;
	}

	return Current;
}

int DLL_GetNodeCount( Node* Head ){
	int Count = 0;
	Node* Current = Head;

	while( Current != NULL ){
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

void DLL_PrintList( Node* Head ){
	int Count = 0;
	Node* Current = Head;

	while( Current != NULL ){
		printf( "Data[%d] : %d\n", Count++, Current->Data );
		Current = Current->NextNode;
	}
}
