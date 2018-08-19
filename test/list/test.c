#include <stdio.h>
#include "list.h"

static int
matchPtr(void *elem, void *key)
{
	return elem==key ? 1:0;
}

static int
matchInt(void *elem, void *key)
{
	return *(int*)elem==*(int*)key ? 1:0;
}

int main(void)
{
	list_t *l = list_create();
	int i;
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int b = 5;
	
	if (!l)
		return -1;
	
	for (i=0; i<10; i++) {
		list_append(l, &arr[i]);
	}
	
	void *t;
	
	t = list_get_data(l, 19);
	if (t)
		printf("--------get data,value is %d\n", *(int*)t);
	t = list_get_data(l, 5);
	if (t)
		printf("--------get data,value is %d\n", *(int*)t);
	
	t = list_find(l, &b, matchInt);
	if (t)
		printf("find b...\n");
	
	t = list_get_head(l);
	printf("-------head------%d\n", *(int *)(((struct node*)t)->data));
	t = list_get_tail(l);
	printf("-------tail------%d\n", *(int*)(((struct node*)t)->data));
	
	printf("-----size-----%d--------\n", list_size(l));
	
	//list_destory(l);
	//list_reset(l);
	
	list_remove(l, &arr[0]);
	list_remove(l, &arr[0]);
	list_remove(l, &arr[1]);
	list_remove(l, &arr[2]);
	list_remove(l, &arr[9]);
	list_remove(l, &arr[8]);
	list_remove(l, &arr[8]);

	for (i>9; i>=0; i--) {
		t = list_find(l, &arr[i], matchPtr);
		if (t) {
			printf("-----%d----\n", *(int *)t);
		}
	}
	t = list_find(l, &b, matchPtr);
	if (!t) {
		printf("no bbbb.\n");
	}

	return 0;
}

