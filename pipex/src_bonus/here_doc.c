/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:36:18 by dforteza          #+#    #+#             */
/*   Updated: 2025/04/06 11:34:11 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_child(int *pipe_fd, char *lim)
{
	char	*line;
	size_t	lim_len;

	lim_len = ft_strlen(lim);
	if (lim[lim_len - 1] == '\n')
		lim[lim_len - 1] = '\0';
	close(pipe_fd[0]);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			exit(EXIT_SUCCESS);
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(char *lim)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		exit_error();
	pid = fork();
	if (pid == -1)
		exit_error();
	if (pid == 0)
		here_doc_child(pipe_fd, lim);
	close(pipe_fd[1]);
	waitpid(pid, NULL, 0);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
}
