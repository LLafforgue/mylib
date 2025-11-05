#include "test.h"
#include <stdio.h>

int ft_count(t_test *list)
{
    int cnt = 0;

    while(list != NULL)
    {
        cnt++;
        list = list->next;
    }
    return (cnt);
}

int main (void)
{
    t_test *head = (void *)0;

    t_test m3 = {3, NULL};
    t_test m2 = {2, &m3};
    t_test m1 = {1, &m2};
    head = &m1;
    int test = ft_count(head);
    printf("il y a %d maillons dans le chaine.", test);
    return (0);
}