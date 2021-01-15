#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"
#include "LinkedList.h"

/** \brief Crea un Diccionario en memoria de manera dinamica
 *
 * \param size Define el tamnio del diccionario en el caso de ser menor  o igual a cero utiliza el valor por defecto
 * \return Dictionary* Retorna el puntero al diccionario o NULL en caso de error
 *
 */
Dictionary* dict_new(int size)
{
    Dictionary* this;
    int i;

    if(size <= 0)
    {
    	size = INITIAL_SIZE;
    }
    this = malloc(sizeof(Dictionary));
    if(this != NULL)
    {
    	this->size = size;
		this->count = 0;
		this->table = malloc(sizeof(DictElement* ) * this->size);

		for(i = 0; i < this->size; i++)
			this->table[i] = 0;
	}
    return this;
}


/** \brief Elimina un diccionario de memoria. Luego de invocar a esta funcion el puntero al diccionario
 *         no puede seguir utilizandose.
 * \param this puntero al diccionario a ser eliminado
 * \return (-1) Error: El puntero al diccionario es NULL
 *         (0) OK
 */
int dict_deleteDictionary(Dictionary* this)
{
    int i;
    DictElement* pAuxElement;
    DictElement* pAuxNextElement;

    if(this!=NULL)
    {
		for(i = 0; i < this->size; i++) {
			for(pAuxElement = this->table[i]; pAuxElement != 0; pAuxElement = pAuxNextElement)
			{
				pAuxNextElement = pAuxElement->next;
				free(pAuxElement->key);
				free(pAuxElement);
			}
		}
		free(this->table);
		free(this);
		return 0;
    }
    return -1;
}


/** \brief Calcula el hash de una clave del diccionario
 *
 * \param char Cadena de caracteres a ser utilizada como key
 * \return int Retorna  (-1) Error: si el puntero recibido es NULL
 *                      ( 0) Si funciono correctamente
 */
static unsigned long hash_function(Dictionary* this,char *key)
{
    unsigned char *usKey;
    unsigned long hashNumber;

    hashNumber = 0;
    for(usKey= (unsigned char *) key; *usKey != '\0'; usKey++) {
        hashNumber = hashNumber * MULTIPLIER + *usKey;
    }

    return hashNumber % this->size;
}

/** \brief Redimenciona un diccionario existente
 *
 * \param this Puntero al direccionario a ser redimencionado
 * \return int Retorna  (-1) Error: si el puntero del diccionario this es NULL o (si no es posible crear en memoria un diccionario auxiliar)
 *                      ( 0) Si funciono correctamente
 */
int grow(Dictionary* this)
{
    Dictionary* pNewDict;
    Dictionary pBufferDict;
    int i;
    DictElement* pAuxElement;
    int retorno = -1;

    if(this != NULL)
    {
		pNewDict = dict_new(this->size * GROWTH_FACTOR);
		if(pNewDict != NULL)
		{
			retorno = 0;
			for(i = 0; i < this->size; i++)
			{
				for(pAuxElement = this->table[i]; pAuxElement != 0; pAuxElement = pAuxElement->next)
				{
					dict_insert(pNewDict, pAuxElement->key, pAuxElement->value);
				}
			}
			pBufferDict = *this;
			*this = *pNewDict;
			*pNewDict = pBufferDict;
			dict_deleteDictionary(pNewDict);
		}

    }
    return retorno;
}


/** \brief Agrega un nuevo elemento (key-value) al diccionario
 *
 * \param this Puntero al direccionario
 * \param key Cadena de carecteres con la key.
 * \param value Valor (Puntero void*)
 *
 * \return int Retorna  (-1) Error: si el puntero del diccionario o la clave o el valor es NULL o (si no es posible crear en memoria un nuevo elemento)
 *                      (-2) Si se agoto el lugar y no es posible hacer crecer mas el diccionario
 *                      ( 0) Si funciono correctamente
 */
int dict_insert(Dictionary* this, char *key, void* value)
{
    DictElement* pElement;
    DictElement* pAuxElement;
    unsigned long hashNumber;
    int retorno = -1;
    if(this != NULL && key != NULL && value != NULL)
    {
    	if(this->count >= this->size)
    	{
    		if (grow(this) == -1)
    		{
    			return -2;
    		}
    	}

    	int flagFoundKey = 0;
    	hashNumber = hash_function(this,key) ;
		for(pAuxElement = this->table[hashNumber]; pAuxElement != 0; pAuxElement = pAuxElement->next)
		{
			if(strcmp(pAuxElement->key,strdup(key)) == 0)
			{
				flagFoundKey = 1;
				pAuxElement->value = value;
				break;
			}
		}

    	if(!flagFoundKey)
    	{
			pElement = malloc(sizeof(*pElement));
			if(pElement != NULL)
			{
				retorno = 0;
				pElement->key = strdup(key);
				pElement->value = value;


				pElement->next = this->table[hashNumber];
				this->table[hashNumber] = pElement;

				this->count++;
			}

    	}
    }
    return retorno;
}


