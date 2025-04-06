/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:30:04 by dforteza          #+#    #+#             */
/*   Updated: 2025/04/06 11:30:12 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../gnl/get_next_line_bonus.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>

int		check_envp(char **ev);
char	*get_cmd_path(char *cmd, char **envp);
void	exit_error(void);
void	custom_error(char *header, char *msg);
void	free_split(char **str);
void	here_doc(char *lim);

#endif
