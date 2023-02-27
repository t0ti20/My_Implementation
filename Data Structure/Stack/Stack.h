/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Stack.h
 *  Module:  Data Structure/Stack
 *  Description:  Stack Implementation
*******************************************************************/
#ifndef _STACK_H_
#define _STACK_H_
/*---------- Include Files -------------*/
#include <stdio.h>
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
/*****************************************
----------   Configuration    ------------
*****************************************/
/*----------- Configuration ------------*/
#define memory_mode Run_Time                                          /*(Run_Time) (Pre_Processor)*/
#define storage_type f32                                              /*(u8) (u16) (u32) (s8) (...)*/
#define stack_size 20                                                 /*When Chosing (Pre_Processor) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
#define Run_Time               0
#define Pre_Processor          1
#if memory_mode == Pre_Processor
typedef struct stack_t {storage_type elements[stack_size+1];u8 top;}stack_t;
#else
void *calloc(size_t nitems,size_t size);
void *realloc(void *ptr,size_t size);
typedef struct stack_t {storage_type *elements;u8 top;}stack_t;
#endif
typedef enum stack_error 
{
     Stack_Full                =0,
     Stack_Ok                  =1,
     Stack_Empty               =2,
     Stack_Allocation_Error    =3,
}stack_error;
/*----------- Functins To Use ---------*/
stack_error Stack_Initialization(stack_t *my_stack);
stack_error Stack_Push(stack_t *my_stack,storage_type data);
stack_error Stack_Print(stack_t *my_stack);
stack_error Stack_Pop(stack_t *my_stack,storage_type *data);
stack_error Stack_Is_Empty(stack_t *my_stack);
#endif
/********************************************************************
 *  END OF FILE: Stack.h
********************************************************************/