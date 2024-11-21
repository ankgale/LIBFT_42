/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:16:04 by gale              #+#    #+#             */
/*   Updated: 2024/10/01 17:04:19 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcont(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		start;
	int		end;
	char	*trim;

	i = 0;
	while (i < ft_strlen(s1) && ft_strcont(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strcont(set, s1[i]))
		i--;
	end = i;
	if (end < start)
		trim = (char *)malloc(sizeof(char));
	else
		trim = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (start <= end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}

/*#include <stdio.h>
int main(){
	char *trim;
	trim = ft_strtrim("lorem ipsum dolor sit amet", "te");
	if (!trim){
		printf("HOLA\n");
		return 0;
	}
	printf("%s\n", trim);
	free(trim);
	return 0;
}*/
