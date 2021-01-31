#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collections/Collections.h"
#include "collections/Dictionary.h"
#include "collections/LinkedList.h"
#include "collections/Set.h"

#include "Examples.h"

static void printSet(Set* s);
static void printList(LinkedList* values);


void example4(void)
{
	printf("\n=================== Ejemplo Funciones de Collections =======================\n\n");

	printf(">>> Ejemplo PickRandom\n");
	Set* conjunto;
	char* cadena;

	conjunto = set_new(SET_CMP_FN(strcmp)); // Set de Strings

	set_add(conjunto,"Batman");
	set_add(conjunto,"Robin");
	set_add(conjunto,"Superman");
	set_add(conjunto,"Acuaman");

	printSet(conjunto);

	cadena = (char*)col_pickRandomFromSet(conjunto,1);
	printf("Elegi:%s\n",cadena);

	cadena = (char*)col_pickRandomFromSet(conjunto,1);
	printf("Elegi:%s\n",cadena);

	cadena = (char*)col_pickRandomFromSet(conjunto,1);
	printf("Elegi:%s\n",cadena);

	cadena = (char*)col_pickRandomFromSet(conjunto,1);
	printf("Elegi:%s\n",cadena);

	cadena = (char*)col_pickRandomFromSet(conjunto,1);
	printf("Elegi:%s\n",cadena);

	printSet(conjunto);


	printf("\n>>> Ejemplo Shuffle\n");

	LinkedList* lista;
	LinkedList* listaRandom;

	lista = ll_newLinkedList();

	ll_add(lista,"Hulk");
	ll_add(lista,"Ironman");
	ll_add(lista,"Spiderman");
	ll_add(lista,"Thor");
	ll_add(lista,"Vision");

	printList(lista);

	printf("Mezclando...\n");
	listaRandom = col_shuffle(lista);

	printList(listaRandom);

	ll_deleteLinkedList(listaRandom);

}

static void printSet(Set* s)
{
	int i;
	LinkedList* values = set_getValues(s);

	printf("Set values(%d):\n",set_size(s));
	for(i=0; i < ll_len(values) ;i++)
	{
		printf("%s\n",(char*)ll_get(values,i));
	}
	printf("___________________\n");
	ll_deleteLinkedList(values);
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
