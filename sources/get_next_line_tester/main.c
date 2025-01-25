/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:59:32 by dforteza          #+#    #+#             */
/*   Updated: 2024/10/29 00:10:30 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		i;
	int		fd;

	fd = open("emptyfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 1;
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("line %d: %s", i, s);
		free(s);
		i++;
	}
	close(fd);
	return (0);
}
