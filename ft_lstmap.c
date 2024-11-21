/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gankaoua <gankaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:31:11 by gankaoua          #+#    #+#             */
/*   Updated: 2024/09/26 18:07:14 by gankaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*auxlst;
	t_list	*auxmap;
	t_list	*aux;

	auxlst = lst;
	map = ft_lstnew(f(auxlst->content));
	if (!map)
		return (NULL);
	auxmap = map;
	auxlst = auxlst->next;
	while (auxlst != NULL)
	{
		aux = ft_lstnew(f(auxlst->content));
		if (!aux)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		auxmap->next = aux;
		auxmap = auxmap->next;
		auxlst = auxlst->next;
	}
	return (map);
}
