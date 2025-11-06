
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:51:30 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/04 16:51:33 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	if (nmemb == __SIZE_MAX__ || size == __SIZE_MAX__)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
