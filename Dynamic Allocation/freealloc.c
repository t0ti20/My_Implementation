#include <stdio.h>
#include <stdlib.h>
#include <Standard_Types.h>
//void *calloc(size_t nitems,size_t size);
//void free(void *ptr);
void main(void)
{
     u8 *ptr=NULL;
     ptr=(u8*)calloc(5,sizeof(u8));
     ptr[0]=1;
     printf("%d\n",ptr[0]);
     ptr=NULL;
     //free(ptr); 
     printf("%d",ptr);
}