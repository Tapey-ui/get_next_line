/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:31:58 by nwai-kea          #+#    #+#             */
/*   Updated: 2022/11/16 19:58:46 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *s)
{
	char	*string;
	int		r;

	string = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!string)
		return (0);
	r = 1;
	while (r != 0 && !ft_strchr(s, '\n'))
	{
		r = read(fd, string, BUFFER_SIZE);
		if (r == -1)
		{
			free(string);
			return (0);
		}
		string[r] = '\0';
		s = ft_strjoin(s, string);
	}
	free(string);
	return (s);
}

char	*ft_get(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	ft_strlcpy_gnl(str, s, i + 1);
	return (str);
}

char	*ft_nextline(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (0);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_get(str[fd]);
	str[fd] = ft_nextline(str[fd]);
	return (line);
}
