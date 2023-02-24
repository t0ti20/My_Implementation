#ifndef _SEARCH_H_
#define _SEARCH_H_
/*-------------- File Guard ------------------*/\
typedef enum{false,true}logic;
/*Include*/
#include <stdio.h>
#include <math.h>
#include <Standard_Types.h>
/*Functins To Use*/
u8 binary_search(u8 *arr,u8 length,u8 element);
u8 jumb_search(u8 *arr,u8 length,u8 element);
u8 linear_search(u8 *arr,u8 length,u8 element);
/*-------------- File Guard ------------------*/
#endif