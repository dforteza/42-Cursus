/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:40:19 by dforteza          #+#    #+#             */
/*   Updated: 2025/04/06 11:27:04 by dforteza         ###   ########.fr       */
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

char	*get_cmd_path(char *cmd, char **envp);
void	exit_error(void);
void	custom_error(char *s1, char *s2);
void	free_split(char **str);
int		check_envp(char **ev);

#endif
