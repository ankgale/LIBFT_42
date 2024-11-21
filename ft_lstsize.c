/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:02:11 by gankaoua          #+#    #+#             */
/*   Updated: 2024/09/25 17:06:46 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		len;

	len = 0;
	aux = lst;
	while (aux != NULL)
	{
		len++;
		aux = aux->next;
	}
	return (len);
}
