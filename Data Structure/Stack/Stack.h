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
#define Memory_Mode Array                                             /*(Linked_List) (Array)*/
#define storage_type u8                                               /*(u8) (u16) (u32) (s8) (...)*/
#define stack_size 5                                                  /*When Chosing (Pre_Processor) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum stack_error
{
     Stack_Full                =0,
     Stack_Ok                  =1,
     Stack_Empty               =2,
     Stack_Allocation_Error    =3,
}stack_error;
#define Array                1
#define Linked_List          2
#if Memory_Mode == Array
typedef struct stack_t {storage_type elements[stack_size+1];u8 top;}stack_t;
#else
typedef struct stack_node_t {struct stack_node_t *next_node;storage_type data;}stack_node_t;
typedef struct stack_t {stack_node_t *top;u8 size;}stack_t;
#endif
/*----------- Functins To Use ---------*/
stack_error Stack_Clear(stack_t *my_stack);
stack_error Stack_Initialization(stack_t *my_stack);
stack_error Stack_Push(stack_t *my_stack,storage_type data);
stack_error Stack_Pop(stack_t *my_stack,storage_type *data);
stack_error Stack_Traverse(stack_t *my_stack,void (*function)(storage_type));
s8 Stack_Is_Empty(stack_t *my_stack);
s8 Stack_Is_Full(stack_t *my_stack);
void *malloc(size_t size);
void free(void *ptr);
#endif
/********************************************************************
 *  END OF FILE: Stack.h
********************************************************************/