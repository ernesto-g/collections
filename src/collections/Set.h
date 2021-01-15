/*
 * Set.h
 *
 *  Created on: Jan 15, 2021
 *      Author: ernesto
 */

#ifndef COLLECTIONS_SET_H_
#define COLLECTIONS_SET_H_

#include "LinkedList.h"

struct S_Set
{
	LinkedList* list;
};

typedef struct S_Set Set;


Set* set_new(void);
int set_add(Set* this, void* pValue);
int set_clear(Set* this);
int set_contains(Set* this, void* pValue);
int set_isEmpty(Set* this);
int set_remove(Set* this, void* pValue);
int set_size(Set* this);
LinkedList* set_getValues(Set* this);


#endif /* COLLECTIONS_SET_H_ */
