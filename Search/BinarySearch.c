#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

ElementType BinarySearch( ElementType DataSet[], int Size, ElementType Target ){
	int Left, Right, Mid;
	
	Left = 0;
	Right = Size - 1;
	
	while( Left <= Right ){
		
		Mid = ( Left + Right ) / 2;
		
		if( DataSet[Mid] == Target ){
			return DataSet[Mid];
		} else if( DataSet[Mid] < Target ){
			Left = Mid + 1;
		} else if( DataSet[Mid] > Target ){
			Right = Mid - 1;
		}
	}
	
	return 0;
}

void BubbleSort( ElementType DataSet[], int Length ){
	int i, j;
	
	for( i=0; i<Length-1; i++ ){
		for( j=0; j<Length-(i+1); j++ ){
			if( DataSet[j] > DataSet[j+1] ){
				int Temp = DataSet[j];
				DataSet[j] = DataSet[j+1];
				DataSet[j+1] = Temp;
			}
		}
	}
}

int test_main( void ){
	int DataSet[] = {32,16,54,96,84,32,16,82,16,89,68,98,79,84,65,13,87,37,99,19,49,71};
	int Length = sizeof DataSet / sizeof DataSet[0];
	
	BubbleSort( DataSet, Length );
	
	int i;
	for( i=0; i<Length; i++ ){
		printf( "%d ", DataSet[i] );
	}
	
	printf( "\nFind : %d", BinarySearch( DataSet, Length, 71 ) );
	
	return 0;
}
