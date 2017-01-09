#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int ElementType;

typedef struct tagHeapNode{
	ElementType Data;
} HeapNode;

typedef struct Heap{
	int Capacity;
	int UsedSize;
	HeapNode* Nodes;
} Heap;




Heap* HEAP_CreateHeap( int Capacity );
void HEAP_DestroyHeap( Heap* _H );

int HEAP_GetParentIndex( int Index );
int HEAP_GetLeftChildIndex( int Index );

void HEAP_SwapNodes( Heap* H, int Index1, int Index2 );

void HEAP_Insert( Heap* H, ElementType NewData );
void HEAP_DeleteMin( Heap* H, HeapNode* Root );

void HEAP_PrintNodes( Heap* H );




Heap* HEAP_CreateHeap( int Capacity ){
	Heap* NewHeap = (Heap*)malloc( sizeof(Heap) );
	
	NewHeap->Capacity = Capacity;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc( sizeof(Heap) * Capacity );
	
	return NewHeap;
}

void HEAP_DestroyHeap( Heap* _H ){
	free( _H->Nodes );
	free( _H );
}

int HEAP_GetParentIndex( int Index ){
	return (int)( (Index-1) / 2 );
}

int HEAP_GetLeftChildIndex( int Index ){
	return ( Index * 2 ) + 1;
}

void HEAP_SwapNodes( Heap* H, int Index1, int Index2 ){
	HeapNode* Temp = (HeapNode*)malloc( sizeof(HeapNode) );

	memcpy( Temp, &(H->Nodes[Index1]), sizeof(HeapNode) );
	memcpy( &(H->Nodes[Index1]), &(H->Nodes[Index2]), sizeof(HeapNode) );
	memcpy( &(H->Nodes[Index2]), Temp, sizeof(HeapNode) );

	free( Temp );
}

void HEAP_Insert( Heap* H, ElementType NewData ){
	int CurrentIndex = 0;
	int ParentIndex = 0;

	if( H->UsedSize == H->Capacity ){
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc( H->Nodes, sizeof(HeapNode) * H->Capacity );
	}
	
	H->Nodes[H->UsedSize].Data = NewData;

	CurrentIndex = H->UsedSize;
	ParentIndex = HEAP_GetParentIndex( CurrentIndex );
	
	while( CurrentIndex > 0 && H->Nodes[CurrentIndex].Data < H->Nodes[ParentIndex].Data ){
		HEAP_SwapNodes( H, CurrentIndex, ParentIndex );
		
		CurrentIndex = ParentIndex;
		ParentIndex = HEAP_GetParentIndex( CurrentIndex );
	}
	
	H->UsedSize++;
}

void HEAP_DeleteMin( Heap* H, HeapNode* Root ){
	memcpy( Root, &(H->Nodes[0]), sizeof(HeapNode) );
	memset( &(H->Nodes[0]), 0, sizeof(HeapNode) );
	
	H->UsedSize--;
	HEAP_SwapNodes( H, 0, H->UsedSize );
	
	int ParentIndex = 0;
	int LeftChildIndex = 0;
	int RightChildIndex = 0;

	LeftChildIndex = HEAP_GetLeftChildIndex( ParentIndex );
	RightChildIndex = LeftChildIndex + 1;
	
	while( 1 ){
		int SelectedIndex = 0;

		if( LeftChildIndex >= H->UsedSize ) break;
		
		if( RightChildIndex >= H->UsedSize ){
			SelectedIndex = LeftChildIndex;
		} else{
			if( H->Nodes[LeftChildIndex].Data > H->Nodes[RightChildIndex].Data ){
				SelectedIndex = RightChildIndex;
			} else{
				SelectedIndex = LeftChildIndex;
			}
		}

		if( H->Nodes[SelectedIndex].Data < H->Nodes[ParentIndex].Data ){
			HEAP_SwapNodes( H, SelectedIndex, ParentIndex );

			ParentIndex = SelectedIndex;
			LeftChildIndex = HEAP_GetLeftChildIndex( ParentIndex );
			RightChildIndex = LeftChildIndex + 1;
		} else{
			break;
		}
	}

	if( H->UsedSize < H->Capacity / 2 ){
		H->Capacity /= 2;
		H->Nodes = (HeapNode*)realloc( H->Nodes, sizeof(HeapNode) * H->Capacity );
	}
}

void HEAP_PrintNodes( Heap* H ){
	int i=0;
	for( i=0; i<H->UsedSize; i++ ){
		printf( "%d ", H->Nodes[i].Data );
	}

	printf( "\n" );
}




int Test_Heap( void ){
	Heap* H = HEAP_CreateHeap( 3 );
	HeapNode MinNode;

	HEAP_Insert( H, 12 );
	HEAP_Insert( H, 87 );
	HEAP_Insert( H, 111 );
	HEAP_Insert( H, 34 );
	HEAP_Insert( H, 16 );
	HEAP_Insert( H, 75 );
	HEAP_PrintNodes( H );

	HEAP_DeleteMin( H, &MinNode );
	HEAP_PrintNodes( H );

	HEAP_DeleteMin( H, &MinNode );
	HEAP_PrintNodes( H );

	HEAP_DeleteMin( H, &MinNode );
	HEAP_PrintNodes( H );

	HEAP_DeleteMin( H, &MinNode );
	HEAP_PrintNodes( H );

	HEAP_DeleteMin( H, &MinNode );
	HEAP_PrintNodes( H );

	HEAP_DeleteMin( H, &MinNode );
	HEAP_PrintNodes( H );

	HEAP_DestroyHeap( H );

	return 0;
}

//int main( void ){
//	Test_Heap();
//	return 0;
//}
