/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Stack.h
 *  Module:  Data Structure/Stack
 *  Description:  Stack Implementation
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Stack.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
stack_t stack;
int main(void)
{
     Stack_Initialization(&stack);
     for(u8 counter=0;counter<10;counter++)Stack_Push(&stack,counter);
     Stack_Print(&stack);
     printf("%d\n",Stack_Is_Empty(&stack));
     u8 x;
     for(u8 counter=0;counter<5;counter++)Stack_Pop(&stack,&x);
     Stack_Print(&stack);
     return 0;
}
/********************************************************************
* Syntax          : stack_error Stack_Initialization(stack_t *my_stack)
* Description     : Initialize The Stack
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
stack_error Stack_Initialization(stack_t *my_stack)
{
     my_stack->top = False;
     return Stack_Ok;
}
/********************************************************************
* Syntax          : stack_error Stack_Push(stack_t *my_stack,storage_type data)
* Description     : Push Data To The Stack
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack) (Copy Of Data)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
stack_error Stack_Push(stack_t *my_stack,storage_type data)
{
     u8 flag=Stack_Full;
     if((my_stack->top)<stack_size)
     {
          my_stack->elements[my_stack->top]=data;
          my_stack->top++;
          flag=Stack_Ok;
     }
     return flag;
}
/********************************************************************
* Syntax          : stack_error Stack_Print(stack_t *my_stack)
* Description     : Print All Stack Data
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
stack_error Stack_Print(stack_t *my_stack)
{
     u8 flag=my_stack->top?Stack_Empty:Stack_Ok;
     for(u8 i=0 ; i<my_stack->top ;i++)printf("[%d] = %d\n",i,my_stack->elements[i]);
     return flag;
}
/********************************************************************
* Syntax          : stack_error Stack_Pop(stack_t *my_stack,storage_type *data)
* Description     : Pop Data From Stack 
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack) (Ptr To Data To Be Stored)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
stack_error Stack_Pop(stack_t *my_stack,storage_type *data)
{
     int flag=Stack_Empty;
     if(my_stack->top>False)
     {
          *data=my_stack->elements[(my_stack->top)-1];
          my_stack->elements[my_stack->top]=False;
          (my_stack->top)--;
          flag=Stack_Ok;
     }
     return flag;
}
/********************************************************************
* Syntax          : stack_error Stack_Pop(stack_t *my_stack,storage_type *data)
* Description     : Pop Data From Stack 
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack) (Ptr To Data To Be Stored)
* Parameters (out): None
* Return value:   : stack_error
********************************************************************/
stack_error Stack_Is_Empty(stack_t *my_stack)
{
     return my_stack->top==stack_size?Stack_Full:Stack_Ok;
}
