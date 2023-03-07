/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Queue.h
 *  Module:  Data Structure/Queue
 *  Description:  Queue Implementation
*******************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
/*---------- Include Files -------------*/
#include <stdio.h>
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
/*****************************************
----------   Configuration    ------------
*****************************************/
#define storage_type          u8
#define queue_size            5
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef struct queue_t {u8 front;storage_type elements[queue_size];u8 rear;}queue_t;
typedef enum queue_error 
{
     Queue_Full                =0,
     Queue_Ok                  =1,
     Queue_Empty               =2,
     Queue_Allocation_Error    =3,
}queue_error;
/*----------- Functins To Use ---------*/
queue_error Queue_Initialization(queue_t *my_queue);
queue_error Queue_Print(queue_t *my_queue);
queue_error Queue_Is_Empty(queue_t *my_queue);
queue_error Queue_Enqueue(queue_t *my_queue,storage_type data);
queue_error Queue_Dequeue(queue_t *my_queue,storage_type *data);
queue_error Queue_Traverse(queue_t *my_queue,void (*function)(storage_type));
static void Queue_Rearrange(queue_t *my_queue);
#endif
/********************************************************************
 *  END OF FILE: Queue.h
********************************************************************/