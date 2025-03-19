/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:39:46 by dforteza          #+#    #+#             */
/*   Updated: 2025/03/19 10:57:34 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **ev)
{
	char	**cmd_exec;
	char	*path;

	if (!cmd || !*cmd)
	{
		custom_error("Error", "Empty command");
		exit(1);
	}
	cmd_exec = ft_split(cmd, ' ');
	path = get_cmd_path(cmd_exec[0], ev);
	if (!path)
	{
		free_split(cmd_exec);
		free(path);
		exit_error();
	}
	if (execve(path, cmd_exec, ev) == -1)
	{
		free_split(cmd_exec);
		free(path);
		exit_error();
	}
}

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

void	child(int *fd, char **av, char **ev)
{
	int	fd_inf;

	fd_inf = open(av[1], O_RDONLY);
	if (fd_inf == -1)
		exit_error();
	if (dup2(fd_inf, STDIN_FILENO) == -1)
		exit_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit_error();
	close(fd[0]);
	close(fd_inf);
	exec(av[2], ev);
}

void	parent(int *fd, char **av, char **ev)
{
	int	fd_otp;

	fd_otp = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_otp == -1)
		exit_error();
	if (dup2(fd_otp, STDOUT_FILENO) == -1)
		exit_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_error();
	close(fd[1]);
	close(fd_otp);
	exec(av[3], ev);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (!check_envp(envp))
		exit_error();
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit_error();
		pid = fork();
		if (pid == -1)
			exit_error();
		if (pid == 0)
			child(fd, argv, envp);
		waitpid(pid, NULL, 0);
		parent(fd, argv, envp);
	}
	else
	{
		custom_error("Error", "Wrong number of arguments");
		custom_error("Correct Input", "./pipex <file1> <cmd1> <cmd2> <file2>");
		exit(1);
	}
}
