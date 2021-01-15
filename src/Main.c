#include <stdio.h>
#include <stdlib.h>
#include "collections/Dictionary.h"
#include "collections/LinkedList.h"



int main(void)
{
	LinkedList* listaClaves;
	LinkedList* listaValores;
	LinkedList* listaValoresUnicos;
	Dictionary* diccionario = dict_new(0);

	char valor1[] = "UNO";
	char valor2[] = "DOS";
	char valor3[] = "TRES";

	dict_insert(diccionario, "Uno",valor1);
	dict_insert(diccionario, "Uno",valor1);
	dict_insert(diccionario, "Dos",valor2);
	dict_insert(diccionario, "DosBis",valor2);
	dict_insert(diccionario, "Tres",valor3);

	listaClaves = dict_getKeys(diccionario);
	listaValores = dict_getValues(diccionario);
	listaValoresUnicos = dict_getUniqueValues(diccionario);

	for(int i=0; i < ll_len(listaClaves) ;i++)
	{
		printf("CLave: %s\n",(char*)ll_get(listaClaves,i));
	}
	for(int i=0; i < ll_len(listaValores) ;i++)
	{
		printf("Valor: %s\n",(char*)ll_get(listaValores,i));
	}
	for(int i=0; i < ll_len(listaValoresUnicos) ;i++)
	{
		printf("Valor Unico: %s\n",(char*)ll_get(listaValoresUnicos,i));
	}
	return EXIT_SUCCESS;
}
