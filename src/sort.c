/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:01:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/15 06:02:49 by niceguy          ###   ########.fr       */
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

static bool	is_sorted(t_pushswap *ps)
{
	if (ft_lstsize(ps->b) > 0)
		return (false);
	return (is_stack_sorted(ps->a, false));
}


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

/*static void insert_sort(t_pushswap *ps, t_list *start)
{
	int	*num[2];

	num[0] = ps->a->content;
	num[1] = ps->b->content;
	if (ps->b->next == start)
	{
		if (*num[0] > *num[1])
		{
			rb(ps);
			pb(ps);
			rrb(ps);
		}
		else
			pb(ps);
		return ;
	}
	if (*num[0] > *num[1])
		pb(ps);
	else
	{
		rb(ps);
		insert_sort(ps, start);
		rrb(ps);
	}
}*/

static void transfer_chunk(t_pushswap *ps, t_list *target)
{
	while (ps->a && !is_target_done(ps->a, target))
	{
		if (*(int *)ps->a->content <= *(int *)target->content)
		{
			if (!ps->b)
				pb(ps);
			else
			{
				if (*(int *)ps->a->content > *(int *)ps->b->content)
					pb(ps);
				else
				{
					/*if (!ps->b->next)
					{
						pb(ps);
						rb(ps);
					}
					else
						insert_sort(ps, ps->b);*/
					pb(ps);
					sb(ps);
				}
			}
		}
		else
			ra(ps);
	}
}

static size_t	get_content_pos(t_list	*stack, void *content)
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
	target = get_target(ps->c, index);
	pos = get_content_pos(ps->b, target->content);
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

	if (is_sorted(ps))
		return ;
	quarter = ps->num / DIVIDER;
	target = get_target(ps->c, quarter);
	while (ps->a)
	{
		transfer_chunk(ps, target);
		target = get_target(target, quarter);
	}
	sort_chunk(ps, ps->num - 1);
}
