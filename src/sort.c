/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:01:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/09 16:54:00 by evallee-         ###   ########.fr       */
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

void	sort(t_pushswap *ps)
{
	if (is_sorted(ps))
		return ;
	while (!is_sorted(ps))
	{
		
	}
}
