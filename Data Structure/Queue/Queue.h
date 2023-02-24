#ifndef _QUEUE_H_
#define _QUEUE_H_
/*-------------- File Guard ------------------*/
/*Configuration*/
#define storage_type u8
#define queue_size 5
/*Type Defs*/
typedef enum{false,true}logic;
typedef struct queue_type {u8 front;storage_type elements[queue_size+1];u8 rear;}queue_type;
/*Global Variabed*/
queue_type my_queue;
/*Functins To Use*/
void queue_init(void);
u8 print_queue(void);
u8 queue_full(void);
u8 enqueue(storage_type *data);
storage_type dequeue(void);
/*-------------- File Guard ------------------*/
#endif