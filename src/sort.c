/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:01:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/17 02:41:26 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_stack_sorted(t_list	*list, bool greater)
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
			if (greater)
			{
				if (*num[0] < *num[1])
					return (false);
			}
			else
			{
				if (*num[0] > *num[1])
					return (false);
			}
		}
		list = list->next;
	}
	return (true);
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

static void transfer_chunk(t_pushswap *ps, t_list *target)
{
	while (ps->a && !is_target_done(ps->a, target))
	{
		if (*(int *)ps->a->content <= *(int *)target->content)
			pb(ps);
		else
			ra(ps);
	}
}

static void sort_chunk(t_pushswap *ps, size_t index)
{
	size_t	pos;
	t_list	*target;

	if (!ps->b)
		return;
	if (!ps->b->next)
	{
		pa(ps);
		return ;
	}
	target = get_node(ps->c, index);
	pos = get_index(ps->b, target->content);
	if (target->content == ps->b->content)
	{
		pa(ps);
		sort_chunk(ps, --index);
		return ;
	}
	if (pos > ft_lstsize(ps->b) / 2)
		rrb(ps);
	else
		rb(ps);
	sort_chunk(ps, index);
}

void	sort(t_pushswap *ps)
{
	size_t	quarter;
	t_list	*target;

	if (ft_lstsize(ps->b) > 0)
		return ;
	if (is_stack_sorted(ps->a, false))
		return ;
	quarter = (ps->num / DIVIDER) + 1;
	target = get_node(ps->c, quarter);
	while (ps->a)
	{
		transfer_chunk(ps, target);
		target = get_node(target, quarter);
	}
	sort_chunk(ps, ps->num - 1);
}
