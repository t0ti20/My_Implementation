/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Linked_List.h
 *  Module:  Data Structure/Linked List
 *  Description:  Linked List Implementation
*******************************************************************/
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
/*---------- Include Files -------------*/
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
#include <stdio.h>
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*----------- Configuration ------------*/
#define storage_type u8
/*------------- Type Defs --------------*/
typedef struct node_t {struct node_t *next_ptr;storage_type data;}node_t;
typedef struct list_t {node_t *head;s16 size;}list_t;
typedef enum list_error 
{
     List_Wrong_Size          =-3,
     List_Wrong_Memory        =-2,
     List_Empty               =-1,
     List_Ok                  =1
}list_error;
/*----------- Functins To Use ---------*/
list_error Linked_List_Print(list_t *my_list);
list_error Linked_List_Initialization(list_t *my_list);
list_error Linked_List_Append(list_t *my_list,storage_type data);
list_error Linked_List_Delete_Node(list_t *my_list,u8 node_number);
list_error Linked_List_Insert(list_t *my_list,u8 node_number,storage_type data);
list_error Linked_List_Get_Node(list_t *my_list,u8 node_number,storage_type *data);
void free(void *ptr);
void *malloc(size_t size);
#endif
/********************************************************************
 *  END OF FILE: Linked_List.h
********************************************************************/