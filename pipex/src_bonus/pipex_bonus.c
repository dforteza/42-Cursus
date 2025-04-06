/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:48:43 by dforteza          #+#    #+#             */
/*   Updated: 2025/04/05 19:31:13 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	do_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		status;

	if (pipe(pipe_fd) == -1)
		exit_error();
	pid = fork();
	if (pid == -1)
		exit_error();
	if (pid == 0)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			exit_error();
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec(cmd, env);
	}
	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(1);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit_error();
	close(pipe_fd[0]);
}

static void	init_files(int ac, char **av, int *fd, int *i)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac != 6)
		{
			custom_error("Error", "Wrong number of arguments");
			exit(1);
		}
		*i = 3;
		fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] == -1)
			exit_error();
		here_doc(av[2]);
	}
	else
	{
		*i = 2;
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] == -1)
			exit_error();
		fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] == -1)
			exit_error();
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	i;

	if (!check_envp(envp) || ac < 5)
	{
		custom_error("Error", "Wrong number of arguments");
		exit(1);
	}
	init_files(ac, av, fd, &i);
	while (i < ac - 2)
		do_pipe(av[i++], envp);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	exec(av[ac - 2], envp);
	return (0);
}
