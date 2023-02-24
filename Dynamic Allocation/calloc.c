#include <stdio.h>
#include <stdlib.h>
#include <Standard_Types.h>
//void *calloc(size_t nitems,size_t size);

/*CALLOC=0*/
void main(void)
{
     u8 *ptr=(u8*)calloc(5,sizeof(u8));
     ptr[0]=1;
     printf("%d",ptr[0]);
}

