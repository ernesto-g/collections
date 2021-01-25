#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collections/Dictionary.h"
#include "collections/LinkedList.h"
#include "collections/Set.h"

#include "Examples.h"


void printDict(Dictionary* diccionario);

void example1(void)
{
	printf("\n=================== Ejemplo DICT =======================\n\n");

	// Prueba diccionario
	Dictionary* diccionario = dict_new(0);

	char valor1[] = "UNO";
	char valor2[] = "DOS";
	char valor3[] = "TRES";

	dict_insert(diccionario, "Uno",valor1);
	dict_insert(diccionario, "Uno",valor1);
	dict_insert(diccionario, "Dos",valor2);
	dict_insert(diccionario, "DosBis",valor2);
	dict_insert(diccionario, "Tres",valor3);

	printDict(diccionario);

	dict_remove(diccionario,"Uno");
	printf("Removi la key 'Uno'\r\n");

	printDict(diccionario);

	char* val = dict_get(diccionario,"DosBis");
	printf("\ntest1 get devolvio: %s",val);

	val = dict_get(diccionario,"Lalala");
	printf("\ntest2 get devolvio: %s",val);

}

void printDict(Dictionary* diccionario)
{
	LinkedList* listaClaves;
	LinkedList* listaValores;
	LinkedList* listaValoresUnicos;

	listaClaves = dict_getKeys(diccionario);
	listaValores = dict_getValues(diccionario);
	listaValoresUnicos = dict_getUniqueValues(diccionario);

	printf("Keys:\n");
	for(int i=0; i < ll_len(listaClaves) ;i++)
	{
		printf("'%s'\n",(char*)ll_get(listaClaves,i));
	}
	printf("Values(str):\n");
	for(int i=0; i < ll_len(listaValores) ;i++)
	{
		printf("%s\n",(char*)ll_get(listaValores,i));
	}
	printf("Unique Values(str):\n");
	for(int i=0; i < ll_len(listaValoresUnicos) ;i++)
	{
		printf("%s\n",(char*)ll_get(listaValoresUnicos,i));
	}
	printf("____________________\n");

	ll_deleteLinkedList(listaClaves);
	ll_deleteLinkedList(listaValores);
	ll_deleteLinkedList(listaValoresUnicos);
}
