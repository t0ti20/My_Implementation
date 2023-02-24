/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Linked_List.c
 *  Brief:  Handle Linked_List
 *  Description:  Logic C File Implementation Linked List
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Linked_List.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
list_t my_list;
int main(void)
{
     u8 Counter=0;
     storage_type Data;
     Linked_List_Initialization(&my_list);
     printf("==== Pleese Enter (!) To End ====\n");
     do
     {
          printf("Enter [%d] Elenent : ",Counter++);
          fflush(stdout);
          scanf(" %c",&Data);
          fflush(stdin);
          if(Data=='!')break;
          Linked_List_Append(&my_list,Data);
     }while(True);
     Linked_List_Print(&my_list);
}
/********************************************************************
* Syntax          : list_error Linked_List_Initialization(list_t *my_list)
* Description     : Initialize The List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List)
* Parameters (out): None
* Return value:   : list_error
********************************************************************/
list_error Linked_List_Initialization(list_t *my_list)
{
     my_list->head=NULL;
     my_list->size=-1;
     return List_Ok;
}
/********************************************************************
* Syntax          : list_error Linked_List_Insert(list_t *my_list,u8 node_number,storage_type data)
* Description     : Insert Node To Linked List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number),(Data)
* Parameters (out): None
* Return value:   : list_error
********************************************************************/
list_error Linked_List_Insert(list_t *my_list,u8 node_number,storage_type data)
{
     s8 flag;
     if(my_list->size>=(node_number-ONE))
     {
          node_t *new_node=(node_t*)malloc(sizeof(node_t));
          if(new_node)
          {
               node_t *temp=my_list->head;
               new_node->data=data;
               if(node_number==ZERO)
               {
                    temp=my_list->head;
                    my_list->head=new_node;
                    new_node->next_ptr=temp;
               }
               else
               {
                    for(u8 i=TWO;i<=node_number;i++) temp=temp->next_ptr;
                    new_node->next_ptr=temp->next_ptr;
                    temp->next_ptr=new_node;
               }
               my_list->size++;
               flag=List_Ok;
          }
          else
          {
               printf("- Error Getting Memory.\n");
               flag=List_Wrong_Memory;
          }
     }
     else 
     {
          printf("- Error Getting Node.\n");
          flag=List_Wrong_Size;
     }
     return flag;
}
/********************************************************************
* Syntax          : list_error Linked_List_Append(list_t *my_list,storage_type data)
* Description     : Append To The List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Data)
* Parameters (out): None
* Return value:   : list_error
********************************************************************/
list_error Linked_List_Append(list_t *my_list,storage_type data)
{
     s8 flag;
     node_t *new_node=(node_t*)malloc(sizeof(node_t));
     if(new_node)
     {
          new_node->data=data;
          new_node->next_ptr=NULL;
          if(!my_list->head)
          {
               my_list->head=new_node;
          }
          else
          {
               node_t *temp=my_list->head;
               while(temp->next_ptr!=NULL) temp=temp->next_ptr;
               temp->next_ptr=new_node;
          }
          my_list->size++;
          flag=List_Ok;
     }
     else
     {
          printf("- Error Getting Memory.\n");
          flag=List_Wrong_Memory;
     }
     return flag;
}
/********************************************************************
* Syntax          : list_error Linked_List_Print(list_t *my_list)
* Description     : Print The Content Of Linked List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List)
* Parameters (out): None
* Return value:   : list_error
********************************************************************/
list_error Linked_List_Print(list_t *my_list)
{
     s8 flag;
     if(!my_list->head)
     {
          flag=List_Empty;
          printf("- Your List Is Empty\n");
     }
     else
     {
          u8 Counter=0;
          node_t *temp=my_list->head;
          while(temp->next_ptr!=NULL)
          {
               #if storage_type == u8
               printf("-> [%d] = '%c'\n",Counter++,temp->data);
               #else
               printf("-> [%d] = '%d'\n",Counter++,temp->data);
               #endif
               temp=temp->next_ptr;
          }
          #if storage_type == u8
          printf("-> [%d] = '%c'\n",Counter++,temp->data);
          #else
          printf("-> [%d] = '%d'\n",Counter++,temp->data);
          #endif
          flag=List_Ok;
     }
     return flag;
}
/********************************************************************
* Syntax          : storage_type Linked_List_Get_Node(list_t *my_list,u8 node_number)
* Description     : Get Specific Node
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number)
* Parameters (out): None
* Return value:   : Node Data
********************************************************************/
list_error Linked_List_Get_Node(list_t *my_list,u8 node_number,storage_type *data)
{
     s8 flag;
     if(node_number>my_list->size)
     {
          printf("- Error Getting Node.\n");
          flag=List_Wrong_Size;
     }
     else
     {
          node_t *temp=my_list->head;
          while(node_number>=ONE)
          {
               temp=temp->next_ptr;
               node_number--;
          }
          *data=temp->data;
          flag=List_Ok;
     }
     return flag;
}
/********************************************************************
* Syntax          : storage_type Linked_List_Delete_Node(list_t *my_list,u8 node_number)
* Description     : Delete Specific Node
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number)
* Parameters (out): None
* Return value:   : storage_type
********************************************************************/
list_error Linked_List_Delete_Node(list_t *my_list,u8 node_number)
{
     s8 flag;
     if(node_number>my_list->size)
     {
          printf("- Error Getting Node.\n");
          flag=List_Wrong_Size;
     }
     else
     {
          node_t *current=my_list->head;
          if(node_number==ZERO)
          {
               my_list->head=current->next_ptr;
               free(current);
               my_list->size--;
          }
          else
          {
               node_t *previous=my_list->head;
               current=current->next_ptr;
               while(node_number>=TWO)
               {
                    previous=previous->next_ptr;
                    current=current->next_ptr;
                    node_number--;
               }
               previous->next_ptr=current->next_ptr;
               free(current);
               my_list->size--;
          }
          flag=List_Ok; 
     }
     return flag;
}