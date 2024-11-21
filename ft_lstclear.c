/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:19:56 by gankaoua          #+#    #+#             */
/*   Updated: 2024/10/02 13:37:53 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*aux2;

	aux = (*lst);
	while (aux != NULL)
	{
		del(aux->content);
		aux2 = aux->next;
		aux->next = NULL;
		free(aux);
		aux = aux2;
	}
	*lst = NULL;
}
