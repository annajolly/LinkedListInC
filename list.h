#ifndef CommonFile
	#define CommonFile
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define BOOLEAN int
	#define TRUE 1
	#define FALSE 0
#endif

struct NODE;
typedef struct NODE
{
	int value;
	struct NODE *previous;
	struct NODE *next;
}NODE;

void add(int num);
void prettyPrint();
BOOLEAN delete(int input);
