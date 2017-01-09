#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap( int* A, int* B ){
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

void BubbleSort( int DataSet[], int Length ){
	int i = 0, j = 0;

	for( i=0; i<Length-1; i++ ){
		for( j=0; j<Length-(i+1); j++ ){
			if( DataSet[j] > DataSet[j+1] ){
				Swap( &DataSet[j], &DataSet[j+1] );
			}
		}
	}
}
void InsertionSort( int DataSet[], int Length ){
	int i = 0, j = 0, Value = 0;

	for( i=1; i<Length; i++ ){
		if( DataSet[i-1] < DataSet[i] )
			continue;

		Value = DataSet[i];

		for( j=0; j<i; j++ ){
			if( DataSet[j] > Value ){
				memmove( &DataSet[j+1], &DataSet[j], sizeof( DataSet[0] ) * (i-j) );
				DataSet[j] = Value;
				break;
			}
		}
	}
}

int Partition( int DataSet[], int Left, int Right ){
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while( Left <= Right ){
		while( DataSet[Left] <= Pivot && Left < Right ){
			++Left;
		}
		while( DataSet[Right] > Pivot && Left <= Right ){
			--Right;
		}

		if( Left < Right ){
			Swap( &DataSet[Left], &DataSet[Right] );
		} else{
			break;
		}
	}

	Swap( &DataSet[First], &DataSet[Right] );

	return Right;
}

void QuickSort( int DataSet[], int Left, int Right ){
	if( Left < Right ){
		int Index = Partition( DataSet, Left, Right );

		QuickSort( DataSet, Left, Index - 1 );
		QuickSort( DataSet, Index + 1, Right );
	}
}



void Merge( int DataSet[], int StartIndex, int MiddleIndex, int EndIndex ){
	int i;
	int LeftIndex = StartIndex;
	int RightIndex = MiddleIndex + 1;
	int DestIndex = 0;

	int* Destination = (int*)malloc( sizeof(int) * (EndIndex - StartIndex + 1) );

	while( LeftIndex <= MiddleIndex && RightIndex <= EndIndex ){
		if( DataSet[LeftIndex] < DataSet[RightIndex] ){
			Destination[DestIndex] = DataSet[LeftIndex];
			LeftIndex++;
		} else {
			Destination[DestIndex] = DataSet[RightIndex];
			RightIndex++;
		}
		DestIndex++;
	}

	while( LeftIndex <= MiddleIndex ){
		Destination[DestIndex++] = DataSet[LeftIndex++];
	}
	while( RightIndex <= EndIndex ){
		Destination[DestIndex++] = DataSet[RightIndex++];
	}

	DestIndex = 0;
	for( i=StartIndex; i<=EndIndex; i++ ){
		DataSet[i] = Destination[DestIndex++];
	}

	free( Destination );
}

void MergeSort( int DataSet[], int StartIndex, int EndIndex ){
	int MiddleIndex;

	if( EndIndex - StartIndex < 1 ){
		return;
	}

	MiddleIndex = ( StartIndex + EndIndex ) / 2 ;

	MergeSort( DataSet, StartIndex, MiddleIndex );
	MergeSort( DataSet, MiddleIndex + 1, EndIndex );

	Merge( DataSet, StartIndex, MiddleIndex, EndIndex );
}

