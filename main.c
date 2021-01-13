#include <stdio.h>
#include <string.h>
#include "collections/Dict.h"
#include "collections/LinkedList.h"


void main(void)
{
    printf("Prueba diccionario\n");

    Dict* d;
    char buf[512];
    char buf2[512];
    int i;

    d = dict_newDict();
	
    for(i = 0; i < 10; i++) 
    {
    	sprintf(buf,"key%d",i);
    	dict_insert(d, buf, (void*)(i+0x8000));
    }
    for(i = 0; i < 10; i++) 
    {
    	sprintf(buf,"key%d",i);
        printf("%x\n",(int)dict_get(d, buf));
    }

    dict_remove(d, "key5");

    for(i = 0; i < 10; i++) 
    {
    	sprintf(buf,"key%d",i);
        printf("%x\n",(int)dict_get(d, buf));
    }

    dict_deleteDict(d); 



}
