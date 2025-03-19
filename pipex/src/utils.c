/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:21:32 by dforteza          #+#    #+#             */
/*   Updated: 2025/03/19 10:26:32 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	custom_error(char *header, char *msg)
{
	ft_putstr_fd(header, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

char	*get_cmd_path(char *cmd, char **ev)
{
	int		i;
	char	**paths_arr;
	char	*try_path;
	char	*cmd_path;

	i = 0;
	while (ev[i] && ft_strncmp(ev[i], "PATH=", 5))
		i++;
	paths_arr = ft_split(ev[i] + 5, ':');
	i = -1;
	while (paths_arr[++i])
	{
		try_path = ft_strjoin(paths_arr[i], "/");
		cmd_path = ft_strjoin(try_path, cmd);
		free(try_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(paths_arr);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_split(paths_arr);
	custom_error("command not found", cmd);
	return (NULL);
}

void	exit_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
