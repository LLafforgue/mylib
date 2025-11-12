/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:59:41 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/12 17:17:24 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*temp;

	temp = format;
	while (*temp && *temp != '%')
		temp++;
	if (*format && (format) == temp - format)
		write(1, format, ft_strlen(format));
	va_start(args, format);
}
