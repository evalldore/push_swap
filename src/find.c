/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 04:52:51 by niceguy           #+#    #+#             */
/*   Updated: 2023/07/06 14:39:22 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_smallest(t_list **var, t_list *stack)
{
	int	*num[2];
	size_t	pos;

	if (!stack)
		return (-1);
	pos = 0;
	*var = stack;
	while(stack)
	{
		num[0] = (*var)->content;
		num[1] = stack->content;
		if (*num[1] < *num[0])
		{
			*var = stack;
			pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static size_t	get_moves(t_list* stack, t_list* target)
{
	size_t	pos;
	size_t	moves;
	size_t	stack_size;

	stack_size = ft_lstsize(stack);
	pos = get_pos(stack, target);
	if (pos < (stack_size / 2))
		moves = pos;
	else
		moves = (stack_size - pos);
	return (moves);
}

static t_list	*sorted_to_stack(t_list *sorted, t_list *stack)
{
	while (stack)
	{
		if (sorted->content == stack->content)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*find_shortest(t_list *sorted, t_list *stack, size_t max)
{
	t_list	*target;
	size_t	moves[2];

	target = sorted_to_stack(sorted, stack);
	moves[0] = get_moves(stack, target);
	while(sorted && max > 0)
	{
		moves[1] = get_moves(stack, sorted_to_stack(sorted, stack));
		if (moves[1] < moves[0])
		{
			moves[0] = moves[1];
			target = sorted_to_stack(sorted, stack);
		}
		sorted = sorted->next;
		max--;
	}
	return (target);
}
