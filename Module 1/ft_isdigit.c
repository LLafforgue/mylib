#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		del(current->content);  // Libère le contenu avec del.
		free(current);          // Libère le maillon.
	}
	*lst = NULL;  // Optionnel : met à jour le pointeur de tête.
}

