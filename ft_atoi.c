/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:04:28 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/01 13:30:15 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					sign;
	unsigned long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > __LONG_LONG_MAX__ && sign == -1)
			return (0);
		else if (res > __LONG_LONG_MAX__)
			return (-1);
		res *= 10;
		res += (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
int main(int argc, char *argv[]){
	(void)argc;
	printf("%d\n", atoi(argv[1]));
	return 0;
}*/