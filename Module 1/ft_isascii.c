#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	// 1. Gestion des cas d'erreur : si la liste ou les fonctions sont NULL, on retourne NULL.
	if (!lst || !f || !del)
		return (NULL);

	new_list = NULL;
	// 2. Parcours de la liste originale.
	while (lst)
	{
		// 3. Création d'un nouvel élément avec le contenu transformé par f.
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			// 4. En cas d'échec, on libère toute la nouvelle liste avec del.
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		// 5. Ajout du nouvel élément à la fin de la nouvelle liste.
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	// 6. Retourne la nouvelle liste.
	return (new_list);
}
