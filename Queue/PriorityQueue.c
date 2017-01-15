#include "PriorityQueue.h"

PriorityQueue* PQ_Create( int InitialSize ){
	PriorityQueue* NewPQ = (PriorityQueue*)malloc( sizeof( PriorityQueue ) );
	NewPQ->Capacity = InitialSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = (PQNode*)malloc( sizeof( PQNode ) * NewPQ->Capacity );
	
	return NewPQ;
}

void PQ_Destroy( PriorityQueue* _PQ ){
	free( _PQ->Nodes );
	free( _PQ );
}

void PQ_Enqueue( PriorityQueue* PQ, PQNode NewNode ){
	int CurrentPosition = PQ->UsedSize;
	int ParentPosition = PQ_GetParent( CurrentPosition );
	
	if( PQ->UsedSize == PQ->Capacity ){
		if( PQ->Capacity == 0 ){
			PQ->Capacity = 1;
		}
		
		PQ->Capacity *= 2;
		PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
	}
	
	PQ->Nodes[CurrentPosition] = NewNode;
	
	while( CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority ){
		PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );
		
		CurrentPosition = ParentPosition;
		ParentPosition = PQ_GetParent( CurrentPosition );
	}
	
	PQ->UsedSize++;
}

void PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 ){
	int CopySize = sizeof( PQNode );
	PQNode* Temp = (PQNode*)malloc( CopySize );
	
	memcpy( Temp, &PQ->Nodes[Index1], CopySize );
	memcpy( &PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize );
	memcpy( &PQ->Nodes[Index2], Temp, CopySize );
	
	free( Temp );
}

void PQ_Dequeue( PriorityQueue* PQ, PQNode* Root ){
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;
	
	memcpy( Root, &PQ->Nodes[0], sizeof( PQNode ) );
	memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );
	
	PQ->UsedSize--;
	PQ_SwapNodes( PQ, 0, PQ->UsedSize );
	
	LeftPosition = PQ_GetLeftChild( 0 );
	RightPosition = LeftPosition + 1;
	
	while( 1 ){
		int SelectedChild = 0;
		
		if( LeftPosition >= PQ->UsedSize ){
			break;
		}
		
		if( RightPosition >= PQ->UsedSize ){
			SelectedChild = LeftPosition;
		} else{
			if( PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority ){
				SelectedChild = RightPosition;
			} else{
				SelectedChild = LeftPosition;
			}
		}
		
		if( PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority ){
			PQ_SwapNodes( PQ, ParentPosition, SelectedChild );
			ParentPosition = SelectedChild;
		} else{
			break;
		}
		
		LeftPosition = PQ_GetLeftChild( ParentPosition );
		RightPosition = LeftPosition + 1;
	}
	
	if( PQ->UsedSize < ( PQ->Capacity / 2 ) ){
		PQ->Capacity /= 2;
		PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
	}
}

int PQ_GetParent( int Index ){
	return (int)( ( Index - 1 ) / 2 );
}

int PQ_GetLeftChild( int Index ){
	return ( 2 * Index ) + 1;
}

int PQ_IsEmpty( PriorityQueue* PQ ){
	return ( PQ->UsedSize == 0 );
}

void PQ_PrintNode( PQNode* Node ){
	printf( "Task : %s (Priority : %d)\n", (char*)Node->Data, Node->Priority );
}




int Test_PriorityQueue( void ){
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
