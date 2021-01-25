#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "LinkedList.h"
#include "Set.h"

static int getRandom(int max);


void* col_pickRandomFromList(LinkedList* list)
{
	//TODO
	return NULL;
}

void* col_pickRandomFromSet(Set* set)
{
	//TODO
	return NULL;
}

LinkedList* col_shuffle(LinkedList* list)
{
	//TODO
	return NULL;
}

static int getRandom(int max)
{
	static int initRnd=0;
	if(initRnd==0)
	{
		srand(time(NULL));
		initRnd=1;
	}

	return rand() % (max+1);
}
