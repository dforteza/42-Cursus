/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:43:06 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/23 17:05:31 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 5

void	read_file(const char *filename)
{
	int		fd;
	ssize_t	bytesRead;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return ;
	}
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	if (bytesRead == -1)
		perror("Error reading file");
	while (bytesRead > 0) 
	{
		printf("BYTES LEIDOS: %ld\n", bytesRead);
		write(1, buffer, bytesRead);
		write(1, "\n", 1);
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == -1)
			perror("Error reading file");
	}
	close(fd);
}

int main() 
{
	const char *filename = "example02.txt";
	read_file(filename);
	return 0;
}