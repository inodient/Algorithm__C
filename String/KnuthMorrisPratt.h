#ifndef KNUTHMORRISPRATT_H
#define KNUTHMORRISPRATT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 512

int KnuthMorrisPratt( char** Text, int TextSize, int Start, char* Pattern, int PatternSize );

void Preprocess( char* Pattern, int PatternSize, int* Border );

#endif
