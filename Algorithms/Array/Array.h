#ifndef _ARRAY_H_
#define _ARRAY_H_
/*-------------- File Guard ------------------*/
/*define*/
#define MAX_SIZE 100
/*Include*/
#include <stdio.h>
#include "Standard_Types.h"
#include "Macros.h"
/*Functins To Use*/
void Array_VidInsert(u8 *Ptr_u8Array,u8 Copy_u8Location,u8 Copy_u8Data);
void Array_VidReverse(u8 *Ptr_u8Array,u8 Copy_u8Size);
void Array_VidSwap(u8 *Ptr_u8Num_1,u8 *Ptr_u8Num_2);
/*-------------- File Guard ------------------*/
#endif
_ARRAY_H_