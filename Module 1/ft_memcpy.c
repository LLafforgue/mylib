/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:30:18 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/03 17:32:07 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
    unsigned char *temp;
    const unsigned char *srctp;

	i = 0;
    temp = dest;
    srctp = src;
    if (dest == NULL || src == NULL)
        return ;
	while (i < n)
	{
		temp[i] = srctp[i];
		i++;
	}
	return (dest);
}
