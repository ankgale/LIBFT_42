/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:09:21 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/01 12:34:23 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch;
	unsigned char	cc;

	ch = (unsigned char *)s;
	cc = (unsigned char)c;
	while (*ch != '\0' && n > 0)
	{
		if (*ch == cc)
			return ((void *)ch);
		ch++;
		n--;
	}
	if (cc == '\0' && n > 0)
		return ((void *)ch);
	return (NULL);
}
