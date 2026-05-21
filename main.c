#include "push_swap.h"

int main()
{
    t_list  *node;
    char    *ptr;

    ptr = "test";
    node = ft_lstnew(ptr);

    ft_printf("The content in node is --> %s\n", node->content);
    
}