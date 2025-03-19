/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:40:19 by dforteza          #+#    #+#             */
/*   Updated: 2025/03/19 10:26:54 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>

void	child(int *fd, char **argv, char **envp);
void	parent(int *fd, char **argv, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
void	exec(char *cmd, char **envp);
void	exit_error(void);
void	custom_error(char *header, char *msg);
void	free_split(char **str);

#endif
