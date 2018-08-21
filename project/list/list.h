#ifndef _LIST_H
#define _LIST_H


#define list_for_each_entry(pos, list, node)					\
	for (node = list?(list)->head:NULL, pos = node?node->data:NULL;		\
	     pos; 								\
	     node = node->next, pos = node?node->data:NULL)


struct node
{
    struct node *prev;
    struct node *next;

    void * data;
};

typedef struct list
{
    struct node *head;
	struct node *tail;
	int		nodes;
} list_t;

list_t * list_create();

int list_append(list_t *l, void *data);
void * list_node_remove(list_t *l, struct node *rec);
void list_remove(list_t *l, void *data);
void * list_find(list_t *l, void *key, int (*match)(void *elem, void *key));
void list_destory(list_t *l);
void list_reset(list_t *l);
void * list_get_head(struct list *l);
void * list_get_tail(struct list *l);
void * list_get_data(struct list *l, const int pos/*starting from 0*/);
int list_size(list_t *l);

#endif //_list_t_H
