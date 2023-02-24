#ifndef _SORT_H_
#define _SORT_H_
/*-------------- File Guard ------------------*/
/*Typedef*/
typedef enum{Ascending,Descending}Sort;
/*Include*/
#include <stdio.h>
#include "Macros.h"
#include "Standard_Types.h"
/*Functins To Use*/
void Sort_VidBubble_Sort(u8 *Ptr_u8Array,u8 Copy_u8Size,u8 Copy_u8Mode);
void Sort_VidSelection_Sort(u8 *Ptr_u8Array,u8 Copy_u8Size,u8 Copy_u8Mode);
void Sort_VidInsertion_Sort(u8 *Ptr_u8Array,u8 Copy_u8Size);
void Array_VidSwap(u8 *Ptr_u8Num_1,u8 *Ptr_u8Num_2);
/*-------------- File Guard ------------------*/
#endif