/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:32:11 by gankaoua          #+#    #+#             */
/*   Updated: 2024/09/24 20:03:11 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (++i < ft_strlen(s1))
		join[i] = s1[i];
	i = -1;
	while (++i < ft_strlen(s2))
		join[i + ft_strlen(s1)] = s2[i];
	join[i + ft_strlen(s1)] = '\0';
	return (join);
}
