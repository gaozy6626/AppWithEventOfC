#ifndef _QUEUE_H
#define _QUEUE_H

#define MAXSIZE 10

typedef struct node 
{
    int data;
    struct node * next;
} Node;

typedef struct queue
{
    Node * front;
    Node * rear;
    int size;
} Queue;

void q_init(Queue * queue);//初始化
void q_push(Queue * queue, const int data);//入队
void q_pop(Queue * queue);//出队
bool q_empty(Queue * queue);//为空
bool q_full(Queue * queue);//为满
int q_size(Queue * queue);//队大小
int q_front(Queue * queue);//对头元素
int q_back(Queue * queue);//队尾元素
void q_destroy(Queue * queue);//销毁

#endif //_QUEUE_h