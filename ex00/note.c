#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char            nom[30];
    unsigned int    age;
    double          note;
}student_t;

double  find_highest_score(student_t *tab, int l)
{
    int max;

    max = 0;
    for (int i = 0; i < l; i++)
    {
        if (tab[i].note > max)
            max = tab[i].note;
    }
    return (max);
}

void    show_best_student(student_t *tab, int l, double best_note)
{
    printf("The highest score was %.6lf, obtained by:\n", best_note);
    for (int i = 0; i < l; i++)
    {
        if (tab[i].note == best_note)
            printf("Name: %s, Age: %d\n", tab[i].nom, tab[i].age);
    }
}

int     main(void)
{
    student_t   tab[] = {(student_t){"Luc", 3, 15}, (student_t){"Hannah", 99, 18}};
    double      best_note;

    best_note = find_highest_score(tab, 2);
    show_best_student(tab, 2, best_note);
}