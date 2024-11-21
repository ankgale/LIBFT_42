/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:20:43 by gale              #+#    #+#             */
/*   Updated: 2024/10/01 18:48:33 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_magnitude(int n)
{
	int	mag;

	mag = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		mag ++;
		n *= -1;
	}
	while (n > 0)
	{
		mag++;
		n /= 10;
	}
	return (mag);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(n * -1));
	return ((unsigned int)n);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	char			aux[12];
	unsigned int	nbr;
	int				i;
	int				j;

	nbr = ft_abs(n);
	itoa = (char *)malloc((ft_get_magnitude(n) + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	i = 0;
	j = 0;
	if (n < 0)
		itoa[j++] = '-';
	if (nbr == 0)
		itoa[j++] = '0';
	while (nbr > 0)
	{
		aux[i++] = '0' + (nbr % 10);
		nbr /= 10;
	}
	while (--i >= 0)
		itoa[j++] = aux[i];
	itoa[j] = '\0';
	return (itoa);
}

/*
#include <stdio.h>
int main(){
	char *itoa = ft_itoa(-2147483648LL);
	printf("%s\n", itoa);
	free(itoa);
	return 0;
}
*/