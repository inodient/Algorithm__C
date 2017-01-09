#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
	ElementType Data;
} Node;

typedef struct tagArrayStack{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;




void AS_CreateStack( ArrayStack** Stack, int Capacity );
void AS_DestroyStack( ArrayStack* _Stack );

void AS_Push( ArrayStack* Stack, ElementType NewData );
ElementType AS_Pop( ArrayStack* Stack );
ElementType AS_Top( ArrayStack* Stack );

int AS_IsEmpty( ArrayStack* Stack );
int AS_IsFull( ArrayStack* Stack );
int AS_GetSize( ArrayStack* Stack );




void AS_CreateStack( ArrayStack** Stack, int Capacity ){
	*Stack = (ArrayStack*)malloc( sizeof(ArrayStack) );

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
	(*Stack)->Nodes = (Node*)malloc( sizeof(Node) * (*Stack)->Capacity );
}

void AS_DestroyStack( ArrayStack* _Stack ){
	free( _Stack->Nodes );
	free( _Stack );
}

void AS_Push( ArrayStack* Stack, ElementType NewData ){
	int Position = Stack->Top++;

	Stack->Nodes[Position].Data = NewData;
}

ElementType AS_Pop( ArrayStack* Stack ){
	int Position = --Stack->Top;

	return Stack->Nodes[Position].Data;
}

ElementType AS_Top( ArrayStack* Stack ){
	int Position = Stack->Top - 1;

	return Stack->Nodes[Position].Data;
}

int AS_IsEmpty( ArrayStack* Stack ){
	return Stack->Top == 0;
}

int AS_IsFull( ArrayStack* Stack ){
	return Stack->Capacity == Stack->Top;
}

int AS_GetSize( ArrayStack* Stack ){
	return Stack->Top;
}




int Test_ArrayStack( void ){
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack( &Stack, 10 );

	AS_Push( Stack, 3 );
	AS_Push( Stack, 37 );
	AS_Push( Stack, 11 );
	AS_Push( Stack, 12 );

	printf( "Capacity : %d, Size : %d, Top : %d\n\n",
			Stack->Capacity, AS_GetSize( Stack ), AS_Top( Stack ) );

	for( i=0; i<4; i++ ){
		if( AS_IsEmpty( Stack ) ){
			break;
		}

		printf( "Popped : %d, ", AS_Pop(Stack) );

		if( !AS_IsEmpty( Stack ) ){
			printf( "Current Top : %d\n", AS_Top( Stack ) );
		} else {
			printf( "Stack Is Empty.\n" );
		}
	}

	AS_DestroyStack( Stack );

	return 0 ;
}

//int main( void ){
//	Test_ArrayStack();
//	return 0;
//}
