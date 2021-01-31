#ifndef COLLECTIONS_COLLECTIONS_H_
#define COLLECTIONS_COLLECTIONS_H_

#include "LinkedList.h"
#include "Set.h"

void* col_pickRandomFromList(LinkedList* list, int flagRemove);
void* col_pickRandomFromSet(Set* set, int flagRemove);
LinkedList* col_shuffle(LinkedList* list);

#endif /* COLLECTIONS_COLLECTIONS_H_ */
