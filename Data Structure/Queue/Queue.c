#include <stdio.h>
#include <Standard_Types.h>
#include "./Queue.h"

int main(void)
{
     queue_init();
     u8 x=10,y=20,z=11,m=14;
     enqueue(&x);
     enqueue(&y);
     enqueue(&z);
     enqueue(&m);
     dequeue();
     dequeue();
     printf("%d",print_queue());
     return 0;
}
/*--------------------------- Print Queue ---------------------------*/
u8 print_queue(void)
{
     u8 flag=my_queue.rear==my_queue.front?false:true;
     if(flag)
     {
          for(u8 i=my_queue.front;i<my_queue.rear;i++)
          {
               printf("[%d] = %d\n",i,my_queue.elements[i]);
          }
     }
     return flag;
}
/*--------------------------- Enqueue ---------------------------*/
u8 enqueue(storage_type *data)
{
     u8 flag=!queue_full();
     if(flag)
     {
          my_queue.elements[my_queue.rear]=*data;
          my_queue.rear++;
     }
     return flag;
}
/*--------------------------- Dequeue ---------------------------*/
storage_type dequeue(void)
{
     u8 flag=(my_queue.front==my_queue.rear)?false:true;
     if(flag)
     {
          flag=my_queue.elements[my_queue.front];
          my_queue.front++;
     }
     return flag;
}
/*--------------------------- Init ---------------------------*/
void queue_init(void)
{
     my_queue.front=false;
     my_queue.rear=false;
}
/*--------------------------- Is Full ---------------------------*/
u8 queue_full(void)
{
     return ((my_queue.rear-my_queue.front)==queue_size)?true:false;
}
