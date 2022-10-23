/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:45:05 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/30 13:43:32 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*new       :new nodes
t_list	*new_list   :head of LList
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	if (lst)
	{
		tmp = lst;
		begin = ft_lstnew(f(tmp->content));
		if (!begin)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (!new)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, new);
			tmp = tmp->next;
		}
		return (begin);
	}
	return (NULL);
}

// #include <stdio.h>
// void	del(void *content)
// {
// 	free(content);
// }
// void	*function(void *content)
// {
// 	char	*str;
// 	int		i;
// 	i = 0;
// 	str = (char*)content;
// 	while (str[i])
// 	{
// 		str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	return (content);
// }
// t_list	*getNode(t_list *tmp, char *con)
// {
// 	char a[10] = "Furkan";
// 	tmp = (t_list *)malloc(sizeof(t_list));
// 	if (tmp == NULL)
// 		return (NULL);
// 	con = (char * )malloc(sizeof(char) * 10);
// 	int i = 0;
// 	while(a[i])
// 	{
// 		con[i] = a[i];
// 		i++;
// 	}
// 	tmp->content = (void *)con;
// 	tmp->next = NULL;
// 	return (tmp);
// }
// int main()
// {
// 	t_list	*list;
// 	t_list	*tmp;
// 	t_list	*tmp2;
// 	t_list	*head;
// 	char	*str1;
// 	char	*str2;
// 	list = (t_list *)malloc(sizeof(t_list));
// 	if(list == NULL)
// 		return (0);
// 	tmp = getNode(tmp,str1);
// 	list = tmp;
// 	head = list;
// 	int i = 0; 
// 	while(i < 1)
// 	{
// 		tmp2 = getNode(tmp2,str2);
// 		tmp->next = tmp2;
// 		i++;
// 	}
// 	while(list != NULL)
// 	{
// 		printf("%s\n",list->content);
// 		list = list->next;
// 	}
// 	head = ft_lstmap(head, function, del);
// 	while(head != NULL)
// 	{
// 		printf("%s\n",head->content);
// 		head = head->next;
// 	}
// }