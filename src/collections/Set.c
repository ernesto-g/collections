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


Set* set_new(void)
{
	Set* pSet;

	pSet = (Set*)malloc(sizeof(Set));
	if(pSet!=NULL)
	{
		pSet->list = ll_newLinkedList();
		if(pSet->list==NULL)
		{
			free(pSet);
			pSet=NULL;
		}
	}
	return pSet;
}

int set_add(Set* this, void* pValue)
{
	int ret=-1;

	if(this!=NULL)
	{
		if(ll_contains(this->list,pValue)==0)
		{
			// Element does not exist in set
			ll_add(this->list,pValue);
			ret=0;
		}
		else
		{
			ret=1; // Element is already in set
		}
	}
	return ret;
}

int set_clear(Set* this)
{
	int ret=-1;

	if(this!=NULL)
	{
		ll_clear(this->list);

		ret=0;
	}
	return ret;
}

int set_contains(Set* this, void* pValue)
{
	int ret=-1;

	if(this!=NULL)
	{
		ret= ll_contains(this->list,pValue);
	}
	return ret;
}

int set_isEmpty(Set* this)
{
	int ret=-1;

	if(this!=NULL)
	{
		ret = ll_isEmpty(this->list);
	}
	return ret;
}

int set_remove(Set* this, void* pValue)
{
	int ret=-1;
	int index;

	if(this!=NULL)
	{
		index = ll_indexOf(this->list,pValue);
		if(index>=0)
		{
			ret = ll_remove(this->list,index);
		}
		else
			ret = 1;// Element was not in set
	}
	return ret;
}

int set_size(Set* this)
{
	int ret=-1;

	if(this!=NULL)
	{
		ret = ll_len(this->list);
	}
	return ret;
}

LinkedList* set_getValues(Set* this)
{
	LinkedList* retList=NULL;

	if(this!=NULL)
	{
		retList = ll_clone(this->list);
	}
	return retList;
}
