/*------------------------------- INCLUDE -------------------------------*/
#include "./Sort.h"
/*---------------------------- Insertion Sort ---------------------------*/
void Sort_VidInsertion_Sort(u8 *Ptr_u8Array,u8 Copy_u8Size)//do not work
{
     u8 temp,prev;
     for(u8 Local_u8Current=ONE ; Local_u8Current<Copy_u8Size ; Local_u8Current++)
     {
          temp=Ptr_u8Array[Local_u8Current];
          prev=Local_u8Current-ONE;
          while(prev>=ZERO && Ptr_u8Array[prev]>temp)
          {
               Ptr_u8Array[prev+ONE]=Ptr_u8Array[prev];
               prev--;
          }
          Ptr_u8Array[prev+ONE]=temp;
     }
}
/*---------------------------- Selection Sort ---------------------------*/
void Sort_VidSelection_Sort(u8 *Ptr_u8Array,u8 Copy_u8Size,u8 Copy_u8Mode)
{
     switch (Copy_u8Mode)
     {
          case Ascending:
               for(u8 Local_u8Current=0 ; Local_u8Current<(Copy_u8Size-1) ; Local_u8Current++)
               {
                    for(u8 Local_u8Counter=Local_u8Current ; Local_u8Counter<Copy_u8Size ; Local_u8Counter++)
                    {
                         if(Ptr_u8Array[Local_u8Current]>Ptr_u8Array[Local_u8Counter])
                         {
                              Array_VidSwap(&Ptr_u8Array[Local_u8Current],&Ptr_u8Array[Local_u8Counter]);
                         }
                    }
               }
               break;
          case Descending:
               for(u8 Local_u8Current=0 ; Local_u8Current<(Copy_u8Size-1) ; Local_u8Current++)
               {
                    for(u8 Local_u8Counter=Local_u8Current ; Local_u8Counter<Copy_u8Size ; Local_u8Counter++)
                    {
                         if(Ptr_u8Array[Local_u8Current]<Ptr_u8Array[Local_u8Counter])
                         {
                              Array_VidSwap(&Ptr_u8Array[Local_u8Current],&Ptr_u8Array[Local_u8Counter]);
                         }
                    }
               }
               break;
          default:break;
     }
}
/*---------------------------- Bubble Sort ---------------------------*/
void Sort_VidBubble_Sort(u8 *Ptr_u8Array,u8 Copy_u8Size,u8 Copy_u8Mode)
{
     u8 flag;
     switch (Copy_u8Mode)
     {
          case Ascending:
               for(u8 pass=(Copy_u8Size-ONE) ; pass>=ZERO ; pass--)
               {
                    flag=TRUE;
                    for(int iteration=ZERO;iteration<pass;iteration++)
                    {
                         if(Ptr_u8Array[iteration]>Ptr_u8Array[iteration+ONE])
                         {
                              Array_VidSwap(&Ptr_u8Array[iteration],&Ptr_u8Array[iteration+ONE]);
                              flag=FALSE;
                         }
                    }
                    if(flag) break;
               }
               break;
          case Descending:
               for(u8 pass=(Copy_u8Size-ONE) ; pass>=ZERO ; pass--)
               {
                    flag=TRUE;
                    for(int iteration=ZERO;iteration<pass;iteration++)
                    {
                         if(Ptr_u8Array[iteration]<Ptr_u8Array[iteration+ONE])
                         {
                              Array_VidSwap(&Ptr_u8Array[iteration],&Ptr_u8Array[iteration+ONE]);
                              flag=FALSE;
                         }
                    }
                    if(flag) break;
               }
               break;
          default:break;
     }
}
/*---------------------------- Swap Function ---------------------------*/
void Array_VidSwap(u8 *Ptr_u8Num_1,u8 *Ptr_u8Num_2)
{
     *Ptr_u8Num_2^=*Ptr_u8Num_1;
     *Ptr_u8Num_1^=*Ptr_u8Num_2;
     *Ptr_u8Num_2^=*Ptr_u8Num_1;
}