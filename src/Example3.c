#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collections/Dictionary.h"
#include "collections/LinkedList.h"
#include "collections/Set.h"

static void printList(LinkedList* values);


void example3(void)
{
	printf("\n=================== Ejemplo LIST =======================\n\n");

	LinkedList* lista;

	lista = ll_newLinkedList();

	ll_add(lista,"Hulk");
	ll_add(lista,"Ironman");
	ll_add(lista,"Spiderman");
	ll_add(lista,"Thor");
	ll_add(lista,"Vision");

	printList(lista);

	printf("Elimino Spiderman...\n");
	ll_remove(lista,2);

	printList(lista);

}


static void printList(LinkedList* values)
{
	int i;

	printf("List size : %d\n",ll_len(values));
	for(i=0; i < ll_len(values) ;i++)
	{
		printf("%s\n",(char*)ll_get(values,i));
	}
	printf("___________________\n");
}
