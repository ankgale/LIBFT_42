/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:18 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/01 17:04:51 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	i = 0;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (len > 0 && s[start + i] != '\0')
	{
		subs[i] = s[start + i];
		i++;
		len--;
	}
	while (len-- > 0)
		subs[i++] = '\0';
	subs[i] = '\0';
	return (subs);
}

/*#include <stdio.h>

int main(){
	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
	return 0;
}*/