/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:21:32 by dforteza          #+#    #+#             */
/*   Updated: 2025/04/05 12:44:18 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_envp(char **ev)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0 && ev[i][6])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

void	custom_error(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
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
