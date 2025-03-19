/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:57:23 by dforteza          #+#    #+#             */
/*   Updated: 2024/10/01 12:57:26 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_cols(char *s, char c)
{
	int	cols;
	int	in_word;

	cols = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			cols++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (cols);
}

static void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

static char	*ft_copy_word(const char *s, int *j, char c)
{
	int		k;
	int		len;
	char	*word;

	len = 0;
	k = 0;
	while (s[*j + len] && s[*j + len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (s[*j] && s[*j] != c)
		word[k++] = s[(*j)++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		cols;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cols = ft_get_cols((char *)s, c);
	matrix = (char **)malloc((cols + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < cols)
	{
		while (s[j] == c)
			j++;
		matrix[i] = ft_copy_word(s, &j, c);
		if (matrix[i] == NULL)
		{
			ft_free_matrix(matrix);
			return (NULL);
		}
		i++;
	}
	matrix[cols] = NULL;
	return (matrix);
}
