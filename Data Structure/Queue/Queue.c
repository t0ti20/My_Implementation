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
#if Memory_Mode == Array
     if((my_queue->size))
     {
          for(u8 Index=my_queue->front,Counter=ZERO;Counter<my_queue->size;Counter++)
          {
               function(my_queue->elements[Index]);
               Index=(Index+1)%queue_size;
          }
     }
     else flag=Queue_Empty;
#else
     if((my_queue->size))
     {
          for(queue_node_t *node=my_queue->front;node;node=node->next_node)
          {
               function(node->data);
          }
     }
     else flag=Queue_Empty;
#endif
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
#if Memory_Mode == Array
     if((my_queue->size)<queue_size)
     {
          my_queue->rear=(my_queue->rear+ONE)%queue_size;
          my_queue->elements[my_queue->rear]=data;
          my_queue->size++;
     }
     else flag=Queue_Full;
#else
     queue_node_t *node=(queue_node_t *)malloc(sizeof(queue_node_t));
     if(node)
     {
          node->next_node=NULL;
          node->data=data;
          if(!(my_queue->rear))
          {
               my_queue->front=node;
          }
          else
          {
               my_queue->rear->next_node=node; 
          }
          my_queue->rear=node;
          my_queue->size++;
     }
     else flag=Queue_Allocation_Error;
#endif
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
#if Memory_Mode == Array
     if(my_queue->size)
     {
          *data=my_queue->elements[my_queue->front];
          my_queue->front=(my_queue->front+ONE)%queue_size;
          my_queue->size--;
     }
     else flag=Queue_Empty;
#else
     if(my_queue->size)
     {
          queue_node_t *node=my_queue->front;
          *data=node->data;
          my_queue->front=node->next_node;
          free(node);
          if(!(my_queue->front))
          {
               my_queue->rear=NULL;
          }
          my_queue->size--;
     }
     else flag=Queue_Empty;

#endif
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
#if Memory_Mode == Array
     my_queue->size=ZERO;
     my_queue->front=ZERO;
     my_queue->rear=-ONE;
#else
     my_queue->front=NULL;
     my_queue->rear=NULL;
     my_queue->size=ZERO;
#endif
     return flag;
}
/********************************************************************
* Syntax          : queue_error Queue_Clear(queue_t *my_queue)
* Description     : Clear All Elements In Queue
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
queue_error Queue_Clear(queue_t *my_queue)
{
     #if Memory_Mode != Array
     if((my_queue->size))
     {
          for(queue_node_t *node=my_queue->front;node;node=my_queue->front)
          {
               my_queue->front=node->next_node;
               free(node);
          }
     }
     #endif
     return Queue_Initialization(my_queue);
}
/********************************************************************
* Syntax          : s8 Queue_Is_Empty(queue_t *my_queue)
* Description     : Check If Queue Is Empty
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Queue)
* Parameters (out): None
* Return value:   : s8 (True) (False)
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
* Return value:   : s8 (True) (False)
********************************************************************/
s8 Queue_Is_Full(queue_t *my_queue)
{
     #if Memory_Mode == Array
     return (my_queue->size==queue_size);
     #else
     return False;
     #endif
}
/********************************************************************
 *  END OF FILE: Queue.c
********************************************************************/