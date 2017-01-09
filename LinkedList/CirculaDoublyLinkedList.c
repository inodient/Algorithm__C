#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode( ElementType NewData ){
	Node* NewNode = (Node*)malloc( sizeof( Node ) );

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void CDLL_DestroyNode( Node* _Node ){
	free( _Node );
}

void CDLL_AppendNode( Node** Head, Node* NewNode ){
	if( *Head == NULL ){
		*Head = NewNode;
		(*Head)->PrevNode = NewNode;
		(*Head)->NextNode = NewNode;
	} else{
		Node* Tail = (*Head)->PrevNode;

		NewNode->PrevNode = Tail;
		NewNode->NextNode = *Head;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;
	}
}

void CDLL_InsertAfter( Node* Current, Node* NewNode ){
	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}

void CDLL_RemoveNode( Node** Head, Node* Remove ){
	if( *Head == Remove ){
		(*Head)->NextNode->PrevNode = Remove->PrevNode;
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		*Head = Remove->NextNode;
	} else{
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;
	}

	Remove->PrevNode = NULL;
	Remove->NextNode = NULL;
}

Node* CDLL_GetNodeAt( Node* Head, int Location ){
	Node* Current = Head;

	while( Current != NULL && (--Location) >= 0 ){
		Current = Current->NextNode;
	}

	return Current;
}

int CDLL_GetNodeCount( Node* Head ){
	int Count = 0;
	Node* Current = Head;

	while( Current != NULL ){
		Current = Current->NextNode;
		Count++;

		if( Current == Head ){
			break;
		}
	}

	return Count;
}

void CDLL_PrintNode( Node* _Node ){
	if( _Node->PrevNode == NULL ){
		printf( "Prev : NULL" );
	} else{
		printf( "Prev : %d", _Node->PrevNode->Data );
	}

	printf( "	Current : %d	", _Node->Data );

	if( _Node->NextNode == NULL ){
		printf( "Next : NULL" );
	} else{
		printf( "Next : %d", _Node->NextNode->Data );
	}
}

void CDLL_PrintList( Node* Head ){
	int Count = 0;
	Node* Current = Head;

	while( Current != NULL ){
		printf( "Data[%d] : %d\n", Count++, Current->Data );
		Current = Current->NextNode;

		if( Current == Head ){
			break;
		}
	}
}
