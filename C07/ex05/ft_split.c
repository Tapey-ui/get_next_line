/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:14:15 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/09/07 00:03:37 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_is_seperator(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_seperator(str[i + 1], charset) == 1
			&& ft_is_seperator(str[i], charset) == 0)
			word++;
		i++;
	}
	return (word);
}

void	ft_write_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (ft_is_seperator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_write_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_seperator(str[i + j], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_seperator(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			ft_write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ans;
	int		word;

	words = ft_count(str, charset);
	ans = (char **)malloc(sizeof(char *) * (words + 1));
	ans[words] = 0;
	ft_write_split(ans, str, charset);
	return (ans);
}