/** \brief Devuelve el valor asociado a la key pasada como argumento
 *
 * \param this Puntero al direccionario.
 * \param key Cadena de carecteres con la key.
 * \return void* Retorna  (NULL) Error: si el puntero del diccionario this es NULL.
 *                         Puntero al valor correspondiente a la key.
 */
void* dict_get(Dictionary* this, char *key)
{
    DictElement* pElement;

    if(this!=NULL && key!=NULL)
    {
		for(pElement = this->table[hash_function(this,key)]; pElement != 0; pElement = pElement->next) {
			if(!strcmp(pElement->key, key)) {
				/* got it */
				return pElement->value;
			}
		}
    }
    return NULL;
}

/** \brief Elimina el valor correspondiente a la key pasada como argumento.
 *
 * \param this Puntero al direccionario
 * \param key Cadena de carecteres con la key.
 * \return int Retorna  (-1) Error: si el puntero del diccionario this es NULL o si no es posible crear en memoria una lista auxiliar
 *                      (0) Si funciono correctamente
 */
int dict_remove(Dictionary* this, char *key)
{
    DictElement** prev;          /* what to change when element is deleted */
    DictElement* pElement;              /* what to delete */

    if(this!=NULL && key!=NULL)
    {
		for(prev = &(this->table[hash_function(this,key)]);
			*prev != 0;
			prev = &((*prev)->next)) {
			if(!strcmp((*prev)->key, key)) {
				/* got it */
				pElement = *prev;
				*prev = pElement->next;

				free(pElement->key);
				free(pElement);

				return 0; //OK
			}
		}
    }
    return -1;
}

/** \brief Obtiene una lista con las claves presentes en el diccionario.
 *
 * \param this Puntero al direccionario
 * \return LinkediList* Retorna  (NULL) Error: si el puntero del diccionario this es NULL o si no es posible crear en memoria una lista auxiliar
 *                               (!=NULL) Si funciono correctamente
 */
LinkedList* dict_getKeys(Dictionary* this)
{
    int i;
    DictElement* pAuxElement;
    LinkedList* listaRetorno = NULL;

    if(this != NULL)
    {
    	listaRetorno = ll_newLinkedList();
    	if(listaRetorno != NULL)
    	{
			for(i = 0; i < this->size; i++)
			{
				for(pAuxElement = this->table[i]; pAuxElement != 0; pAuxElement = pAuxElement->next)
				{
					ll_add(listaRetorno,pAuxElement->key);
				}
			}
    	}
    }
    return listaRetorno;
}

/** \brief Obtiene una lista con los valores presentes en el diccionario
 *
 * \param this Puntero al direccionario
 * \return LinkediList* Retorna  (NULL) Error: si el puntero del diccionario this es NULL o si no es posible crear en memoria una lista auxiliar
 *                      	     (!=NULL) Si funciono correctamente
 */
LinkedList* dict_getValues(Dictionary* this)
{
    int i;
    DictElement* pAuxElement;
    LinkedList* listaRetorno = NULL;

    if(this != NULL)
    {
    	listaRetorno = ll_newLinkedList();
    	if(listaRetorno != NULL)
    	{
			for(i = 0; i < this->size; i++)
			{
				for(pAuxElement = this->table[i]; pAuxElement != 0; pAuxElement = pAuxElement->next)
				{
					ll_add(listaRetorno,pAuxElement->value);
				}
			}
    	}
    }
    return listaRetorno;
}

/** \brief Obtiene una lista con los valores presentes en el diccionario sin repetir
 *
 * \param this Puntero al direccionario
* \return LinkediList* Retorna  (NULL) Error: si el puntero del diccionario this es NULL o si no es posible crear en memoria una lista auxiliar
 *                              (!=NULL) Si funciono correctamente
  */
LinkedList* dict_getUniqueValues(Dictionary* this)
{
    int i;
    DictElement* pAuxElement;
    LinkedList* listaRetorno = NULL;

    if(this != NULL)
    {
    	listaRetorno = ll_newLinkedList();
    	if(listaRetorno != NULL)
    	{
			for(i = 0; i < this->size; i++)
			{
				for(pAuxElement = this->table[i]; pAuxElement != 0; pAuxElement = pAuxElement->next)
				{
					if(!ll_contains(listaRetorno,pAuxElement->value))
					{
						ll_add(listaRetorno,pAuxElement->value);
					}
				}
			}
    	}
    }
    return listaRetorno;
}
