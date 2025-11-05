/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:31:55 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/03 13:50:08 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char *str)
{
	if (*str == '\0')
		return (1);
	else
	{
		if (*str >= '0' && *str <= '9')
		{
			if (*(str + 1))
				return (ft_isdigit(str + 1));
			else
				return (1);
		}
		else
			return (0);
	}
}
