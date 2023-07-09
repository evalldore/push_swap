/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:01:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/09 19:14:11 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_stack_sorted(t_list	*list)
{
	int	*num[2];

	if (!list)
		return (false);
	while (list)
	{
		num[0] = list->content;
		if (list->next)
		{
			num[1] = list->next->content;
			if (*num[1] < *num[0])
				return (false);
		}
		list = list->next;
	}
	return (true);
}

static bool	is_sorted(t_pushswap *ps)
{
	if (ft_lstsize(ps->b) > 0)
		return (false);
	return (is_stack_sorted(ps->a));
}

/*static void	set_top(t_pushswap *ps, size_t num)
{
	size_t	pos;
	t_list	*shortest;
	t_list	*sorted;
	t_list	*temp;

	sorted = ps->c;
	shortest = find_shortest(sorted, ps->a, num / 4);
	pos = get_pos(ps->a, shortest);
	if (!shortest)
		return ;
	while (ps->a != shortest)
	{
		if ((ft_lstsize(ps->a) / 2) > pos)
			ra(ps);
		else
			rra(ps);
	}
	while (sorted)
	{
		if (sorted->next && (sorted->next->content == shortest->content))
		{
			temp = sorted->next;
			sorted->next = temp->next;
			free(temp);
			break;
		}
		sorted = sorted->next;
	}
}*/

static t_list *get_target(t_list *sorted, size_t index)
{
	index = index;
	while (sorted && index > 0)
	{
		if (!sorted->next)
			break;
		index--;
		sorted = sorted->next;
	}
	return (sorted);
}

static bool is_target_done(t_list *stack, t_list *target)
{
	while(stack)
	{
		if (*(int *)stack->content <= *(int *)target->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort(t_pushswap *ps, size_t num)
{
	size_t	quarter;
	t_list	*target;

	if (is_sorted(ps))
		return ;
	quarter = num / 4;
	target = get_target(ps->c, quarter);
	while (ps->a)
	{
		while (ps->a && !is_target_done(ps->a, target))
		{
			if (*(int *)ps->a->content <= *(int *)target->content)
				pb(ps);
			else
				ra(ps);
		}
		target = get_target(target, quarter);
	}
	while (ps->b)
		pa(ps);
}
