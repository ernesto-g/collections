/*
 * Set.c
 *
 *  Created on: Jan 15, 2021
 *      Author: ernesto
 */
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "Set.h"

/** \brief Crea un Set en memoria de manera dinamica
 *
 * \param void
 * \return Dictionary* Retorna el puntero al set o NULL en caso de error
 *
 */
Set* set_new(void)
{
	Set* this;

	this = (Set*)malloc(sizeof(Set));
	if(this!=NULL)
	{
		this->list = ll_newLinkedList();
		if(this->list==NULL)
		{
			free(this);
			this=NULL;
		}
	}
	return this;
}

/** \brief  Agrega un elemento al set
 * \param this Set* Puntero al set
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero al set es NULL
 *                      ( 0) Si funciono correctamente
 *						( 1) Si pElement ya existia en el set
 */
int set_add(Set* this, void* pElement)
{
	int retorno=-1;

	if(this!=NULL)
	{
		if(ll_contains(this->list,pElement)==0)
		{
			// Element does not exist in set
			ll_add(this->list,pElement);
			retorno=0;
		}
		else
		{
			// Element is already in set
			retorno=1;
		}
	}
	return retorno;
}

/** \brief  Limpia el set, es decir que de a este sin elementos
 * \param this Set* Puntero al set
 * \return int Retorna  (-1) Error: si el puntero al set es NULL
 *                      ( 0) Si funciono correctamente
 */
int set_clear(Set* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		ll_clear(this->list);
		retorno=0;
	}
	return retorno;
}

/** \brief  Verifica si un elemento esta o no contenido en el set
* \param this Set* Puntero al set
* \param pElement void* Puntero al elemento a ser verificado
* \return int Retorna  (-1) Error: si el puntero al set es NULL
*                      ( 0) Si el elemento no forma parte del set
*                      ( 1) Si el elemento forma parte del set
*/
int set_contains(Set* this, void* pValue)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno= ll_contains(this->list,pValue);
	}
	return retorno;
}

/** \brief  Verifica si el set se encuentra vacio
* \param this Set* Puntero al set
* \return int Retorna  (-1) Error: si el puntero al set es NULL
*                      ( 0) Si el set contiene elementos
*                      ( 1) Si el set NO contiene elementos
*/
int set_isEmpty(Set* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno = ll_isEmpty(this->list);
	}
	return retorno;
}

/** \brief  Quita un elemento del set
* \param this Set* Puntero al set
* \param pElement void* Puntero al elemento a ser removido
* \return int Retorna  (-1) Error: si el puntero al set es NULL
* 					   ( 0) Si el elemento forma parte del set y fue removido
*                      ( 1) Si el elemento no forma parte del set
*/
int set_remove(Set* this, void* pValue)
{
	int retorno=-1;
	int index;

	if(this!=NULL)
	{
		index = ll_indexOf(this->list,pValue);
		if(index>=0)
		{
			retorno = ll_remove(this->list,index);
		}
		else
			retorno = 1;// Element was not in set
	}
	return retorno;
}

/** \brief  Retorna la cantidad de elementos que forman parte del set
* \param this Set* Puntero al set
* \return int Retorna  (-1) Error: si el puntero al set es NULL
*                      ( n) Cantidad de elementos contenidos por el set
*/
int set_size(Set* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno = ll_len(this->list);
	}
	return retorno;
}

/** \brief  Retorna una lista (inkedList) conformada por los elementos del set
* \param this Set* Puntero al set
* \return int Retorna  (NULL) Error: si el puntero al set es NULL
*                      ( n) Lista conformada por los elementos del set
*/
LinkedList* set_getValues(Set* this)
{
	LinkedList* retList=NULL;

	if(this!=NULL)
	{
		retList = ll_clone(this->list);
	}
	return retList;
}
