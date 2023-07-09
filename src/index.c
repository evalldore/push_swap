/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:02:36 by niceguy           #+#    #+#             */
/*   Updated: 2023/07/06 14:32:01 by niceguy          ###   ########.fr       */
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

size_t	get_pos(t_list* stack, t_list* target)
{
	size_t	pos;

	pos = 0;
	while(stack)
	{
		if (stack == target)
			break;
		pos++;
		stack = stack->next;
	}
	return (pos);
}