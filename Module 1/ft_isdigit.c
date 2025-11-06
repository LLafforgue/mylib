#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			current = *lst;
			*lst = (*lst)->next;
			free(current);
		}
		free(*lst);
		free(lst);
	}
}
