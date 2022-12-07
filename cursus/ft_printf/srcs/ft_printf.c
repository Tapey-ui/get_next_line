/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:41 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/10/25 19:23:44 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "ft_putchar.c"

int ft_printf(const char *str,...)
{
    va_list args;
    int     result;
	int		i;

	result = 0;
	i = 0;
    va_start(args, str);
    while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
    va_end(args);
    return (result);
}
