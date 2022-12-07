/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:34:04 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/09/07 00:03:14 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
	len = 1;
	while (i < size)
		len = ft_strlen(strs[i++]) + ft_strlen(sep);
	string = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < size)
	{
		while (strs[i][j])
			string[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			string[k++] = sep[j++];
		j = 0;
	}
	string[k] = '\0';
	return (string);
}
