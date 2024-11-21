/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:14:49 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/02 13:40:50 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = (*lst);
	if ((*lst))
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
	if (!(*lst))
		((*lst) = new);
}
