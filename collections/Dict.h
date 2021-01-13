/*
https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
*/

#ifndef DICT_H_
#define DICT_H_

typedef struct dict Dict;

/* create a new empty dictionary */
Dict* dict_newDict(void);

/* destroy a dictionary */
void dict_deleteDict(Dict*);

/* insert a new key-value pair into an existing dictionary */
void dict_insert(Dict*, const char *key, void* value);

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
void* dict_get(Dict*, const char*key);

/* delete the most recently inserted record with the given key */
/* if there is no such record, has no effect */
void dict_remove(Dict*, const char *key);

#endif
