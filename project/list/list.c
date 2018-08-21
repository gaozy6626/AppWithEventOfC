#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *
list_create()
{
    list_t *l = (list_t*)malloc(sizeof(list_t));
    if (!l) {
        printf("******list create fail!******\n");
        return NULL;
    }

    l->head = NULL;
    l->tail = NULL;
    l->nodes = 0;

    return l;
}

int
list_append(list_t *l, void *data)
{
    if (!l || !data)
        return -1;

    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (!n) {
        printf("******list append fail!******");
	return -1;
    }
    n->data = data;
    n->prev = n->next = NULL;

    if (!l->head)
        l->head = n;
    else
        l->tail->next = n;

    n->prev = l->tail;
    l->tail = n;
    l->nodes++;
	
    return 0;
}

void *
list_node_remove(list_t *l, struct node *rec)
{
	if (!l || !rec)
		return NULL;

	void *data;

	if (rec->next)
		rec->next->prev = rec->prev;
	if (rec->prev)
		rec->prev->next = rec->next;

	if (rec == l->head)
		l->head = rec->next;
	if (rec == l->tail)
		l->tail = rec->prev;

	data = rec->data;
	free(rec);
	l->nodes--;
	
	return data;
}

void
list_remove(list_t *l, void *data)
{
	if (!l || !data)
		return;
	
	void *e;
	struct node *n;
	
	list_for_each_entry(e, l, n) {
		if (e == data)
			break;
	}
	list_node_remove(l, n);
}

void *
list_find(list_t *l, void *key, int (*match)(void *elem, void *key))
{
	if (!l || !key || !match)
		return NULL;
	
	struct node *e;
	
	for (e=l->head; e; e=e->next)
		if (match(e->data, key))
			break;
	
	return e?e->data:NULL;
}

void
list_destory(list_t *l)
{
	if (l)
		free(l);
}

void
list_reset(list_t *l)
{
	if (!l)
		return;
	l->head = l->tail = NULL;
	l->nodes = 0;
}

void *
list_get_head(struct list* l)
{
	return l?l->head:NULL;
}

void *
list_get_tail(struct list* l)
{
	return l?l->tail:NULL;
}

void *
list_get_data(struct list* l, const int pos)
{
	if (!l)
		return NULL;
	
	int i;
	struct node *n;
	
	n = l->head;
	for (i=0; i<pos && n; i++)
		n = n->next;

	return n?n->data:NULL;
}


int
list_size(list_t *l)
{
	if (!l)
		return 0;
	return l->nodes;
}
