/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:06:04 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/08/24 16:58:54 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hex(char base[])
{
	int	i;

	i = -1;
	while (++i <= 9)
	{
		base[i] = i + '0';
	}
	base[10] = 'a';
	base[11] = 'b';
	base[12] = 'c';
	base[13] = 'd';
	base[14] = 'e';
	base[15] = 'f';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	a;
	char	b;
	char	base[16];

	ft_base(base);
	i = -1;
	while (str[++i] != '\0')
	{
		if ((str[i] >= 32 && str[i] <= 126))
			write(1, &str[i], 1);
		else
		{
			a = base[str[i] / 16];
			b = base[str[i] % 16];
			write(1, "\\", 1);
			write(1, &a, 1);
			write(1, &b, 1);
		}
	}
}
