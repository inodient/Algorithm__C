#include "BruteForce.h"

int BruteForce(char* Text, int TextSize, int Start, char* Pattern, int PatternSize) {
	int i = 0, j = 0;

	for (i = Start; i <= TextSize - PatternSize; i++) {
		for (j = 0; j < PatternSize; j++) {
			if (Text[i + j] != Pattern[j]) {
				break;
			}
		}

		if (j >= PatternSize) {
			return i;
		}
	}

	return -1;
}

int Test_BruteForce(int argc, char** argv) {
	char* FilePath;
	FILE* fp;

	char Text[MAX_BUFFER];
	char* Pattern;
	int PatternSize = 0;
	int Line = 0;

	if (argc < 3) {
		printf("Usage : %s <FilePath> <Pattern>\n", argv[0]);
		return 1;
	}

	FilePath = argv[1];
	Pattern = argv[2];

	PatternSize = strlen(Pattern);

	if ((fp = fopen(FilePath, "r")) == NULL) {
		printf("Cannot open file: %s\n", FilePath);
		return 1;
	}

	while (fgets(Text, MAX_BUFFER, fp) != NULL) {
		int Position = BruteForce(Text, strlen(Text), 0, Pattern, PatternSize);

		if (Position >= 0) {
			printf("line:%d, column:%d : %s", Line++, Position, Text);
		}
	}

	fclose(fp);

	return 0;
}

//int main(int argc, char** argv) {
//	printf( "%d\n", argc );
//
//	int i=0;
//	for( i=0; i<argc; i++ ){
//		printf( "%s\n", argv[i] );
//	}
//
//	Test_BruteForce(argc, argv);
//
//	return 0;
//}
