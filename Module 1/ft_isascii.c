/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:04:22 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/03 14:04:25 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(char *str)
{
	if (!*str)
		return (1);
	else
	{
		if (*str >= 0 && *str <= 127)
		{
			if (*(str + 1))
				return (ft_isascii(str + 1));
			else
				return (1);
		}
		else
			return (0);
	}
}
