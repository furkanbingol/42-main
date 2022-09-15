/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:57 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/29 12:14:02 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*tmp;

	a = (*lst);
	while (a != NULL)
	{
		tmp = a->next;
		ft_lstdelone(a, del);
		a = tmp;
	}
	(*lst) = NULL;
}
