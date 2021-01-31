#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "LinkedList.h"
#include "Set.h"

// Private functions
static int getRandom(int max);
//__________________



/** \brief Toma un elemento de una LinkedList de forma aleatoria y lo devuelve. De forma opcional
 * 			puede eliminar el elemento de la lista o dejarlo.
 * \param list puntero a LinkedList.
 * \param flagRemove si es 0, deja en la lista el elemento seleccionado, si es 1, lo borra de la lista.
 * \return (NULL) Error: El puntero a list es NULL
 *         Puntero a elemento tomado al azar de la lista.
 */
void* col_pickRandomFromList(LinkedList* list, int flagRemove)
{
	if(list!=NULL)
	{
		int size = ll_len(list);
		if(size>0)
		{
			int index = getRandom(size-1);
			if(flagRemove)
				return ll_pop(list,index);
			else
				return ll_get(list,index);
		}
	}
	return NULL;
}

/** \brief Toma un elemento de un Set de forma aleatoria y lo devuelve. De forma opcional
 * 			puede eliminar el elemento de la lista o dejarlo.
 * \param set puntero a Set.
 * \param flagRemove si es 0, deja en el Set el elemento seleccionado, si es 1, lo borra del Set.
 * \return (NULL) Error: El puntero al Set es NULL
 *         Puntero a elemento tomado al azar del Set.
 */
void* col_pickRandomFromSet(Set* set, int flagRemove)
{
	if(set!=NULL)
	{
		return col_pickRandomFromList(set->list,flagRemove);
	}
	return NULL;
}

/** \brief Devuelve una nueva LinkedList con los elementos mezclados de forma aleatoria.
 * \param list puntero a LinkedList.
 * \return (NULL) Error: El puntero a list es NULL
 *         Puntero a una nueva LinkedList con los elementos mezclados.
 */
LinkedList* col_shuffle(LinkedList* list)
{
	LinkedList* listOut=NULL;
	LinkedList* clonedList=NULL;
	int i;
	void* pEl;

	if(list!=NULL)
	{
		listOut = ll_newLinkedList();
		clonedList = ll_clone(list);
		int size = ll_len(clonedList);

		for(i=0; i<size; i++)
		{
			pEl = col_pickRandomFromList(clonedList,1); // Pick and remove
			ll_add(listOut,pEl);
		}
		ll_deleteLinkedList(clonedList);
	}
	return listOut;
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
