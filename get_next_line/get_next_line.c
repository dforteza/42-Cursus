/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:56:03 by dforteza          #+#    #+#             */
/*   Updated: 2025/02/25 19:30:16 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append_line(int fd, char *str)
{
	char	*buff;
	ssize_t	bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(str, '\n')))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_next_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim_line(char *str)
{
	char	*trim_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	trim_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!trim_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		trim_str[j++] = str[i++];
	trim_str[j] = '\0';
	free(str);
	return (trim_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	stash = ft_append_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_next_line(stash);
	stash = ft_trim_line(stash);
	return (line);
}