int main( void ){

	int DataSet[] = {0,2,3,4,5,1,6,3,5,3,2,4,6,7,8,4,3,2,1,4,5,6,8,4,3,7,3,4,5,3,2};
	int Length = sizeof DataSet / sizeof DataSet[0];

	BubbleSort( DataSet, Length );
	for( int i=0; i<Length; i++ ){
		printf( "%d ", DataSet[i] );
	}
	printf( "\n" );

	int DataSet2[] = {0,2,3,4,5,1,6,3,5,3,2,4,6,7,8,4,3,2,1,4,5,6,8,4,3,7,3,4,5,3,2};
	Length = sizeof DataSet2 / sizeof DataSet2[0];

	InsertionSort( DataSet2, Length );
	for( int i=0; i<Length; i++ ){
		printf( "%d ", DataSet2[i] );
	}
	printf( "\n" );

	int DataSet3[] = {0,2,3,4,5,1,6,3,5,3,2,4,6,7,8,4,3,2,1,4,5,6,8,4,3,7,3,4,5,3,2};
	Length = sizeof DataSet3 / sizeof DataSet3[0];

	QuickSort( DataSet3, 0, Length-1 );
	for( int i=0; i<Length; i++ ){
		printf( "%d ", DataSet3[i] );
	}
	printf( "\n" );

	int DataSet4[] = {0,2,3,4,5,1,6,3,5,3,2,4,6,7,8,4,3,2,1,4,5,6,8,4,3,7,3,4,5,3,2};
	Length = sizeof DataSet4 / sizeof DataSet4[0];

	MergeSort( DataSet4, 0, Length-1 );
	for( int i=0; i<Length; i++ ){
		printf( "%d ", DataSet4[i] );
	}
	printf( "\n" );


	return 0;
}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void Swap( int* A, int* B ){
//	int Temp = *A;
//	*A = *B;
//	*B = Temp;
//}
//
//int BubbleSort( int DataSet[], int Length ){
//	for( int i=0; i<Length-1; i++ ){
//		for( int j=0; j<Length-(i+1); j++ ){
//			if( DataSet[j] > DataSet[j+1] ){
//				Swap( &DataSet[j], &DataSet[j+1] );
//			}
//		}
//	}
//}
//
//int InsertionSort( int DataSet[], int Length ){
//	int Value = 0;
//
//	for( int i=1; i<Length; i++ ){
//		if( DataSet[i-1] < DataSet[i] ){
//			continue;
//		}
//
//		Value = DataSet[i];
//
//		for( int j=0; j<i; j++ ){
//			if( DataSet[j] > Value ){
//				memmove( &DataSet[j+1], &DataSet[j], sizeof( DataSet[0] ) * (i-j) );
//				DataSet[j] = Value;
//				break;
//			}
//		}
//	}
//}
//
//int Partition( int DataSet[], int Left, int Right ){
//	int Last = Right;
//	int Pivot = DataSet[Last];
//
//	while( Left <= Right ){
//		while( DataSet[Left] <= Pivot && Left <= Right ){
//			++Left;
//		}
//		while( DataSet[Right] > Pivot && Left < Right ){
//			--Right;
//		}
//
//		if( Left < Right ){
//			Swap( &DataSet[Left], &DataSet[Right] );
//		} else{
//			break;
//		}
//	}
//
//	Swap( &DataSet[Left], &DataSet[Last] );
//
//	return Left;
//}
//
//void QuickSort( int DataSet[], int Left, int Right ){
//	if( Left < Right ){
//		int Index = Partition( DataSet, Left, Right );
//
//		QuickSort( DataSet, Left, Index - 1 );
//		QuickSort( DataSet, Index + 1, Right );
//	}
//}
//
//int main( void ){
//	int DataSet[] = {1,2,3,5,6,7,9,8,7,6,4,0,8,7,6,1,2,0,3,8,7,4,5,1,0,2,7,6,3,5,9,7,4,6,5,2,1,8,0,7,2,6,3,0,8,1,7,2,4,9,7,6,5,1,2,8,6,3,5,1,4,8,2,5,6,3,4,1,9,7,2,6,3,5,1,9,2,7,5,1,1,9,8,2,7,3,6,4};
//	int Length = sizeof DataSet / sizeof DataSet[0];
//
//	QuickSort( DataSet, 0, Length-1 );
//
//	for( int i=0; i<Length; i++ ){
//		printf( "%d ", DataSet[i] );
//	}
//
//	return 0;
//}

