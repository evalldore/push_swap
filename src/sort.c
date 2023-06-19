/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:01:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/19 19:01:46 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_pushswap *ps)
{
	int		num[2];
	t_list	*temp;

	if (ft_lstsize(ps->b) > 0)
		return (false);
	temp = ps->a;
	while (temp)
	{
		num[0] = *(int *)temp->content;
		if (temp->next)
		{
			num[1] = *(int *)temp->next->content;
			if (num[1] < num[0])
				return (false);
		}
		temp = temp->next;
	}
	return (true);
}

void	find_node(t_find *res, t_list *stack)
{
	int		num[2];
	size_t	pos;

	if (!stack)
		return ;
	res->found = stack;
	res->pos = 0;
	pos = 0;
	while(stack)
	{
		num[0] = *(int *)res->found->content;
		num[1] = *(int *)stack->content;
		if (num[1] < num[0])
		{
			res->found = stack;
			res->pos = pos;
		}
		stack = stack->next;
		pos++;
	}
}

void	set_top(t_pushswap *ps)
{
	t_find	res;
	size_t	size;

	res.found = NULL;
	res.pos = -1;
	find_node(&res, ps->a);
	if (!res.found)
		return ;
	size = ft_lstsize(ps->a);
	while (ps->a != res.found)
	{
		if ((size / 2) > res.pos)
			ra(ps);
		else
			rra(ps);
	}
}

void	sort(t_pushswap *ps)
{
	if (is_sorted(ps))
		return ;
	set_top(ps);
	printf("%d\n", *(int *)ps->a->content);
	pb(ps);
	printf("%d\n", *(int *)ps->b->content);
	set_top(ps);
	printf("%d\n", *(int *)ps->a->content);
	pb(ps);
	printf("%d\n", *(int *)ps->b->content);
}
