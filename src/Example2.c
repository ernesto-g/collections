#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collections/Dictionary.h"
#include "collections/LinkedList.h"
#include "collections/Set.h"

#include "Examples.h"

void printSet(Set* s);


void example2(void)
{
	printf("\n=================== Ejemplo SET =======================\n\n");

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
	ll_deleteLinkedList(values);
}


