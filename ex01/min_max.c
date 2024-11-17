#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct res_min_max
{
    int min;
    int max;
};

typedef struct res_min_max res_min_max_t;

int get_min(res_min_max_t p)
{
    return (p.min);
}

int get_max(res_min_max_t p)
{
    return (p.max);
}

void    tab_min_max(int *tab, int l, res_min_max_t *p)
{
    if (tab != NULL)
    {   
        p -> min = INT_MAX;
        p -> max = INT_MIN;
        for (int i = 0; i < l; i++)
        {
            if (tab[i] < p-min)
                p->min = tab[i];
            if (tab[i] > p -> max)
                p -> max=tab[i];
        }
    }
}

int main(void)
{
    int tab[] = {4, 1, 7};
    res_min_max_t p;
    p = (res_min_max_t){1, 2};
    printf("%d\t%d\n", get_min(p), get_max(p));
    tab_min_max(tab, 3, &p);
    printf("%d\t%d\n", get_min(p), get_max(p));
}