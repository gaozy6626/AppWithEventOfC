#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "lqueue.h"

static Node* make_node(const int data);//创建节点
static void destroy_node(Node * current);//销毁链表

void q_init(Queue * queue)
{
    queue->front = queue->rear = make_node(INT_MIN);//创建一个带头节点的队列,front队头指针,rear队尾指针
    queue->size = 0;
}

void q_push(Queue * queue, const int data)
{
    Node * node;
    if ( q_full(queue) )
        return;
    node = make_node(data);
    
    queue->rear->next = node;//将队尾节点的next指针指向新节点
    queue->rear = node;//队尾指针后移

    queue->size++;
}

void q_pop(Queue * queue)
{
    Node * current;
    if ( q_empty(queue) )
        return;

    current = queue->front->next;//保存出队节点，以便释放内存
    queue->front->next = current->next;//将队头指针后移
    
    queue->size--;
    destroy_node(current);
}

bool q_empty(Queue * queue)
{
    return queue->size == 0;//队中元素个数为0,队列为空，但右一个节点
}

bool q_full(Queue * queue)
{
    return queue->size == MAXSIZE;
}

int q_size(Queue * queue)
{
    return queue->size;
}

int q_front(Queue * queue)
{
    assert( !q_empty(queue) );
    return queue->front->next->data;
}

int q_back(Queue * queue)
{
    assert( !q_empty(queue) );
    return queue->rear->data;
}

void q_destroy(Queue * queue)
{
    Node * current = queue->front;//遍历队列，释放内存
    while (current != NULL)
    {
        destroy_node(current);
        current = current->next;
    }
}

static Node* make_node(const int data)
{
    Node * node = (Node *)malloc( sizeof(Node) );
    assert( node != NULL );
    node->data = data;
    node->next = NULL;
}

static void destroy_node(Node * current)
{
    assert(current != NULL);
    free(current);
}