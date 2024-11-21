/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:19:54 by gale              #+#    #+#             */
/*   Updated: 2024/10/01 12:06:16 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	aux[12];

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(fd, "0", 1);
	i = -1;
	while (n > 0)
	{
		aux[++i] = '0' + (n % 10);
		n /= 10;
	}
	while (i >= 0)
		write(fd, &aux[i--], 1);
}

/*
int main(int argc, char **argv){
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), 1);
}
*/