#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collections/Dictionary.h"
#include "collections/LinkedList.h"
#include "collections/Set.h"


void printDict(Dictionary* diccionario);
void printSet(Set* s);

int main(void)
{
	// Prueba Set
	char buffer[64];
	Set* conjunto;

	// Cambiar entre estas dos definiciones para probar comportamiento
	conjunto = set_new(NULL); // Set de punteros
	//conjunto = set_new(SET_CMP_FN(strcmp)); // Set de Strings
	//_________________________________________________________________

	// defino cadenas
	char* pVal1 = "Batman";
	char* pVal2 = "Robin";
	char* pVal3 = "Superman";
	char* pVal4 = "Acuaman";
	char pVal5[64];
	sprintf(pVal5,"%s",pVal2);// copia de texto Robin en otro address

	// Las cargo
	set_add(conjunto,pVal1);
	set_add(conjunto,pVal2);
	set_add(conjunto,pVal2);
	set_add(conjunto,pVal2);
	set_add(conjunto,pVal5);
	set_add(conjunto,pVal3);
	set_add(conjunto,pVal4);
	set_add(conjunto,pVal4);

	printSet(conjunto);

	printf("Ingrese cual borrar:");
	scanf("%s",buffer);
	set_remove(conjunto,buffer);

	printSet(conjunto);

	return 0; // Fin programa

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

	return EXIT_SUCCESS;
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


void printSet(Set* s)
{
	int i;
	LinkedList* values = set_getValues(s);

	printf("Set values(%d):\n",set_size(s));
	for(i=0; i < ll_len(values) ;i++)
	{
		printf("%s\n",(char*)ll_get(values,i));
	}
	printf("___________________\n");
}

