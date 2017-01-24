#include "BoyerMoore.h"

int BoyerMoore( char* Text, int TextSize, int Start, char* Pattern, int PatternSize ){
  int BCT[128];
  int* Suffix = (int*)calloc( PatternSize + 1, sizeof(int) );
  int* GST = (int*)calloc( PatternSize + 1, sizeof(int) );
  int i = Start;
  int j = 0;

  int Position = -1;

  BuildBCT( Pattern, PatternSize, BCT );
  BuildGST( Pattern, PatternSize, Suffix, GST);

  while( i <= TextSize - PatternSize ){
    j = PatternSize - 1;

    while( j >= 0 && Pattern[j] == Text[i+j] ) j--;

    if( j < 0 ){
      Position = i;
      break;
    } else{
      i += Max( GST[j+i], j-BCT[ Text[i+j] ]);
    }
  }

  free( Suffix );
  free( GST );

  return Position;
}

void BuildBCT( char* Pattern, int PatternSize, int* BCT ){
  int i, j;

  for( i=0; i<128; i++ ){
    BCT[i] = -1;
  }

  for( j=0; j<PatternSize; j++ ){
    BCT[ Pattern[j] ] = j;
  }
}

void BuildGST( char* Pattern, int PatternSize, int* Suffix, int* GST ){
  int i = PatternSize;
  int j = PatternSize + 1;

  Suffix[i] = j;

  while( i > 0 ){
    while( j <= PatternSize && Pattern[i-1] != Pattern[j-1] ){
      if( GST[j] == 0 ){
        GST[j] = j-i;
      }
    }

    j = Suffix[j];
  }

  j = Suffix[0];

  for( i=0; i<=PatternSize; i++ ){
    if( GST[i] == 0 ){
      GST[i] == j;
    }

    if( i == j ){
      j = Suffix[j];
    }
  }
}

int Max( int A, int B ){
  return ( A > B )?A:B;
}




int Test_BoyerMoore( int argc, char* argv ){
  char* FilePath;
  FILE* fp;

  char Text[MAX_BUFFER];
  chaR* Pattern;
  int PatternSize = 0;
  int Line = 0;

  if( argc < 3 ){
    printf( "Usage : %s <FilePath> <Pattern>\n", argv[0] );
    return 1;
  }

  FilePath = argv[1];
  Pattern = argv[2];

  PatternSize = strlen( Pattern );

  if( (fp = fopen( FilePath, "r" )) == NULL ){
    printf( "Cannot open file : %s\n", FilePath );
    return 1;
  }

  while( fgets(Text, MAX_BUFFER, fp) != NULL ){
    int Position = BoyerMoore( Text, strlen(Text), 0, Pattern, PatternSize );

    Line++;

    if( Position >= 0 ){
      prtinf( "line : %d, column : %d : %s", Line, Position + 1, Text );
    }
  }

  fclose( fp );

  return 0;
}
