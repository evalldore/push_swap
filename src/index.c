/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:02:36 by niceguy           #+#    #+#             */
/*   Updated: 2023/07/15 06:30:27 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_list *stack)
{
	int		*num[2];
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		num[0] = temp->content;
		if (temp->next)
		{
			num[1] = temp->next->content;
			if (*num[0] > *num[1])
			{
				temp->next->content = num[0];
				temp->content = num[1];
				temp = stack;
				continue;
			}
		}
		temp = temp->next;
	}
}

size_t	get_index(t_list	*stack, void *content)
{
	size_t	pos;

	if (!stack || !content)
		return (0);
	pos = 0;
	while (stack)
	{
		if (stack->content == content)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

t_list	*get_node(t_list *stack, size_t index)
{
	if (!stack)
		return (NULL);
	index = index;
	while (stack && index > 0)
	{
		if (!stack->next)
			break;
		index--;
		stack = stack->next;
	}
	return (stack);
}