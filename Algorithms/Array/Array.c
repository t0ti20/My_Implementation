/*------------------------------- INCLUDE -------------------------------*/
#include "./Array.h" 
/*---------------------------- Array Insert ---------------------------*/
void Array_VidInsert(u8 *Ptr_u8Array,u8 Copy_u8Location,u8 Copy_u8Data)
{
     u8 Local_u8Size;
     for(Local_u8Size=ZERO;Ptr_u8Array[Local_u8Size];Local_u8Size++);
     if(Copy_u8Location<=Local_u8Size && Copy_u8Location>=ZERO)
     {
          for(u8 Local_u8Counter=Local_u8Size;Local_u8Counter>=Copy_u8Location;Local_u8Counter--)
          {
               Ptr_u8Array[Local_u8Counter+1]=Ptr_u8Array[Local_u8Counter];
          }
          Ptr_u8Array[Copy_u8Location]=Copy_u8Data;
     }
}
/*---------------------------- Array Reverse ---------------------------*/
void Array_VidReverse(u8 *Ptr_u8Array,u8 Copy_u8Size)
{
     for(u8 Local_u8Start=0,Local_u8End=Copy_u8Size-1;Local_u8Start<(Copy_u8Size/2);Local_u8Start++,Local_u8End--)
     {
          Array_VidSwap(&Ptr_u8Array[Local_u8Start],&Ptr_u8Array[Local_u8End]);
     }
}
/*---------------------------- Swap Function ---------------------------*/
void Array_VidSwap(u8 *Ptr_u8Num_1,u8 *Ptr_u8Num_2)
{
     *Ptr_u8Num_2^=*Ptr_u8Num_1;
     *Ptr_u8Num_1^=*Ptr_u8Num_2;
     *Ptr_u8Num_2^=*Ptr_u8Num_1;
}