/*
    Copyright (C) <2021>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
*/
#include "LinkedList.h"

#ifndef DICT_H_
#define DICT_H_

struct sElement {
    struct sElement *next;
    char* key;
    void* value;
};

typedef struct sElement DictElement;

typedef struct{
    int size;           /* size of the pointer table */
    int count;              /* number of elements stored */
    DictElement** table;
}Dictionary;

#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MULTIPLIER (97)

/* create a new empty dictionary, if the size value is 0, the default value will be used*/
Dictionary* dict_new(int size);

/* destroy a dictionary */
int dict_delete(Dictionary*);

/* insert a new key-value pair into an existing dictionary */
int dict_insert(Dictionary*, char *key, void* value);

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
void* dict_get(Dictionary*, char*key);

/* delete the most recently inserted record with the given key */
/* if there is no such record, has no effect */
void dict_remove(Dictionary*, char *key);

LinkedList* dict_getKeys(Dictionary* this);

LinkedList* dict_getValues(Dictionary* this);

LinkedList* dict_getUniqueValues(Dictionary* this);
#endif
