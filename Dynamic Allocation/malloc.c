#include <stdio.h>
#include <stdlib.h>
#include <Standard_Types.h>
void *malloc(size_t size);

/*MALLOC=garbage*/
void main(void)
{
     u8 *ptr=malloc(5*sizeof(u8));
     ptr[0]=1;
     printf("%d",ptr[0]);
}

