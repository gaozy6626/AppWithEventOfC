#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_MAX_SIZE        4094

struct array
{
    int *array;
    int pos;
    int size;
};

struct array*
array_create(int size)
{
    if ( size > ARRAY_MAX_SIZE)
    {
        printf("%s\n", "the size is more than ARRAY_MAX_SIZE");
        return NULL;
    }

    struct array *arr;
    arr = malloc(sizeof(struct array));
    if (NULL == arr)
        return NULL;
    arr->array = calloc(size, sizeof(int));
    if (arr == NULL)
        return NULL;

    arr->size = size;
    arr->pos = 0;

    return arr;
};

bool array_append(struct array *arr, int data)
{
    if (arr->pos == arr->size)
        return false;
    arr->array[arr->pos] = data;
    arr->pos += 1;

    return true;
}

bool array_delete(struct array *arr, int pos)
{
    if (arr->pos < pos)
        return false;

    for ( ; pos<=arr->pos; pos++)
        arr->array[pos] = arr->array[pos+1];
    arr->pos--;

    return true;
}

bool arrar_find(struct array *arr, int key)
{
    int i;
    for (i=0; i<arr->pos; i++)
    {
        if (arr->array[i] == key)
            return true;
    }

    return false;
}

void debug_array(struct array *arr)
{
    if (arr == NULL)
    {
        printf("%s\n", "debug_array : pointer is null\n");
        return;
    }

    printf("debug_array...\n");
    printf("arr : pos = %d, size = %d\n", arr->pos, arr->size);
    int i;
    printf("%s\n", "debug_array data : ");
    for (i=0; i<arr->pos; i++)
        printf("%d", arr->array[i]);
    printf("\n");
}

int main(void)
{
    struct array *my_arr;
    my_arr = array_create(20);
    if (NULL == my_arr)
        return -1;
    int i;
    for (i=0; i<5; i++)
        array_append(my_arr, i);
    debug_array(my_arr);
    if (arrar_find(my_arr, 3))
        printf("%s\n", "I can find 3 in the my_arr.");
    else
        printf("%s\n", "I can't find 10 in the my_arr.");

    if (arrar_find(my_arr, 10))
        printf("I can find 10 in the my_arr.\n");
    else
        printf("I can't find 10 in the my_arr.\n");

    array_delete(my_arr, 3);
    debug_array(my_arr);
    array_delete(my_arr, 1);
    debug_array(my_arr);

    return 0;
}