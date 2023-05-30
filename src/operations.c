/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:09:34 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/29 20:37:53 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap(t_list *list)
{
	void	*temp;

	if (!list || !list->next)
		return ;
	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
}

void	push(t_list **dest_list, t_list **src_list)
{
	t_list	*temp;

	if (!*src_list)
		return ;
	temp = *src_list;
	*src_list = temp->next;
	temp->next = *dest_list;
	*dest_list = temp;
}

void	rotate(t_list	**list)
{
	t_list	*temp;

	temp = *list;
	*list = temp->next;
	temp->next = NULL;
	ft_lstadd_back(list, temp);
}

void	reverse(t_list	**list)
{
	t_list	*temp;
	t_list	*last;

	temp = *list;
	if (!temp)
		return ;
	last = NULL;
	while (temp && temp->next)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	ft_lstadd_front(list, temp);
}
