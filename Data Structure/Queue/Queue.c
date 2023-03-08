/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Queue.c
 *  Module:  Data Structure/Queue
 *  Description:  Queue Implementation
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Queue.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
queue_t queue;
void print(storage_type element)
{
     printf("- %d\n",element);
}
int main(void)
{
     u8 x;
     printf("%d\n",Queue_Initialization(&queue));
     printf("%d\n",Queue_Dequeue(&queue,&x));
     printf("%d\n",Queue_Enqueue(&queue,11));
     printf("%d\n",Queue_Enqueue(&queue,12));
     printf("%d\n",Queue_Enqueue(&queue,12));
     printf("%d\n",Queue_Dequeue(&queue,&x));
     printf("%d\n",Queue_Enqueue(&queue,12));
     printf("%d\n",Queue_Enqueue(&queue,12));
     printf("%d\n",Queue_Dequeue(&queue,&x));
     printf("%d\n",Queue_Dequeue(&queue,&x));
     printf("%d\n\n",Queue_Dequeue(&queue,&x));
     Queue_Traverse(&queue,print);
     return 0;
}
/********************************************************************
* Syntax          : queue_error Queue_Traverse(queue_t *my_queue,void (*function)(storage_type))
* Description     : Traverse Function To Queue
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue) (Ptr To Function)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Traverse(queue_t *my_queue,void (*function)(storage_type))
{
     queue_error flag=Queue_Ok;
     if((my_queue->size))
     {
          for(u8 Index=my_queue->front,Counter=ZERO;Counter<my_queue->size;Counter++)
          {
               function(my_queue->elements[Index]);
               Index=(Index+1)%queue_size;
          }
     }
     else flag=Queue_Empty;
     return flag;
}
/********************************************************************
* Syntax          : queue_error Queue_Enqueue(queue_t *my_queue,storage_type data)
* Description     : Add Elements To Queue
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue) (Copy Of Data)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Enqueue(queue_t *my_queue,storage_type data)
{
     queue_error flag=Queue_Ok;
     if((my_queue->size)<queue_size)
     {
          my_queue->rear=(my_queue->rear+ONE)%queue_size;
          my_queue->elements[my_queue->rear]=data;
          my_queue->size++;
     }
     else flag=Queue_Full;
     return flag;
}
/********************************************************************
* Syntax          : queue_error Queue_Dequeue(queue_t *my_queue,storage_type *data)
* Description     : Get An Element From Queue
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue) (Ptr To Storage Data)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Dequeue(queue_t *my_queue,storage_type *data)
{
     queue_error flag=Queue_Ok;
     if(my_queue->size)
     {
          *data=my_queue->elements[my_queue->front];
          my_queue->front=(my_queue->front+ONE)%queue_size;
          my_queue->size--;
     }
     else flag=Queue_Empty;
     return flag;
}
/********************************************************************
* Syntax          : queue_error Queue_Initialization(queue_t *my_queue)
* Description     : Initialize Queue
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Initialization(queue_t *my_queue)
{
     queue_error flag=Queue_Ok;
     my_queue->size=ZERO;
     my_queue->front=ZERO;
     my_queue->rear=-ONE;
     return flag;
}
/********************************************************************
* Syntax          : queue_error Queue_Initialization(queue_t *my_queue)
* Description     : Initialize Queue
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Clear(queue_t *my_queue)
{
     return Queue_Initialization(my_queue);
}
/********************************************************************
* Syntax          : queue_error Queue_Is_Empty(queue_t *my_queue)
* Description     : Check If Queue Is Empty
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
s8 Queue_Is_Empty(queue_t *my_queue)
{
     return !(my_queue->size);
}
/********************************************************************
* Syntax          : queue_error Queue_Is_Full(queue_t *my_queue)
* Description     : Check If Queue Is Full
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
s8 Queue_Is_Full(queue_t *my_queue)
{
     return (my_queue->size==queue_size);
}
