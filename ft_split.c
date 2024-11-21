/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:02:22 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/01 18:28:43 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**ft_free_split(char const **split, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)split[j]);
	}
	free(split);
	return (NULL);
}

static char	**affect(char const *s, char **split, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		split[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (split[j] == NULL)
			return (ft_free_split((char const **)split, j));
		while (s[i] != '\0' && s[i] != c)
			split[j][k++] = s[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		l;

	if (s == NULL)
		return (NULL);
	l = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (l + 1));
	if (split == NULL)
		return (NULL);
	return (affect(s, split, c, l));
}

/*#include <stdio.h>
int	main(void)
{
	char	**split;
	int		i;

	split = ft_split("   lorem   ipsum dolor     sit amet,
	consectetur adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	i = 0;
	while (split[i] != NULL)
	{
		printf(".%s.\n", split[i]);
		i++;
	}
	for(i = 0; split[i] != NULL; i++)
		free(split[i]);
	free(split);
	return (0);
}
*/