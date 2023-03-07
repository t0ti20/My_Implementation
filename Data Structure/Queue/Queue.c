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
     printf("%d\n",element);
}
int main(void)
{
     Queue_Initialization(&queue);
     for(u8 counter=0;counter<10;counter++)Queue_Enqueue(&queue,counter);
     Queue_Traverse(&queue,print);
     u8 x;
     for(u8 counter=0;counter<3;counter++)Queue_Dequeue(&queue,&x);
     Queue_Print(&queue);
     Queue_Enqueue(&queue,10);
     Queue_Enqueue(&queue,11);
     Queue_Print(&queue);
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
     for(u8 counter=my_queue->front;counter<my_queue->rear;counter++)
     {
          function(my_queue->elements[counter]);
     }
     return flag;
}
/********************************************************************
* Syntax          : queue_error Queue_Print(queue_t *my_queue)
* Description     : Print All Elements In Queue 
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Print(queue_t *my_queue)
{
     queue_error flag=Queue_Ok;
     if(my_queue->rear>my_queue->front)
     {
          for(u8 counter=my_queue->front;counter<my_queue->rear;counter++)
          {
               printf("[%d] = %d\n",counter,my_queue->elements[counter]);
          }
     }
     else flag=Queue_Empty;
     return flag;
}
/********************************************************************
* Syntax          : static void Queue_Rearrange(queue_t *my_queue)
* Description     : Rearrange Queue When Its Full And There Is Places
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : None
********************************************************************/
static void Queue_Rearrange(queue_t *my_queue)
{
     u8 counter=ZERO;
     for(u8 element=my_queue->front;element<my_queue->rear;element++,counter++)
     {
          my_queue->elements[counter]=my_queue->elements[(element)];
     }
     my_queue->rear=counter;
     my_queue->front=ZERO;
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
     if((my_queue->rear-my_queue->front)<queue_size)
     {
          if(my_queue->rear<queue_size)
          {
               my_queue->elements[my_queue->rear]=data;
               my_queue->rear++;
          }
          else
          {
               Queue_Rearrange(my_queue);
               my_queue->elements[my_queue->rear]=data;
               my_queue->rear++;
          }
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
     if(my_queue->front<my_queue->rear)
     {
          *data=my_queue->elements[my_queue->front];
          my_queue->front++;
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
     my_queue->front=ZERO;
     my_queue->rear=ZERO;
     return flag;
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
queue_error Queue_Is_Empty(queue_t *my_queue)
{
     return (my_queue->rear-my_queue->front)<queue_size?Queue_Empty:Queue_Full;
}
