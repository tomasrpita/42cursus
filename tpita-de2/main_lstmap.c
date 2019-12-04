#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#​include "libft.h"

typedef struct        s_list
{
    void            *content;
    struct s_list    *next;
} t_list;
​
void    ft_print_result(t_list *elem)
{
    int        len;
​
    len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, ((char *)elem->content), len);
    write(1, "\n", 1);
}
​
t_list    *ft_lstnewone(void const *content)
{
    t_list    *elem;
​
    elem = (t_list *)malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    if (!content)
    {
        elem->content = NULL;
    }
    else
    {
        if (!(elem->content = malloc(sizeof(*(elem->content)) * sizeof(elem->content))))
            return (NULL);
        elem->content = memcpy(elem->content, content, sizeof(elem->content));
    }
    elem->next = NULL;
    return (elem);
}
​
void    *ft_map(void *ct)
{
    int i;
    void    *c;
    char    *pouet;
​
    if (!(c = malloc(sizeof(*(c)) * sizeof(c))))
        return (NULL);
    c = memcpy(c, ct, sizeof(c));
    i = -1;
    pouet = (char *)c;
    while (pouet[++i])
        if (pouet[i] == 'o')
            pouet[i] = 'a';
    return (c);
}
​
void    ft_del(void *content)
{
    free(content);
}
​
int    ft_lstsize(t_list *lst)
{
    int    i;
​
    i = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}
​
t_list    *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (lst);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}
​
void    ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *p2;
​
    if (*alst == NULL)
        *alst = new;
    else
    {
        p2 = ft_lstlast(*alst);
        p2->next = new;
    }
}
​
void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst != NULL)
    {
        if (lst->content != NULL)
            del(lst->content);
        free(lst);
        lst = NULL;
    }
}
​
void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list    *temp;
​
    if (*lst != NULL)
    {
        while (*lst != NULL)
        {
            temp = (*lst)->next;
            ft_lstdelone(*lst, del);
            *lst = temp;
        }
    }
}
​
t_list    *ft_lstnew(void *content)
{
    t_list *new;
​
    if (!(new = malloc(sizeof(t_list))))
        return (NULL);
    if (content != NULL)
        new->content = content;
    else
        new->content = NULL;
    new->next = NULL;
    return (new);
}
​
t_list    *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list		**temp;
    t_list		*ret;
    int        i;
    int        j;
​
    temp = &lst;
    i = ft_lstsize(lst);
    if ((*temp) != NULL)
    {
		ret = NULL;
        while ((*temp) != NULL)
        {
            ft_lstadd_back(&ret, ft_lstnew(f((*temp)->content)));
            temp = &(*temp)->next;
        }
        j = ft_lstsize(ret);
        if (j == i)
            return (ret);
        else
            ft_lstclear(&ret, del);
    }
    return (lst);
}
​
int main(void)
{
    t_list        *elem;
    t_list        *elem2;
    t_list        *elem3;
    t_list        *elem4;
    t_list        *list;
    char        str [] = "lorem";
    char        str2 [] = "ipsum";
    char        str3 [] = "dalar";
    char        str4 [] = "sit";
​
    elem = ft_lstnewone(str);
    elem2 = ft_lstnewone(str2);
    elem3 = ft_lstnewone(str3);
    elem4 = ft_lstnewone(str4);
​
    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
​
    if (!(list = ft_lstmap(elem, &ft_map, &ft_del)))
        return (0);
    if (list == elem)
        write(1, "A new list is not returned\n", 27);
    int i;
    i = 0;
    ft_print_result(list);
    while (list->next)
    {
        list = list->next;
        ft_print_result(list);
        i++;
    }
    return (0);
}