/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:37:42 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/03 13:55:05 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(char *str)
{
	if (*str == 0)
		return (1);
	else
	{
		if (*str >= 32 && *str <= 126)
		{
			if (*(str + 1))
				return (ft_isprint(str + 1));
			else
				return (1);
		}
		else
			return (0);
	}
}
