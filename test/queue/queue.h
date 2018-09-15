#ifndef _QUEUE_H
#define _QUEUE_H

struct node
{
	void *data;
	struct node *next;
};

struct queue
{
	struct node *front;
	struct node *rear;
	int 		size;
}queue_h;

queue_h * queue_create();

void * queue_push(queue_h *q, void *node);
void * queue_pop(queue_h *q);
void * queue_front(queue_h *q);
void * queue_size(queue_h *q);

void queue_destory(queue_h *q);


#endif //_QUEUE_H