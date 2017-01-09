#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
	struct tagNode* Next;
} Node;

typedef struct tagLinkedListStack{
	Node* List;
	Node* Top;
} LinkedListStack;




void LLS_CreateStack( LinkedListStack** Stack );
void LLS_DestroyStack( LinkedListStack* _Stack );

Node* LLS_CreateNode( ElementType NewData );
void LLS_DestroyNode( Node* _Node );

void LLS_Push( LinkedListStack* Stack, Node* NewNode );
Node* LLS_Pop( LinkedListStack* Stack );
Node* LLS_Top( LinkedListStack* Stack );

int LLS_IsEmpty( LinkedListStack* Stack );
int LLS_GetSize( LinkedListStack* Stack );




void LLS_CreateStack( LinkedListStack** Stack ){
	*Stack = (LinkedListStack*)malloc( sizeof(LinkedListStack) );

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack( LinkedListStack* _Stack ){
	while( !LLS_IsEmpty(_Stack) ){
		Node* Popped = LLS_Pop( _Stack );
		LLS_DestroyNode( Popped );
	}

	free( _Stack );
}

Node* LLS_CreateNode( ElementType NewData ){
	Node* NewNode = (Node*)malloc( sizeof(Node) );

	NewNode->Data = NewData;
	NewNode->Next = NULL;

	return NewNode;
}

void LLS_DestroyNode( Node* _Node ){
	free( _Node );
}

void LLS_Push( LinkedListStack* Stack, Node* NewNode ){
	if( Stack->List == NULL ){
		Stack->List = NewNode;
	} else{
		Node* CursorNode = Stack->List;

		while( CursorNode->Next != NULL ){
			CursorNode = CursorNode->Next;
		}

		CursorNode->Next = NewNode;
	}

	Stack->Top = NewNode;
}

Node* LLS_Pop( LinkedListStack* Stack ){
	Node* Popped = Stack->Top;

	if( Stack->List == Stack->Top ){
		Stack->List = NULL;
		Stack->Top = NULL;
	} else{
		Node* CursorNode = Stack->List;

		while( CursorNode->Next != Stack->Top ){
			CursorNode = CursorNode->Next;
		}

		Stack->Top = CursorNode;
	}

	return Popped;
}

Node* LLS_Top( LinkedListStack* Stack ){
	return Stack->Top;
}

int LLS_IsEmpty( LinkedListStack* Stack ){
	return Stack->List == NULL;
}

int LLS_GetSize( LinkedListStack* Stack ){
	int Count = 0;
	Node* CursorNode = Stack->List;

	while( CursorNode != NULL ){
		CursorNode = CursorNode->Next;
		Count++;
	}

	return Count;
}




int Test_LinkedListStack( void ){
	int i = 0;
	int Count = 0;
	Node* Popped;

	LinkedListStack* Stack;

	LLS_CreateStack( &Stack );

	LLS_Push( Stack, LLS_CreateNode( "abc" ) );
	LLS_Push( Stack, LLS_CreateNode( "edf" ) );
	LLS_Push( Stack, LLS_CreateNode( "efg" ) );
	LLS_Push( Stack, LLS_CreateNode( "hij" ) );

	Count = LLS_GetSize( Stack );
	printf( "Size : %d, Top : %s\n\n", Count, LLS_Top( Stack )->Data );

	for( i=0; i<Count; i++ ){
		if( LLS_IsEmpty(Stack) ){
			break;
		}

		Popped = LLS_Pop( Stack );

		printf( "Popped : %s, ", Popped->Data );

		LLS_DestroyNode( Popped );

		if( !LLS_IsEmpty( Stack ) ){
			printf( "Current Top : %s\n", LLS_Top( Stack )->Data );
		} else {
			printf( "Stack Is Empty.\n" );
		}
	}

	LLS_DestroyStack( Stack );

	return 0;
}

//int main( void ){
//	Test_LinkedListStack();
//}
