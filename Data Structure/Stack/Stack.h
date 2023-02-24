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
----------    GLOBAL DATA     ------------
*****************************************/
/*----------- Configuration ------------*/
#define storage_type u8
#define stack_size 3
/*------------- Type Defs --------------*/
typedef struct stack_t {storage_type elements[stack_size+1];u8 top;}stack_t;
typedef enum stack_error 
{
     Stack_Full                =0,
     Stack_Ok                  =1,
     Stack_Empty               =2,
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