#include <stdio.h>
#include <stdlib.h>
#include <Standard_Types.h>
//void *calloc(size_t nitems,size_t size);
//void *realloc(void *ptr,size_t size);

/*realloc=0*/
void main(void)
{
     u8 *ptr=(u8*)calloc(5,sizeof(u8));
     ptr[0]=1;
     printf("%d",ptr[0]);
     ptr=realloc(ptr,10*sizeof(u8));
     ptr[8]=5;
     printf("\n%d",ptr[8]);
}

