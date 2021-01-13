#include <stdio.h>
#include <string.h>
#include "dict.h"



void main(void)
{
    printf("Prueba diccionario\n");

    Dict d;
    char buf[512];
    char buf2[512];
    int i;

    d = DictCreate();
	
    for(i = 0; i < 10; i++) 
    {
    	sprintf(buf,"key%d",i);
    	DictInsert(d, buf, (void*)(i+0x8000));
    }
    for(i = 0; i < 10; i++) 
    {
    	sprintf(buf,"key%d",i);
        printf("%x\n",(int)DictSearch(d, buf));
    }

    DictDelete(d, "key5");

    for(i = 0; i < 10; i++) 
    {
    	sprintf(buf,"key%d",i);
        printf("%x\n",(int)DictSearch(d, buf));
    }

    DictDestroy(d); 



}
