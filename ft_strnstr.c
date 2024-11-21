/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:11:08 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/01 11:24:44 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		pos;

	if (!ft_strlen(little))
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			pos = i;
			while (little[j] != '\0' && big[i] == little[j] && i < len)
			{
				j++;
				i++;
			}
			if (little[j] == '\0')
				return ((char *)&big[pos]);
		}
		else
			i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(){
	char a[] = "hola";
	char b[] = "ol";
	char *c = ft_strstr(a, b);
	printf("%s\n", c);
}*/