/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  Macros.h
 *  Module:  Library
 *  Description:  Common Usage Macros
*******************************************************************/
#ifndef _MACROS_H_
#define _MACROS_H_
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*Logic*/
#ifndef False
#define False 0
#endif
#ifndef True
#define True 1
#endif
#ifndef Disable
#define Disable 0
#endif
#ifndef Enable
#define Enable 1
#endif
/* Magic_Numbers */
typedef enum{ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHTH,NINE,TEN}numbers_t;
/* Null */
#ifndef NULL
#define NULL   	               ((void*) 0 )                  /* NULL Pointer */
#endif
/* Bit Math */
#define Set_Bit(Reg,Bit_Num)       (Reg|=1<<Bit_Num)			/* Set Bit */
#define Clear_Bit(Reg,Bit_Num)     (Reg&=~(1<<Bit_Num))		/* Clear Bit */
#define Toggle_Bit(Reg,Bit_Num)    (Reg^=(1<<Bit_Num))		     /* Toggle Bit */
#define Get_Bit(Reg,Bit_Num)       ((Reg>>Bit_Num)&1)		     /* Get_Bit */
/* Max-Min */
#define Max(x,y)                   (x>y)?(x):(y)                 /* Max Of Two Digits */
#define Min(x,y)                   (x>y)?(y):(x)                 /* Min Of Two Digits */
#endif
/********************************************************************
 *  END OF FILE: Macros.h
********************************************************************/
