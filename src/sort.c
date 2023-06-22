/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:01:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/22 04:46:27 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_stack_sorted(t_list	*list)
{
	t_num	*num[2];

	if (!list)
		return (false);
	while (list)
	{
		num[0] = list->content;
		if (list->next)
		{
			num[1] = list->next->content;
			if (num[1]->num < num[0]->num)
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

static void	find_node(t_find *res, t_list *stack)
{
	t_num	*num[2];
	size_t	pos;

	if (!stack)
		return ;
	res->found = stack;
	res->pos = 0;
	pos = 0;
	while(stack)
	{
		num[0] = res->found->content;
		num[1] = stack->content;
		if (num[1]->num < num[0]->num)
		{
			res->found = stack;
			res->pos = pos;
		}
		stack = stack->next;
		pos++;
	}
}

static void	set_top(t_pushswap *ps)
{
	t_find	res;

	res.found = NULL;
	res.pos = -1;
	find_node(&res, ps->a);
	if (!res.found)
		return ;
	while (ps->a != res.found)
	{
		if ((ft_lstsize(ps->a) / 2) > res.pos)
			ra(ps);
		else
			rra(ps);
	}
}

void	sort(t_pushswap *ps)
{
	if (is_sorted(ps))
		return ;
	while (!is_sorted(ps))
	{
		//trim(ps);
		while (ps->a)
		{
			set_top(ps);
			pb(ps);
		}
		while (ps->b)
			pa(ps);
	}
}
