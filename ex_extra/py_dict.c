#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char    *key;
    int     value;
}dict;

typedef struct
{
    dict    *t;
    int     max_size;
    int     size;
}tab;

void    resize(tab *arr, int new_size)
{
    arr->t = realloc(arr->t, sizeof(dict) * new_size);
    arr->max_size = new_size;
}

void    append(tab *arr, dict *tuple)
{
    if (arr->size + 1 > arr->max_size)
    {
        resize(arr, arr->max_size * 2);
    }
    (arr->t)[arr->size] = *tuple;
    arr->size++;
}

int     len(tab *arr)
{
    return (arr->size);
}

void    ft_remove(tab *arr)
{
    arr->size--;
}

dict    *pop(tab *arr)
{
    arr->size--;
    return (&(arr->t)[arr->size]);
}

void    show_tuple(dict *tuple)
{
    printf("%s: %d\n", tuple->key, tuple->value);
}

void    show_tab(tab *arr)
{
    printf("[");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%s: %d", (arr->t)[i].key, (arr->t)[i].value);
        if (i + 1 != arr->size)
            printf("  ");
    }
    printf("]\n");
}

int     get_value(tab *arr, char *key)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (!strcmp(((arr->t)[i]).key, key))
            return (((arr->t)[i]).value);
    }
    fprintf(stderr, "\t--key not found--\t");
    return (-1);
}

void    set_value(tab *arr, char *key, int new_value)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (!strcmp(((arr->t)[i]).key, key))
            ((arr->t)[i]).value = new_value;
        else if (i + 1 == arr->size)
            fprintf(stderr, "\t--key not found--\t\n");
    }
}

int     main(void)
{
    tab array = (tab){malloc(sizeof(dict) * 4), 4, 0};
    append(&array, &((dict){"a", 1}));
    append(&array, &((dict){"b", 2}));
    append(&array, &((dict){"c", 3}));
    append(&array, &((dict){"d", 4}));
    append(&array, &((dict){"e", 8}));
    append(&array, &((dict){"f", 6}));
    show_tab(&array);
    printf("%d\n", len(&array));
    show_tuple(pop(&array));
    show_tab(&array);
    printf("%d\n", len(&array));
    printf("%d\n", get_value(&array, "e"));
    set_value(&array, "e", 5);
    show_tab(&array);
    free(array.t);
}